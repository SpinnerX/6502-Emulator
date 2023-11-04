#pragma once
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <unistd.h>
#include <Instructions/InstructionSet.h>
#include <common/CPUConfigs.h>

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
        memory.fill(0);
        memory[0x03] = 0xA9;
        memory[0xFFFC] = 0x0000;
        memory[0xFFFC] = 0x0001;

        lookup.insert({0xA9, new Instruction<0xA9>()});
    }

    void run(){
        std::cout << "CPU Running...\n";
        int start = conf.pc;

        while(start < lookup.size()){
            uint16_t opcode = fetch();
            BaseInstruction* instruction = decode(opcode);

            executeInstruction(instruction);
            sleep(1);
        }
    }

    // adding out fetch, decode, and execute phases

    // Fetching grabs the next instruction and thhe program counter contains that specific location (basically memory[pc++])
    uint8_t fetch(){
        uint8_t data = memory[conf.pc++];
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

        reset();
        // if(instruction->addressMode == "IMM" and instruction->name == "LDA"){
        //     print("IMM (Immediate) mode called\n");
        //     instruction->operation(conf, value);
        //     setFlag(CPUConfigs::Status::Z, conf.ac == 0x00);
        //     setFlag(CPUConfigs::Status::N, conf.ac & 0x80);
        //     printHex(conf.ac);

        //     reset();
        // }



    }

    // We make sure that the CPU is in a known state
    void reset(){
        conf.reset();
    }

private:
    // CPUConfigs contains our register
    CPUConfigs conf;
    std::array<uint8_t, 64 * 1024> memory; // virtual memory
    std::unordered_map<uint16_t, BaseInstruction *> lookup; // lookup table for searching 
    BaseInstruction* instruction; // This will store the current instruction that we will want to execute
};