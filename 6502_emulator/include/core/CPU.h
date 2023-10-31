#pragma once
#include <iostream>
#include <unordered_map>
#include <functional>
#include <stack>
#include <common/types.h>
#include <Registers/MnemonicOperation.h>
#include <Configurations/Memory.h>

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
 * Memory
 * - The CPU does not know how memory addresses are designed
 * - Simply knows what addresses to read and write from
 * - Virtual memory could just be std::array<T, size> where we know 
 *   specific regions in memory are for regions RAM, and ROM.
 * 
 * 
 * NOTE:
 * Reset Vector
 * - The reset vector is set at memory address locations $0xFFFC and 0xFFFD
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
        instructions.insert({0xA9, new Operation<0xA9>() }); //  IMMEDIATE
        instructions.insert({0xA5, new Operation<0xA5>() }); //  ZPG
        instructions.insert({0xB5, new Operation<0xB5>() }); //  ZPG X
        instructions.insert({0xAD, new Operation<0xAD>() }); //  ABS
        instructions.insert({0xBD, new Operation<0xBD>() }); //  ABS X
        instructions.insert({0xB9, new Operation<0xB9>() }); //  ABS Y
        instructions.insert({0xA1, new Operation<0xA1>() }); //  INDIRECT X
        instructions.insert({0xB1, new Operation<0xB1>() }); //  INDIRECT Y


        // LDX (Load Index X with Memory) Instruction
        instructions.insert({0xA2, new Operation<0xA2>() });
        instructions.insert({0xA6, new Operation<0xA6>() });
        instructions.insert({0xB6, new Operation<0xB6>() });
        instructions.insert({0xAE, new Operation<0xAE>() });
        instructions.insert({0xBE, new Operation<0xBE>() });

        // LDY (Load Index Y with Memory)
        instructions.insert({0xA0, new Operation<0xA0>() });
        instructions.insert({0xA4, new Operation<0xA4>() });
        instructions.insert({0xB4, new Operation<0xB4>() });
        instructions.insert({0xAC, new Operation<0xAC>() });
        instructions.insert({0xBC, new Operation<0xBC>() });


        // STA (Store Accumulator in Memory)
        instructions.insert({0x85, new Operation<0x85>() });
        instructions.insert({0x95, new Operation<0x95>() });
        instructions.insert({0x8D, new Operation<0x8D>() });
        instructions.insert({0x9D, new Operation<0x9D>() });
        instructions.insert({0x99, new Operation<0x99>() });
        instructions.insert({0x81, new Operation<0x81>() });
        instructions.insert({0x91, new Operation<0x91>() });

        // STX (Store X)
        instructions.insert({0x86, new Operation<0x86>() });
        instructions.insert({0x96, new Operation<0x96>() });
        instructions.insert({0x8E, new Operation<0x8E>() });

        // STY (Store Y)
        instructions.insert({0x84, new Operation<0x84>() });
        instructions.insert({0x94, new Operation<0x94>() });
        instructions.insert({0x8C, new Operation<0x8C>() });

        // Transfer Instructions (that only have one address mode, which is IMPLIED)
        instructions.insert({0xAA, new Operation<0xAA>() }); // TAX .. IMPLIED
        instructions.insert({0xA8, new Operation<0xA8>() }); // TAY .. IMPLIED
        instructions.insert({0xBA, new Operation<0xBA>()});  // TSX .. IMPLIED
        instructions.insert({0x8A, new Operation<0x8A>() }); // TXA .. IMPLIED
        instructions.insert({0x9A, new Operation<0x9A>() }); // TXS .. IMPLIED
        instructions.insert({0x98, new Operation<0x98>() }); // TYA .. IMPLIED

        // Stack Instructions (transferring accumulator,status reg(flags) to and from stack)
        instructions.insert({0x48, new Operation<0x48>() });
        instructions.insert({0x08, new Operation<0x08>() });
        instructions.insert({0x68, new Operation<0x68>() });
        instructions.insert({0x28, new Operation<0x28>() });

        // Decrements & Increments Instruction
        // DEC - Instruction Name
        instructions.insert({0xC6, new Operation<0xC6>() }); // ZeroPage
        instructions.insert({0xD6, new Operation<0xD6>() }); // ZeroPage X
        instructions.insert({0xCE, new Operation<0xCE>() }); // Absolute
        instructions.insert({0xDE, new Operation<0xDE>() }); // Absolute X

        // INC (Increment Memory by One)
        instructions.insert({0xE6, new Operation<0xE6>() }); // ZeroPage
        instructions.insert({0xF6, new Operation<0xF6>() }); // ZeroPage X
        instructions.insert({0xEE, new Operation<0xEE>() }); // Absolute
        instructions.insert({0xFE, new Operation<0xFE>() }); // ZeroPage

        // INX (Increment Index X By One)
        instructions.insert({0xE8, new Operation<0xE8>() });

        // INY (Increment Index Y By One)
        instructions.insert({0xC8, new Operation<0xC8>() });

        // ADC (Add Memory to Accumulator with Carry)
        instructions.insert({0x69, new Operation<0x69>() }); // IMMEDIATE
        instructions.insert({0x65, new Operation<0x65>() }); // ZeroPage
        instructions.insert({0x75, new Operation<0x75>() }); // ZeroPage X
        instructions.insert({0x6D, new Operation<0x6D>() }); // Absolute
        instructions.insert({0x7D, new Operation<0x7D>() }); // Absolute X
        instructions.insert({0x79, new Operation<0x79>() }); // Absolute Y
        instructions.insert({0x61, new Operation<0x61>() }); // Indirect X
        instructions.insert({0x71, new Operation<0x71>() }); // Indirect Y

        // SBC (Subtract Memory from Accumulator with Borrow)
        instructions.insert({0xE9, new Operation<0xE9>() });
        instructions.insert({0xE5, new Operation<0xE5>() });
        instructions.insert({0xF5, new Operation<0xF5>() });
        instructions.insert({0xED, new Operation<0xED>() });
        instructions.insert({0xFD, new Operation<0xFD>() });
        instructions.insert({0xF9, new Operation<0xF9>() });
        instructions.insert({0xE1, new Operation<0xE1>() });
        instructions.insert({0xF1, new Operation<0xF1>() });


        // AND (AND Memory with Accumulator)
        instructions.insert({0x29, new Operation<0x29>() });
        instructions.insert({0x25, new Operation<0x25>() });
        instructions.insert({0x35, new Operation<0x35>() });
        instructions.insert({0x2D, new Operation<0x2D>() });
        instructions.insert({0x3D, new Operation<0x3D>() });
        instructions.insert({0x39, new Operation<0x39>() });
        instructions.insert({0x21, new Operation<0x21>() });
        instructions.insert({0x31, new Operation<0x31>() });

        //  EOR (Exclusive-OR Memory withh Accumulator)
        instructions.insert({0x49, new Operation<0x49>() });
        instructions.insert({0x45, new Operation<0x45>() });
        instructions.insert({0x55, new Operation<0x55>() });
        instructions.insert({0x4D, new Operation<0x4D>() });
        instructions.insert({0x5D, new Operation<0x5D>() });
        instructions.insert({0x59, new Operation<0x59>() });
        instructions.insert({0x41, new Operation<0x41>() });
        instructions.insert({0x51, new Operation<0x51>() });

        // ORA (Or Memory withAccumulator)
        instructions.insert({0x09, new Operation<0x09>() });
        instructions.insert({0x05, new Operation<0x05>() });
        instructions.insert({0x15, new Operation<0x15>() });
        instructions.insert({0x0D, new Operation<0x0D>() });
        instructions.insert({0x1D, new Operation<0x1D>() });
        instructions.insert({0x19, new Operation<0x19>() });
        instructions.insert({0x01, new Operation<0x01>() });
        instructions.insert({0x11, new Operation<0x11>() });

        // ASL (Shit Left One Bit (Memory or Accumulator) )
        instructions.insert({0x0A, new Operation<0x0A>() });
        instructions.insert({0x06, new Operation<0x06>() });
        instructions.insert({0x16, new Operation<0x16>() });
        instructions.insert({0x0E, new Operation<0x0E>() });
        instructions.insert({0x1E, new Operation<0x1E>() });

        // LSR (Shift One Bit Right)
        instructions.insert({0x4A, new Operation<0x4A>() });
        instructions.insert({0x46, new Operation<0x46>() });
        instructions.insert({0x56, new Operation<0x56>() });
        instructions.insert({0x4E, new Operation<0x4E>() });
        instructions.insert({0x5E, new Operation<0x5E>() });

        // ROL (Rotate One Bit Left (Memory or Accumulator) )
        instructions.insert({0x2A, new Operation<0x2A>() });
        instructions.insert({0x26, new Operation<0x26>() });
        instructions.insert({0x36, new Operation<0x36>() });
        instructions.insert({0x2E, new Operation<0x2E>() });
        instructions.insert({0x3E, new Operation<0x3E>() });


        // ROR (Rotate One Bit Right (Memory or Accumulator) )
        instructions.insert({0x6A, new Operation<0x6A>() });
        instructions.insert({0x66, new Operation<0x66>() });
        instructions.insert({0x76, new Operation<0x76>() });
        instructions.insert({0x6E, new Operation<0x6E>() });
        instructions.insert({0x7E, new Operation<0x7E>() });

        // Transfer Instructions (only have one address modes, IMPLIED)
        instructions.insert({0x18, new Operation<0x18>() }); // CLC .. clears carry
        instructions.insert({0xD8, new Operation<0xD8>() }); // CLD .. clears decimal (BCD arithmetics disabled)
        instructions.insert({0x58, new Operation<0x58>() }); // CLI .. clears interrupt disabled
        instructions.insert({0xB8, new Operation<0xB8>() }); // CLV .. clears overflow
        instructions.insert({0x38, new Operation<0x38>() }); // SEC .. sets carry
        instructions.insert({0xF8, new Operation<0xF8>() }); // SED .. sets decimal (BCD arithmetics enabled)
        instructions.insert({0x78, new Operation<0x78>() }); // SEI .. sets interrupt disable

        // CMP (Compare Memory with Accumulator)
        instructions.insert({0xC9, new Operation<0xC9>() });
        instructions.insert({0xC5, new Operation<0xC5>() });
        instructions.insert({0xD5, new Operation<0xD5>() });
        instructions.insert({0xCD, new Operation<0xCD>() });
        instructions.insert({0xDD, new Operation<0xDD>() });
        instructions.insert({0xD9, new Operation<0xD9>() });
        instructions.insert({0xC1, new Operation<0xC1>() });
        instructions.insert({0xD1, new Operation<0xD1>() });

        // CPX (Compare Memory and Index X)
        instructions.insert({0xE0, new Operation<0xE0>() });
        instructions.insert({0xE4, new Operation<0xE4>() });
        instructions.insert({0xEC, new Operation<0xEC>() });

        // CPY (Compare Memory and Index Y)
        instructions.insert({0xC0, new Operation<0xC0>() });
        instructions.insert({0xC4, new Operation<0xC4>() });
        instructions.insert({0xCC, new Operation<0xCC>() });

        // Branch Instructions
        instructions.insert({0x90, new Operation<0x90>() }); // BCC .... Branch on Carry Clear
        instructions.insert({0xB0, new Operation<0xB0>() }); // BCS .... Branch on Carry Set
        instructions.insert({0xF0, new Operation<0xF0>() }); // BEQ .... Branchh on Equal (zero set)
        instructions.insert({0x30, new Operation<0x30>() }); // BMI .... Branch on minus (negative set)
        instructions.insert({0xD0, new Operation<0xD0>() }); // BNE .... Branch on not equal (zero clear)
        instructions.insert({0x10, new Operation<0x10>() }); // BPL .... Branch on plus (negative clear)
        instructions.insert({0x50, new Operation<0x50>() }); // BVC .... Branch on overflow clear
        instructions.insert({0x70, new Operation<0x70>() }); // BVS .... Branch on overflow set

        // Jump and Subroutine Instructions
        // JMP
        instructions.insert({0x4C, new Operation<0x4C>() }); // ABSOLUTE
        instructions.insert({0x6C, new Operation<0x6C>() }); // INDIRECT
        instructions.insert({0x20, new Operation<0x20>() }); // JSR - ABSOLUTE
        instructions.insert({0x60, new Operation<0x60>() }); // RTS - IMPLIED

        // Interrupts
        instructions.insert({0x00, new Operation<0x00>() }); // BRK (Force Break)
        instructions.insert({0x00, new Operation<0x40>() }); // RTI ( return from Interrupt)

        // Other Operation Instructions
        instructions.insert({0x24, new Operation<0x24>() });
        instructions.insert({0x2C, new Operation<0x2C>() });
        instructions.insert({0xEA, new Operation<0xEA>() });

    }

    ~CPU(){
        instructions.clear();
    }

    /**
     * 
     * 
     * - Changes thhe state of thhe
     * 
    */
    void turnOnCPU(){

    }

    // This is how the CPU configures the instructions, during the boot up phase
    void memoryConfigurations(){}

    // fetches
    opcode_t read(){
        PC++;
        std::cout << "Program Counter: " << PC << '\n';
        // return memory[PC];
        return 0;
    }

    // Resets the program counter, based on the reset vector.
    void reset(){}

    /**
     * 
     * 
     * decode()
     * - retrieves based on the opcode the address mode, bytes, cycles, and opcode.
     * - This basically allows us to know and evaluate which instruction to execute first.
     * - returns the register, likely returns: Register<opcode>
    */

    template<opcode_t opcode>
    BaseOperation* decode(){
        // We want to check if the register is in the lookup table
        // Knowing if its not in the lookup then no need to continue, and throw an assert.
        if(!instructions.contains(opcode)){
            return nullptr;
        }

        return instructions[opcode];
    }


    // Application user only should execute this function without creating an instance of an object directly from main.
    friend void execute(bool isCpuRunning);

    /*
        resetVector = "$0xFFFC to $0xFFFD"
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
    // Virtual Memory
    // std::array<uint64_t, 65536> memory; // Acts as the virtual memory.
    std::array<uint64_t, 0xFFFFD> memory; // Acts as the virtual memory.
    std::stack<int> callStack; // Virtual Call stack
    // std::unordered_map<opcode_t,  std::function<BaseOperation*()> > instructions; // Containing the registers
    std::unordered_map<opcode_t,  BaseOperation*> instructions; // Containing the registers
    int resetVector = 0xFFFFC;
    State cpuState; //
};