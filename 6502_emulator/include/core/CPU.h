#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <array>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
#include <map>
#include <set>
#include <unordered_map>
#include <fcntl.h>
#include <functional>
#include <bit>
#include <cstdint>
#include <numeric>
#include <common/types.h>
#include <Registers/Registers.h>
#include <Configurations/Memory.h>
#include <formatCpp/formatCpp.h>

/**
 * 
 * CPU Information
 * PC - program counter (8 bits, 1 byte): Holds the memory address of the next instruction going to be fetched, decoded, and executed.
 * SP - stack pointer (16 bits, 2 bytes): Used to keep track of the current position on the stack
 * A - accumulator (8 bits, 1 byte): main register used for arithmetic and logical operations
 * X - index register (8 bits, 1 byte): primarily used for indexing memory locations or as a counter.
 * Y - index register (8 bits, 1 byte): used for indexing memory or as a counter
 * Reset Vector - (16 bits, 2 bytes): stores memory addresses where CPU starts execution after reset signal received.
 * 
*/

/**
 * 
 * NOTES:
 * 
 * START:
 * 
 * Testing CPU Emulatorory
 * 2.) Check the fetch, decode, execute processes
 * 1.) First there is a need to initialize an array of mem
 * 3.) Double checking each process is successfully fetching, decoding, and executing successfully.
 * 4.) Once, we can confirm these are working then continue to looking at cleaning up the code base/reformatting file structure
 * 
 * 
 * END:
 * 
 * 
*/

class CPU{
public:
    CPU(){

        // LDA (Load accumulator to Memory) Instruction
        instructions.insert({0xA9, [](){ return new Register<0xA9>(); }}); //  IMMEDIATE
        instructions.insert({0xA5, [](){ return new Register<0xA5>(); }}); //  ZPG
        instructions.insert({0xB5, [](){ return new Register<0xB5>(); }}); //  ZPG X
        instructions.insert({0xAD, [](){ return new Register<0xAD>(); }}); //  ABS
        instructions.insert({0xBD, [](){ return new Register<0xBD>(); }}); //  ABS X
        instructions.insert({0xB9, [](){ return new Register<0xB9>(); }}); //  ABS Y
        instructions.insert({0xA1, [](){ return new Register<0xA1>(); }}); //  INDIRECT X
        instructions.insert({0xB1, [](){ return new Register<0xB1>(); }}); //  INDIRECT Y


        // LDX (Load Index Y with Memory) Instruction
        instructions.insert({0xA2, [](){ return new Register<0xA2>(); }});
        instructions.insert({0xA6, [](){ return new Register<0xA6>(); }});
        instructions.insert({0xB6, [](){ return new Register<0xB6>(); }});
        instructions.insert({0xAE, [](){ return new Register<0xAE>(); }});
        instructions.insert({0xBE, [](){ return new Register<0xBE>(); }});
    }


    // This is how the CPU configures the instructions, during the boot up phase
    void memoryConfigurations(){}

    // fetches
    opcode_t read(){
        PC++;
        std::cout << "Program Counter: " << PC << '\n';
        return memory[PC];
    }

    /**
     * 
     * 
     * decode()
     * - retrieves based on the opcode the address mode, bytes, cycles, and opcode.
     * - This basically allows us to know and evaluate which instruction to execute first.
     * - returns the register, likely returns: Register<opcode>
    */

    template<opcode_t opcode>
    BaseRegister* decode(){
        
        if(!instructions.contains(opcode)){
            // formatCpp::print("Convert {} to hexadecimal to see what hex number this is\n", opcode);
            formatCpp::print("Invalid opcode not found: ");
            std::cout << reinterpret_cast<void *>(opcode);
            formatCpp::print("\n");
            formatCpp::print("ERROR OCCURED: INVALID OPCODE!\n");
            exit(0);
            return nullptr;
        }

        std::function<BaseRegister*()> getInstruction = instructions[opcode];
        BaseRegister* instruction = getInstruction();


        if(instruction == nullptr){
            formatCpp::print("Nullptr detected in decode() in CPU class!\n");
            return nullptr;
        }

        return instruction;
    }


    // Application user only should execute this function without creating an instance of an object directly from main.
    friend void execute(bool isCpuRunning);

    /*
        resetVector = 0xFFFFC;
        PC = 0x0000; // 0x0000 to 0xFFFF
        SP = 0xFF; // 0x0100
        AC = 0;
        X = 0;
        Y = 0;
    */
    Bytes2 PC = 0x0000; // Program Counter
    Byte SP=0xFF; // Stack Ptr
    Byte A = 0; // accumulator
    Byte X = 0; // index-reg
    Byte Y = 0; // index-reg
    std::array<u8, 65536> memory; // Ram Memory
    int resetVector = 0xFFFFC;
    std::unordered_map<opcode_t,  std::function<BaseRegister*()> > instructions; // Containing the registers
};