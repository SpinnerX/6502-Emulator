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

    return instructions[opcode];
}