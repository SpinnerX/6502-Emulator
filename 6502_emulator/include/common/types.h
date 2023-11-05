#pragma once
#include <iomanip>
#include <cmath>
#include <unordered_map>
#include <functional>

/**
 * 
 * InstructionData
 * - Contains instruction name, address mode, and opcode
 * - Opcode will help us know if there is a need for additional cycles (since it varies by opcode for each address mode)
 * - Handles in checking if there needs to be additional cycles based on the address mode
 * 
*/

struct InstructionData{
    // returns a value if there is an additional cycles to be computed
    // or returns 0 if no additional cycles depending on address mode
    uint8_t cycle(CPUConfigs& configs){
        return 0;
    }

    std::string name = "Default Name";
    std::string addressMode = "Default mode";
    uint16_t opcode = 0x00;
};


// Adding Instruction Data to hashh table to allow a lookup table for the instruction set.
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
    // instructions.emplace(0xAA, InstructionData{"TAX", "IMPLIED", 0xAA});

    // // TAY (Transfer Accumulator to Index Y)
    // instructions.emplace(0xA8, InstructionData{"TAY", "IMLPIED", 0xA8});

    // // TSX (Transfer Stack Pointer to Index X)
    // instructions.emplace(0xBA, InstructionData{"TSX", "IMPLIED", 0xBA});

    // // TXA (Transfer Index X to Accumulator)
    // instructions.emplace(0x8A, InstructionData{"TXA", "IMPLIED"}, 0x8A);

    // // TXS (Transfer Index X to Stack Register)
    // instructions.emplace(0x9A, InstructionData{"TXS", "IMPLIED", 0x9A});

    // // TYA (Transfer Index Y to Accumulator)
    // instructions.emplace(0x98, InstructionData{"TYA", "IMPLIED", 0x98});

    


    return instructions[opcode];
}