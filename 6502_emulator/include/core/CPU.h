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
#include <sstream>
#include <cassert>

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

/*


// This is how we know the different states the bitfields are in, for each instruction
// This shoiws what the bitfields states are in corresponding with those registers.
Legend to Flags: +  ....  modified
                 -  ....  not modified
                 1  ....  set
                 0  ....  cleared
                 M6 ....  memory bit 6
                 M7 ....  memory bit 7 


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


        // LDX (Load Index X with Memory) Instruction
        instructions.insert({0xA2, [](){ return new Register<0xA2>(); }});
        instructions.insert({0xA6, [](){ return new Register<0xA6>(); }});
        instructions.insert({0xB6, [](){ return new Register<0xB6>(); }});
        instructions.insert({0xAE, [](){ return new Register<0xAE>(); }});
        instructions.insert({0xBE, [](){ return new Register<0xBE>(); }});

        // LDY (Load Index Y with Memory)
        instructions.insert({0xA0, [](){ return new Register<0xA0>(); }});
        instructions.insert({0xA4, [](){ return new Register<0xA4>(); }});
        instructions.insert({0xB4, [](){ return new Register<0xB4>(); }});
        instructions.insert({0xAC, [](){ return new Register<0xAC>(); }});
        instructions.insert({0xBC, [](){ return new Register<0xBC>(); }});


        // STA (Store Accumulator in Memory)
        instructions.insert({0x85, [](){ return new Register<0x85>(); }});
        instructions.insert({0x95, [](){ return new Register<0x95>(); }});
        instructions.insert({0x8D, [](){ return new Register<0x8D>(); }});
        instructions.insert({0x9D, [](){ return new Register<0x9D>(); }});
        instructions.insert({0x99, [](){ return new Register<0x99>(); }});
        instructions.insert({0x81, [](){ return new Register<0x81>(); }});
        instructions.insert({0x91, [](){ return new Register<0x91>(); }});

        // STX (Store X)
        instructions.insert({0x86, [](){ return new Register<0x86>(); }});
        instructions.insert({0x96, [](){ return new Register<0x96>(); }});
        instructions.insert({0x8E, [](){ return new Register<0x8E>(); }});

        // STY (Store Y)
        instructions.insert({0x84, [](){ return new Register<0x84>(); }});
        instructions.insert({0x94, [](){ return new Register<0x94>(); }});
        instructions.insert({0x8C, [](){ return new Register<0x8C>(); }});

        // Transfer Instructions (that only have one address mode, which is IMPLIED)
        instructions.insert({0xAA, [](){ return new Register<0xAA>(); }}); // TAX .. IMPLIED
        instructions.insert({0xA8, [](){ return new Register<0xA8>(); }}); // TAY .. IMPLIED
        instructions.insert({0xBA, [](){ return new Register<0xBA>();}});  // TSX .. IMPLIED
        instructions.insert({0x8A, [](){ return new Register<0x8A>(); }}); // TXA .. IMPLIED
        instructions.insert({0x9A, [](){ return new Register<0x9A>(); }}); // TXS .. IMPLIED
        instructions.insert({0x98, [](){ return new Register<0x98>(); }}); // TYA .. IMPLIED

        // Stack Instructions (transferring accumulator,status reg(flags) to and from stack)
        instructions.insert({0x48, [](){ return new Register<0x48>(); }});
        instructions.insert({0x08, [](){ return new Register<0x08>(); }});
        instructions.insert({0x68, [](){ return new Register<0x68>(); }});
        instructions.insert({0x28, [](){ return new Register<0x28>(); }});

        // Decrements & Increments Instruction
        // DEC - Instruction Name
        instructions.insert({0xC6, [](){ return new Register<0xC6>(); }}); // ZeroPage
        instructions.insert({0xD6, [](){ return new Register<0xD6>(); }}); // ZeroPage X
        instructions.insert({0xCE, [](){ return new Register<0xCE>(); }}); // Absolute
        instructions.insert({0xDE, [](){ return new Register<0xDE>(); }}); // Absolute X

        // INC (Increment Memory by One)
        instructions.insert({0xE6, [](){ return new Register<0xE6>(); }}); // ZeroPage
        instructions.insert({0xF6, [](){ return new Register<0xF6>(); }}); // ZeroPage X
        instructions.insert({0xEE, [](){ return new Register<0xEE>(); }}); // Absolute
        instructions.insert({0xFE, [](){ return new Register<0xFE>(); }}); // ZeroPage

        // INX (Increment Index X By One)
        instructions.insert({0xE8, [](){ return new Register<0xE8>(); }});

        // INY (Increment Index Y By One)
        instructions.insert({0xC8, [](){ return new Register<0xC8>(); }});

        // ADC (Add Memory to Accumulator with Carry)
        instructions.insert({0x69, [](){ return new Register<0x69>(); }}); // IMMEDIATE
        instructions.insert({0x65, [](){ return new Register<0x65>(); }}); // ZeroPage
        instructions.insert({0x75, [](){ return new Register<0x75>(); }}); // ZeroPage X
        instructions.insert({0x6D, [](){ return new Register<0x6D>(); }}); // Absolute
        instructions.insert({0x7D, [](){ return new Register<0x7D>(); }}); // Absolute X
        instructions.insert({0x79, [](){ return new Register<0x79>(); }}); // Absolute Y
        instructions.insert({0x61, [](){ return new Register<0x61>(); }}); // Indirect X
        instructions.insert({0x71, [](){ return new Register<0x71>(); }}); // Indirect Y

        // SBC (Subtract Memory from Accumulator with Borrow)
        instructions.insert({0xE9, [](){ return new Register<0xE9>(); }});
        instructions.insert({0xE5, [](){ return new Register<0xE5>(); }});
        instructions.insert({0xF5, [](){ return new Register<0xF5>(); }});
        instructions.insert({0xED, [](){ return new Register<0xED>(); }});
        instructions.insert({0xFD, [](){ return new Register<0xFD>(); }});
        instructions.insert({0xF9, [](){ return new Register<0xF9>(); }});
        instructions.insert({0xE1, [](){ return new Register<0xE1>(); }});
        instructions.insert({0xF1, [](){ return new Register<0xF1>(); }});


        // AND (AND Memory with Accumulator)
        instructions.insert({0x29, [](){ return new Register<0x29>(); }});
        instructions.insert({0x25, [](){ return new Register<0x25>(); }});
        instructions.insert({0x35, [](){ return new Register<0x35>(); }});
        instructions.insert({0x2D, [](){ return new Register<0x2D>(); }});
        instructions.insert({0x3D, [](){ return new Register<0x3D>(); }});
        instructions.insert({0x39, [](){ return new Register<0x39>(); }});
        instructions.insert({0x21, [](){ return new Register<0x21>(); }});
        instructions.insert({0x31, [](){ return new Register<0x31>(); }});

        //  EOR (Exclusive-OR Memory withh Accumulator)
        instructions.insert({0x49, [](){ return new Register<0x49>(); }});
        instructions.insert({0x45, [](){ return new Register<0x45>(); }});
        instructions.insert({0x55, [](){ return new Register<0x55>(); }});
        instructions.insert({0x4D, [](){ return new Register<0x4D>(); }});
        instructions.insert({0x5D, [](){ return new Register<0x5D>(); }});
        instructions.insert({0x59, [](){ return new Register<0x59>(); }});
        instructions.insert({0x41, [](){ return new Register<0x41>(); }});
        instructions.insert({0x51, [](){ return new Register<0x51>(); }});

        // ORA (Or Memory withAccumulator)
        instructions.insert({0x09, [](){ return new Register<0x09>(); }});
        instructions.insert({0x05, [](){ return new Register<0x05>(); }});
        instructions.insert({0x15, [](){ return new Register<0x15>(); }});
        instructions.insert({0x0D, [](){ return new Register<0x0D>(); }});
        instructions.insert({0x1D, [](){ return new Register<0x1D>(); }});
        instructions.insert({0x19, [](){ return new Register<0x19>(); }});
        instructions.insert({0x01, [](){ return new Register<0x01>(); }});
        instructions.insert({0x11, [](){ return new Register<0x11>(); }});

        // ASL (Shit Left One Bit (Memory or Accumulator) )
        instructions.insert({0x0A, [](){ return new Register<0x0A>(); }});
        instructions.insert({0x06, [](){ return new Register<0x06>(); }});
        instructions.insert({0x16, [](){ return new Register<0x16>(); }});
        instructions.insert({0x0E, [](){ return new Register<0x0E>(); }});
        instructions.insert({0x1E, [](){ return new Register<0x1E>(); }});

        // LSR (Shift One Bit Right)
        instructions.insert({0x4A, [](){ return new Register<0x4A>(); }});
        instructions.insert({0x46, [](){ return new Register<0x46>(); }});
        instructions.insert({0x56, [](){ return new Register<0x56>(); }});
        instructions.insert({0x4E, [](){ return new Register<0x4E>(); }});
        instructions.insert({0x5E, [](){ return new Register<0x5E>(); }});

        // ROL (Rotate One Bit Left (Memory or Accumulator) )
        instructions.insert({0x2A, [](){ return new Register<0x2A>(); }});
        instructions.insert({0x26, [](){ return new Register<0x26>(); }});
        instructions.insert({0x36, [](){ return new Register<0x36>(); }});
        instructions.insert({0x2E, [](){ return new Register<0x2E>(); }});
        instructions.insert({0x3E, [](){ return new Register<0x3E>(); }});


        // ROR (Rotate One Bit Right (Memory or Accumulator) )
        instructions.insert({0x6A, [](){ return new Register<0x6A>(); }});
        instructions.insert({0x66, [](){ return new Register<0x66>(); }});
        instructions.insert({0x76, [](){ return new Register<0x76>(); }});
        instructions.insert({0x6E, [](){ return new Register<0x6E>(); }});
        instructions.insert({0x7E, [](){ return new Register<0x7E>(); }});

        // Transfer Instructions (only have one address modes, IMPLIED)
        instructions.insert({0x18, [](){ return new Register<0x18>(); }}); // CLC .. clears carry
        instructions.insert({0xD8, [](){ return new Register<0xD8>(); }}); // CLD .. clears decimal (BCD arithmetics disabled)
        instructions.insert({0x58, [](){ return new Register<0x58>(); }}); // CLI .. clears interrupt disabled
        instructions.insert({0xB8, [](){ return new Register<0xB8>(); }}); // CLV .. clears overflow
        instructions.insert({0x38, [](){ return new Register<0x38>(); }}); // SEC .. sets carry
        instructions.insert({0xF8, [](){ return new Register<0xF8>(); }}); // SED .. sets decimal (BCD arithmetics enabled)
        instructions.insert({0x78, [](){ return new Register<0x78>(); }}); // SEI .. sets interrupt disable

        // CMP (Compare Memory with Accumulator)
        instructions.insert({0xC9, [](){ return new Register<0xC9>(); }});
        instructions.insert({0xC5, [](){ return new Register<0xC5>(); }});
        instructions.insert({0xD5, [](){ return new Register<0xD5>(); }});
        instructions.insert({0xCD, [](){ return new Register<0xCD>(); }});
        instructions.insert({0xDD, [](){ return new Register<0xDD>(); }});
        instructions.insert({0xD9, [](){ return new Register<0xD9>(); }});
        instructions.insert({0xC1, [](){ return new Register<0xC1>(); }});
        instructions.insert({0xD1, [](){ return new Register<0xD1>(); }});

        // CPX (Compare Memory and Index X)
        instructions.insert({0xE0, [](){ return new Register<0xE0>(); }});
        instructions.insert({0xE4, [](){ return new Register<0xE4>(); }});
        instructions.insert({0xEC, [](){ return new Register<0xEC>(); }});

        // CPY (Compare Memory and Index Y)
        instructions.insert({0xC0, [](){ return new Register<0xC0>(); }});
        instructions.insert({0xC4, [](){ return new Register<0xC4>(); }});
        instructions.insert({0xCC, [](){ return new Register<0xCC>(); }});

        // Branch Instructions
        instructions.insert({0x90, [](){ return new Register<0x90>(); }});
        instructions.insert({0xB0, [](){ return new Register<0xB0>(); }});
        instructions.insert({0xF0, [](){ return new Register<0xF0>(); }});
        instructions.insert({0x30, [](){ return new Register<0x30>(); }});
        instructions.insert({0xD0, [](){ return new Register<0xD0>(); }});
        instructions.insert({0x10, [](){ return new Register<0x10>(); }});
        instructions.insert({0x50, [](){ return new Register<0x50>(); }});
        instructions.insert({0x70, [](){ return new Register<0x70>(); }});

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
            std::cout << "ERROR OCCURED: INVALID OPCODE \"" << reinterpret_cast<void *>(opcode) << "\"\n";
            // int checkExistance =  (!instructions.contains(opcode));
            // static_assert(static_cast<int>((!instructions.contains(opcode))), "Opcode is Invalid or does not exist!\n");
            return nullptr;
        }

        std::function<BaseRegister*()> getInstruction = instructions[opcode];
        BaseRegister* instruction = getInstruction();

        if(instruction == nullptr){
            std::cout << "Nullptr detected in decode() in CPU class!\n";
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