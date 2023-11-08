#pragma once
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <unistd.h>
#include <Instructions/InstructionSet.h>
#include <common/CPUData.h>

template<typename T>
void print(T value){
    std::cout << value;
}

void printHex(uint16_t value){
    std::cout << reinterpret_cast<void *>(value) << '\n';
}

class CPU{
public:
    CPU(){
        conf.initializeMemory();
        conf.reset();
        lookup.emplace(0xA9, new Instruction<0xA9>());
        lookup.emplace(0xA5, new Instruction<0xA5>());
        lookup.emplace(0xB5, new Instruction<0xB5>());
        lookup.emplace(0x95, new Instruction<0x95>());
        lookup.emplace(0x8D, new Instruction<0x8D>());
        lookup.emplace(0x9D, new Instruction<0x9D>());
        lookup.emplace(0x99, new Instruction<0x99>());
        lookup.emplace(0x81, new Instruction<0x81>());
        
        lookup.emplace(0xA2, new Instruction<0xA2>());
        lookup.emplace(0xA6, new Instruction<0xA6>());
        lookup.emplace(0xB6, new Instruction<0xB6>());
        lookup.emplace(0xAE, new Instruction<0xAE>());
        lookup.emplace(0xBE, new Instruction<0xBE>());

        lookup.emplace(0xA0, new Instruction<0xA0>());
        lookup.emplace(0xA4, new Instruction<0xA4>());
        lookup.emplace(0xB4, new Instruction<0xB4>());
        lookup.emplace(0xAC, new Instruction<0xAC>());
        lookup.emplace(0xBC, new Instruction<0xBC>());
        
        lookup.emplace(0x85, new Instruction<0x85>());
        lookup.emplace(0x95, new Instruction<0x95>());
        lookup.emplace(0x8D, new Instruction<0x8D>());
        lookup.emplace(0x9D, new Instruction<0x9D>());
        lookup.emplace(0x99, new Instruction<0x99>());
        lookup.emplace(0x81, new Instruction<0x81>());
        lookup.emplace(0x91, new Instruction<0x91>());

        lookup.emplace(0x86, new Instruction<0x86>());
        lookup.emplace(0x96, new Instruction<0x96>());
        lookup.emplace(0x8E, new Instruction<0x8E>());

        lookup.emplace(0x84, new Instruction<0x84>());
        lookup.emplace(0x94, new Instruction<0x94>());
        lookup.emplace(0x8C, new Instruction<0x8C>());
        
        lookup.emplace(0xAA, new Instruction<0xAA>());
        lookup.emplace(0xA8, new Instruction<0xA8>());
        lookup.emplace(0xBA, new Instruction<0xBA>());
        lookup.emplace(0x8A, new Instruction<0x8A>());
        lookup.emplace(0x94, new Instruction<0x94>());
        lookup.emplace(0x98, new Instruction<0x98>());

        // Initializing memory to these opcodes.
        // For the decoding process
        for(auto [key, value] : lookup){
            conf[key] = value->getOpcode();
        }
    }

    void run(){
        std::cout << "CPU Running...\n";
        printHexDump();
        sleep(2);
        int start = conf.pc;
        print("Starting Program Counter: ");
        printHex(conf.pc);
        print("\n");
        while(conf.pc < conf.memory.size()){
            uint8_t opcode = fetch();
            print("Current Start Val: ");
            printHex(conf.pc);
            print(" => ");
            print("Current Iterative Opcode Value: ");
            printHex(opcode);
            print("\n");
            BaseInstruction* instruction = decode(opcode);

            executeInstruction(instruction);
            // printSP(); // debugging
            sleep(1);
        }
        std::cout << "CPU Stopping...\n";
    }

    // adding out fetch, decode, and execute phases

    // Fetching grabs the next instruction and thhe program counter contains that specific location (basically memory[pc++])
    uint8_t fetch(){
        // uint8_t data = conf.memory[conf.pc++];
        uint8_t data = conf[conf.pc++];
        return data;
    }

    BaseInstruction* decode(uint8_t opcode){
        if(!lookup.contains(opcode)){
            return nullptr;
        }

        return lookup[opcode];
    }

    void executeInstruction(BaseInstruction* instruction){
        if(instruction == nullptr){
            print("In execute(): Instruction was nullptr\n");
            return;
        }

        int value = 2;
        instruction->operation(conf, value);
        // printHex(conf.ac);
        std::cout << instruction << '\n';
        print("AC: ");
        printHex(conf.ac);
        print("\n");
    }

    // We make sure that the CPU is in a known state
    void reset(){
        conf.reset();
    }
private:
    void printSP(){
        print("Stack Pointer: ");
        printHex(0x0100 + conf.sp);
        conf.sp--;
        print("\n");
    }

    // This is just to see if we are able to see all the instructions that
    // have been set in memory.
    void printHexDump(){
        print("Printing Hex Dump\n");
        int sizeOfRows = 16;
        std::cout << '\t';
        for(int i = 0; i <= sizeOfRows; i++){
            std::cout << std::setw(2) << std::hex << i << ' ';
        }
        std::cout << '\n';

        for(int row = 0; row < 30; row++){
            std::cout << std::hex << std::setw(6) <<std::setfill('0') << row * 16 << ' ';
            for(int col = 0; col <= sizeOfRows; col++){
                uint8_t data = conf[row * 16 + col];
                // We want all values that are 0x00 to be ~~
                // Just so we can indicate that no values have been set to that memory location.
                if(data == 0x00) std::cout << std::setw(2) << "~~ ";
                else std::cout << std::hex << std::setw(2) << static_cast<uint64_t>(data) << ' ';
            }
            std::cout << '\n';
        }
    }

private:
    // CPUData contains our registers, and data that'll be modified in the emulator
    CPUData conf;
    std::unordered_map<uint16_t, BaseInstruction *> lookup; // lookup table for searching for instructions corresponding with those opcodes
    BaseInstruction* instruction; // This will store the current instruction that we will want to execute

    // Idea is we want to keep track of what is our current address mode (opcode) that we are fetching
    // To make sure we are executing the right instructions address mode correctly
    // For handling cycles (related stuff).
    std::string currentAddressMode = "";
};