#pragma once
#include <cstring>
#include <type_traits>
#include <cstdlib>
#include <common/types.h>
#include <ostream>


/**
 * 
 * InstructionTraits
 * - Contain specialized templates, that are traits very dependent on the type of instructions and the opcodes with the corresponding address modes to them.
 * 
 * Base template specialization
 * - Allowing to create generalized way of retrieving data based on opcode to Address Modes
 * 
*/
struct InstructionTraits{
    InstructionTraits() = default;
    InstructionTraits(RegisterTypes type, AddressModes mode, opcode_t opcode, int bytes, int cycles) : type(type), mode(mode), opcode(opcode), bytes(bytes), cycles(cycles) { }

    friend std::ostream& operator<<(std::ostream& outs, const InstructionTraits& traits){
        outs << "--------- [";
        switch (traits.type){
        case RegisterTypes::ADC:
            outs << "ADC";
            break;
        case RegisterTypes::AND:
            outs << "AND";
            break;
        case RegisterTypes::ASL:
            outs << "ASL";
            break;
        case RegisterTypes::BCC:
            outs << "BCC";
            break;
        case RegisterTypes::BCS:
            outs << "BCS";
            break;
        case RegisterTypes::BEQ:
            outs << "BEQ";
            break;
        case RegisterTypes::BIT:
            outs << "BIT";
            break;
        case RegisterTypes::BMI:
            outs << "BMI";
            break;
        case RegisterTypes::BNE:
            outs << "BNE";
            break;
        case RegisterTypes::BPL:
            outs << "BPL";
            break;
        case RegisterTypes::BRK:
            outs << "BRK";
            break;
        case RegisterTypes::BVC:
            outs << "BVC";
            break;
        case RegisterTypes::BVS:
            outs << "BVS";
            break;
        case RegisterTypes::CLC:
            outs << "CLC";
            break;
        case RegisterTypes::CLD:
            outs << "CLD";
            break;
        case RegisterTypes::CLV:
            outs << "CLV";
            break;
        case RegisterTypes::CMP:
            outs << "CMP";
            break;
        case RegisterTypes::CPX:
            outs << "CPX";
            break;
        case RegisterTypes::CPY:
            outs << "CPY";
            break;
        case RegisterTypes::DEC:
            outs << "DEC";
            break;
        case RegisterTypes::DEX:
            outs << "DEX";
            break;
        case RegisterTypes::DEY:
            outs << "DEY";
            break;
        case RegisterTypes::EOR:
            outs << "EOR";
            break;
        case RegisterTypes::INC:
            outs << "INC";
            break;
        case RegisterTypes::INX:
            outs << "INX";
            break;
        case RegisterTypes::INY:
            outs << "INY";
            break;
        case RegisterTypes::JMP:
            outs << "JMP";
            break;
        case RegisterTypes::JSR:
            outs << "JSR";
            break;
        case RegisterTypes::LDA:
            outs << "LDA";
            break;
        case RegisterTypes::LDX:
            outs << "LDX";
            break;
        case RegisterTypes::LDY:
            outs << "LDY";
            break;
        case RegisterTypes::LSR:
            outs << "LSR";
            break;
        case RegisterTypes::NOP:
            outs << "NOP";
            break;
        case RegisterTypes::ORA:
            outs << "ORA";
            break;
        case RegisterTypes::PHA:
            outs << "PHA";
            break;
        case RegisterTypes::PHP:
            outs << "PHP";
            break;
        case RegisterTypes::PLA:
            outs << "PLA";
            break;
        case RegisterTypes::PLP:
            outs << "PLP";
            break;
        case RegisterTypes::ROL:
            outs << "ROL";
            break;
        case RegisterTypes::ROR:
            outs << "ROR";
            break;
        case RegisterTypes::RTI:
            outs << "RTI";
            break;
        case RegisterTypes::RTS:
            outs << "RTS";
            break;
        case RegisterTypes::SBC:
            outs << "SBC";
            break;
        case RegisterTypes::SEC:
            outs << "SEC";
            break;
        case RegisterTypes::SED:
            outs << "SED";
            break;
        case RegisterTypes::SEI:
            outs << "SEI";
            break;
        case RegisterTypes::STA:
            outs << "STA";
            break;
        case RegisterTypes::STX:
            outs << "STX";
            break;
        case RegisterTypes::STY:
            outs << "STY";
            break;
        case RegisterTypes::TAX:
            outs << "TAX";
            break;
        case RegisterTypes::TAY:
            outs << "TAY";
            break;
        case RegisterTypes::TSX:
            outs << "TSX";
            break;
        case RegisterTypes::TXA:
            outs << "TXA";
            break;
        case RegisterTypes::TXS:
            outs << "TXS";
            break;
        case RegisterTypes::TYA:
            outs << "TYA";
            break;
        default:
            outs << "Default value as reg type";
            break;
        }

        outs << "] -----> [";
        if(traits.mode == AddressModes::IMMEDIATE){
            outs << "Immediate";
        }
        else if(traits.mode == AddressModes::ZPG){
            outs << "ZeroPage";
        }
        else if(traits.mode == AddressModes::ZPG_X){
            outs << "ZeroPage X";
        }
        else if(traits.mode == AddressModes::ABS){
            outs << "Absolute";
        }
        else if(traits.mode == AddressModes::ABSX) {
            outs << "Absolute X";
        }
        else if(traits.mode == AddressModes::ABSY){
            outs << "Absolute Y";
        }
        else if(traits.mode == AddressModes::INDIRECT_X){
            outs << "Indirect X";
        }
        else if(traits.mode == AddressModes::INDIRECT_Y){
            outs << "Indirect Y";
        }
        else{
            outs << "Address mode not found!";
        }
        outs << "]---------\n";
        outs << "OpCode: " << reinterpret_cast<void *>(traits.opcode) << '\n';
        outs << "Bytes: " << traits.bytes << '\n';
        outs << "Cycles: " << traits.cycles;
        return outs;
    }

    // Should be false if any of the followings false
    // Because we want to use this for checking if they have been initialized correctly, during setting up the emulator.
    bool operator==(const InstructionTraits& other) const {
        // return ((type != other.type) || (mode != other.mode) || (bytes != other.bytes) || (cycles != other.cycles));
        if(type != other.type) return false;
        if(mode != other.mode) return false;
        if(bytes != other.bytes) return false;
        if(cycles != other.cycles) return false;
        return true;
    }

    RegisterTypes type;
    AddressModes mode;
    opcode_t opcode;
    int bytes;
    int cycles;

};

struct InstructionStatus{
    Byte N : 1; //  Negative
    Byte Z : 1; // Overflow
    Byte C : 1; // Carry
    Byte I : 1; // Interrupt (IQR disable)
    Byte D : 1; // Decimal (use BCD for arithmetics)
    Byte V : 1; // Overflow
};