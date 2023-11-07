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
    std::cout << value << '\n';
}

void printHex(uint16_t value){
    std::cout << "VAL: " << reinterpret_cast<void *>(value) << '\n';
}

class CPU{
public:
    CPU(){
        conf.initializeMemory();
        conf.reset();
        lookup.insert({0xA9, new Instruction<0xA9>()});
    }

    void run(){
        std::cout << "CPU Running...\n";
        int start = conf.pc;
        while(start < lookup.size()){
            uint16_t opcode = fetch();
            BaseInstruction* instruction = decode(opcode);

            // executeInstruction(instruction);
            printSP(); // debugging
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
        printHex(conf.ac);

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

private:
    // CPUD contains our register
    CPUData conf;
    std::unordered_map<uint16_t, BaseInstruction *> lookup; // lookup table for searching 
    BaseInstruction* instruction; // This will store the current instruction that we will want to execute
};