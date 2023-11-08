#pragma once
#include <iomanip>
#include <cmath>
#include <unordered_map>
#include <functional>

/**
 * 
 * InstructionData (a POD)
 * - Contains instruction name, address mode, and opcode
 * - Opcode will help us know if there is a need for additional cycles (since it varies by opcode for each address mode)
 * - Handles in checking if there needs to be additional cycles based on the address mode
 * 
 * Address Modes Abbreviation Definition
 * IMM - Immediate
 * ZPG - ZeroPage
 * ZPGX - ZeroPage X
 * ZPGY - ZeroPage Y
 * ABS - Absolute
 * ABSX - Absolute X
 * ABSY - Absolute X
 * IND_X - (Indirect, X)
 * IND_Y - (Indirect), Y
 * AC - Accumulator
*/

struct InstructionData{
    // returns a value if there is an additional cycles to be computed
    // or returns 0 if no additional cycles depending on address mode
    uint8_t cycle(CPUData& configs){
        return 0;
    }

    std::string name = "Default Name";
    std::string addressMode = "Default mode";
    uint16_t opcode = 0x00;
};


// Adding Instruction Data to hash table to allow a lookup table for the instruction set.
// We have this hash table containing InstructionData's is because we know that there are going to be
// instructions with variations of opcodes, and address modes, InstrucionData is basically how we are going to
// be organizing that data.
InstructionData instructionData(uint16_t opcode){
    std::unordered_map<uint16_t, InstructionData> instructions; // unordered_map<opcode, name>


    // LDA Instruction (Loading accumulator)
    instructions.emplace(0xA9, InstructionData{"LDA", "IMM", 0xA9}); // IMMEDIATE
    instructions.emplace(0xA5, InstructionData{"LDA", "ZPG", 0xA5}); // ZeroPage
    instructions.emplace(0xB5, InstructionData{"LDA", "ZPGX", 0xB5}); // ZeroPage X
    instructions.emplace(0xAD, InstructionData{"LDA", "ABS", 0xAD}); // Absolute
    instructions.emplace(0xBD, InstructionData{"LDA", "ABSX", 0xBD}); // Absolute X
    instructions.emplace(0xB9, InstructionData{"LDA", "ABSY", 0xB9}); // Absolute Y
    instructions.emplace(0xA1, InstructionData{"LDA", "IND_X", 0xA1}); // (Indirect, X)
    instructions.emplace(0xB1, InstructionData{"LDA", "IND_Y", 0xB1}); // (Indirect), Y


    // LDX Instruction (Loading x register)
    instructions.emplace(0xA2, InstructionData{"LDX", "IMM", 0xA2}); // IMMEDIATE
    instructions.emplace(0xA6, InstructionData{"LDX", "ZPG", 0xA6}); // ZeroPage
    instructions.emplace(0xB6, InstructionData{"LDX", "ZPGY", 0xB6}); // ZeroPage Y
    instructions.emplace(0xAE, InstructionData{"LDX", "ABS", 0xAE}); // Absolute
    instructions.emplace(0xBE, InstructionData{"LDX", "ABSY", 0xBE}); // Absolute Y

    // LDY Instruction (Loading y register)
    instructions.emplace(0xA0, InstructionData{"LDY", "IMM", 0xA0}); // IMMEDIATE
    instructions.emplace(0xA4, InstructionData{"LDY", "ZPG", 0xA4}); // ZeroPage
    instructions.emplace(0xB4, InstructionData{"LDY", "ZPGX", 0xB4}); // ZeroPage X
    instructions.emplace(0xAC, InstructionData{"LDY", "ABS", 0xAC}); // Absolute
    instructions.emplace(0xBC, InstructionData{"LDY", "ABSX", 0xBC}); // Absolute X

    // STA (Store Accumulator in Memory)
    instructions.emplace(0x85, InstructionData{"STA", "ZPG", 0x85}); // ZeroPage
    instructions.emplace(0x95, InstructionData{"STA", "ZPGX", 0x95}); // ZeroPage X
    instructions.emplace(0x8D, InstructionData{"STA", "ABS", 0x8D}); // Absolute
    instructions.emplace(0x9D, InstructionData{"STA", "ABSX", 0x9D}); // Absolute X
    instructions.emplace(0x99, InstructionData{"STA", "ABSY", 0x99}); // Absolute Y
    instructions.emplace(0x81, InstructionData{"STA", "IND_X", 0x81}); // (Indirect, X)
    instructions.emplace(0x91, InstructionData{"STA", "IND_Y", 0x91}); // (Indirect), Y

    // STX (Store X in Memory)
    instructions.emplace(0x86, InstructionData{"STX", "ZPG", 0x86}); // ZeroPage
    instructions.emplace(0x96, InstructionData{"STX", "ZPGY", 0x96}); // ZeroPage Y
    instructions.emplace(0x8E, InstructionData{"STX", "ABS", 0x8E}); // Absolute

    // STY (Store Y in Memory)
    instructions.emplace(0x84, InstructionData{"STY", "ZPG", 0X84}); // ZeroPage
    instructions.emplace(0x94, InstructionData{"STY", "ZPGX", 0X94}); // ZeroPage X
    instructions.emplace(0x8C, InstructionData{"STY", "ABS", 0X8C}); // Absolute

    // TAX (Transfer Accumulator to Index X)
    instructions.emplace(0xAA, InstructionData{"TAX", "IMPLIED", 0xAA});

    // // TAY (Transfer Accumulator to Index Y)
    instructions.emplace(0xA8, InstructionData{"TAY", "IMLPIED", 0xA8});

    // // TSX (Transfer Stack Pointer to Index X)
    instructions.emplace(0xBA, InstructionData{"TSX", "IMPLIED", 0xBA});

    // // TXA (Transfer Index X to Accumulator)
    instructions.emplace(0x8A, InstructionData{"TXA", "IMPLIED", 0x8A});

    // // TXS (Transfer Index X to Stack Register)
    instructions.emplace(0x9A, InstructionData{"TXS", "IMPLIED", 0x9A});

    // TYA (Transfer Index Y to Accumulator)
    instructions.emplace(0x98, InstructionData{"TYA", "IMPLIED", 0x98});


    // Stack Instructions
    
    // PHA (Push accumulator on Stack)
    instructions.emplace(0x48, InstructionData{"PHA", "IMPLIED", 0x48});

    // PHP (Push Processor Status on Stack)
    instructions.emplace(0x08, InstructionData{"PHP", "IMPLIED", 0x08});

    // PLA (Pull Accumulator from Stack)
    instructions.emplace(0x68, InstructionData{"PLA", "IMPLIED", 0x68});


    // Adding Decrement/Increment, Arithmetic Operations, Logical Operations
    // These are not going to be defined, until maybe ALU is implemented possibly
    // Or might implement protoypes of a few of these to test for c orrectness
    
    
    // DEC (Decrement Memory by One)
    instructions.emplace(0xC6, InstructionData{"DEC", "ZPG", 0xC6}); // ZeroPage
    instructions.emplace(0xC6, InstructionData{"DEC", "ZPGX", 0xD6}); // ZeroPage X
    instructions.emplace(0xC6, InstructionData{"DEC", "ABS", 0xCE}); // Absolute
    instructions.emplace(0xC6, InstructionData{"DEC", "ABSX", 0xDE}); // Absolute X
    

    // DEX (Decrement Index X by One)
    instructions.emplace(0xCA, InstructionData{"DEX", "IMPLIED", 0xCA});
    
    // DEY (Decrement Index Y by One)
    instructions.emplace(0x88, InstructionData{"DEY", "IMPLIED", 0x88});

    // Arithmetic Operations

    // ADC (Add Memory to Accumulator with Carry)
    instructions.emplace(0x69, InstructionData{"ADC", "IMM", 0x69}); // Immediate
    instructions.emplace(0x65, InstructionData{"ADC", "ZPG", 0x65}); // ZeroPage
    instructions.emplace(0x75, InstructionData{"ADC", "ZPGX", 0x75}); // ZeroPage X
    instructions.emplace(0x6D, InstructionData{"ADC", "ABS", 0x6D}); // Absolute
    instructions.emplace(0x7D, InstructionData{"ADC", "ABSX", 0x7D}); // Absolute X
    instructions.emplace(0x79, InstructionData{"ADC", "ABSY", 0x79}); // Absolute Y
    instructions.emplace(0x61, InstructionData{"ADC", "IND_X", 0x61}); // (Indirect, X)
    instructions.emplace(0x71, InstructionData{"ADC", "IND_Y", 0x71}); // (Indirect), Y

    // SBC (Subtract Memory from Accumulator with Borrow)
    instructions.emplace(0xE9, InstructionData{"SBC", "IMM", 0xE9}); // Immediate
    instructions.emplace(0xE5, InstructionData{"SBC", "ZPG", 0xE5}); // ZeroPage
    instructions.emplace(0xF5, InstructionData{"SBC", "ZPGX", 0xF5}); // ZeroPage X
    instructions.emplace(0xED, InstructionData{"SBC", "ABS", 0xED}); // Absolute
    instructions.emplace(0xFD, InstructionData{"SBC", "ABSX", 0xFD}); // Absolute X
    instructions.emplace(0xF9, InstructionData{"SBC", "ABSY", 0xF9}); // Absolute Y
    instructions.emplace(0xE1, InstructionData{"SBC", "IND_X", 0xE1}); // (Indirect, X)
    instructions.emplace(0xF1, InstructionData{"SBC", "IND_Y", 0xF1}); // (Indirect), Y


    // Logical Operations

    // AND - AND Memory with Accumulator
    instructions.emplace(0x29, InstructionData{"AND", "IMM", 0x29}); // Immediate
    instructions.emplace(0x25, InstructionData{"AND", "ZPG", 0x25}); // ZeroPage
    instructions.emplace(0x35, InstructionData{"AND", "ZPGX", 0x35}); // ZeroPage X
    instructions.emplace(0x2D, InstructionData{"AND", "ABS", 0x2D}); // Absolute 
    instructions.emplace(0x3D, InstructionData{"AND", "ABSX", 0x3D}); // Absolute X
    instructions.emplace(0x39, InstructionData{"AND", "ABSY", 0x39}); // Absolute Y
    instructions.emplace(0x21, InstructionData{"AND", "IND_X", 0x21}); // (Indirect, X)
    instructions.emplace(0x31, InstructionData{"AND", "IND_Y", 0x31}); // (Indirect), Y

    // EOR (Exclusive-OR Memory with Accumulator)
    instructions.emplace(0x49, InstructionData{"EOR", "IMM", 0x49}); // Immediate
    instructions.emplace(0x45, InstructionData{"EOR", "ZPG", 0x45}); // ZeroPage
    instructions.emplace(0x55, InstructionData{"EOR", "ZPGX", 0x55}); // ZeroPage X
    instructions.emplace(0x4D, InstructionData{"EOR", "ABS", 0x4D}); // Absolute 
    instructions.emplace(0x5D, InstructionData{"EOR", "ABSX", 0x5D}); // Absolute X
    instructions.emplace(0x59, InstructionData{"EOR", "ABSY", 0x59}); // Absolute Y
    instructions.emplace(0x41, InstructionData{"EOR", "IND_X", 0x41}); // (Indirect, X)
    instructions.emplace(0x51, InstructionData{"EOR", "IND_Y", 0x51}); // (Indirect), Y

    // ORA (OR Memory with Accumulator)
    instructions.emplace(0x09, InstructionData{"ORA", "IMM", 0x09}); // Immediate
    instructions.emplace(0x05, InstructionData{"ORA", "ZPG", 0x05}); // ZeroPage
    instructions.emplace(0x15, InstructionData{"ORA", "ZPGX", 0x15}); // ZeroPage X
    instructions.emplace(0x0D, InstructionData{"ORA", "ABS", 0x0D}); // Absolute
    instructions.emplace(0x1D, InstructionData{"ORA", "ABSX", 0x1D}); // Absolute X
    instructions.emplace(0x19, InstructionData{"ORA", "ABSY", 0x19}); // Absolute Y
    instructions.emplace(0x01, InstructionData{"ORA", "IND_X", 0x01}); // (Indirect, X)
    instructions.emplace(0x11, InstructionData{"ORA", "IND_Y", 0x11}); // (Indirect), Y
    

    // Shifting and Rotation Instructions

    // ASL - Shift Left One Bit (Memory or Accumulator)
    instructions.emplace(0x0A, InstructionData{"ASL", "A", 0x0A});
    instructions.emplace(0x06, InstructionData{"ASL", "IMM", 0x06});


    return instructions[opcode];
}