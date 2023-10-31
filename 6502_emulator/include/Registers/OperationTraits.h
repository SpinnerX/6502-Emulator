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
struct OperationTraits{
    OperationTraits() = default;
    OperationTraits(OperationTypes type, AddressModes mode, opcode_t opcode, int bytes, int cycles) : type(type), mode(mode), opcode(opcode), bytes(bytes), cycles(cycles) { }

    friend std::ostream& operator<<(std::ostream& outs, const OperationTraits& traits){
        outs << "\n--------- [";
        switch (traits.type){
        case OperationTypes::ADC:
            outs << "ADC";
            break;
        case OperationTypes::AND:
            outs << "AND";
            break;
        case OperationTypes::ASL:
            outs << "ASL";
            break;
        case OperationTypes::BCC:
            outs << "BCC";
            break;
        case OperationTypes::BCS:
            outs << "BCS";
            break;
        case OperationTypes::BEQ:
            outs << "BEQ";
            break;
        case OperationTypes::BIT:
            outs << "BIT";
            break;
        case OperationTypes::BMI:
            outs << "BMI";
            break;
        case OperationTypes::BNE:
            outs << "BNE";
            break;
        case OperationTypes::BPL:
            outs << "BPL";
            break;
        case OperationTypes::BRK:
            outs << "BRK";
            break;
        case OperationTypes::BVC:
            outs << "BVC";
            break;
        case OperationTypes::BVS:
            outs << "BVS";
            break;
        case OperationTypes::CLC:
            outs << "CLC";
            break;
        case OperationTypes::CLD:
            outs << "CLD";
            break;
        case OperationTypes::CLV:
            outs << "CLV";
            break;
        case OperationTypes::CMP:
            outs << "CMP";
            break;
        case OperationTypes::CPX:
            outs << "CPX";
            break;
        case OperationTypes::CPY:
            outs << "CPY";
            break;
        case OperationTypes::DEC:
            outs << "DEC";
            break;
        case OperationTypes::DEX:
            outs << "DEX";
            break;
        case OperationTypes::DEY:
            outs << "DEY";
            break;
        case OperationTypes::EOR:
            outs << "EOR";
            break;
        case OperationTypes::INC:
            outs << "INC";
            break;
        case OperationTypes::INX:
            outs << "INX";
            break;
        case OperationTypes::INY:
            outs << "INY";
            break;
        case OperationTypes::JMP:
            outs << "JMP";
            break;
        case OperationTypes::JSR:
            outs << "JSR";
            break;
        case OperationTypes::LDA:
            outs << "LDA";
            break;
        case OperationTypes::LDX:
            outs << "LDX";
            break;
        case OperationTypes::LDY:
            outs << "LDY";
            break;
        case OperationTypes::LSR:
            outs << "LSR";
            break;
        case OperationTypes::NOP:
            outs << "NOP";
            break;
        case OperationTypes::ORA:
            outs << "ORA";
            break;
        case OperationTypes::PHA:
            outs << "PHA";
            break;
        case OperationTypes::PHP:
            outs << "PHP";
            break;
        case OperationTypes::PLA:
            outs << "PLA";
            break;
        case OperationTypes::PLP:
            outs << "PLP";
            break;
        case OperationTypes::ROL:
            outs << "ROL";
            break;
        case OperationTypes::ROR:
            outs << "ROR";
            break;
        case OperationTypes::RTI:
            outs << "RTI";
            break;
        case OperationTypes::RTS:
            outs << "RTS";
            break;
        case OperationTypes::SBC:
            outs << "SBC";
            break;
        case OperationTypes::SEC:
            outs << "SEC";
            break;
        case OperationTypes::SED:
            outs << "SED";
            break;
        case OperationTypes::SEI:
            outs << "SEI";
            break;
        case OperationTypes::STA:
            outs << "STA";
            break;
        case OperationTypes::STX:
            outs << "STX";
            break;
        case OperationTypes::STY:
            outs << "STY";
            break;
        case OperationTypes::TAX:
            outs << "TAX";
            break;
        case OperationTypes::TAY:
            outs << "TAY";
            break;
        case OperationTypes::TSX:
            outs << "TSX";
            break;
        case OperationTypes::TXA:
            outs << "TXA";
            break;
        case OperationTypes::TXS:
            outs << "TXS";
            break;
        case OperationTypes::TYA:
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
        outs << "Cycles: " << traits.cycles << '\n';
        return outs;
    }

    // Should be false if any of the followings false
    // Because we want to use this for checking if they have been initialized correctly, during setting up the emulator.
    bool operator==(const OperationTraits& other) const {
        // return ((type != other.type) || (mode != other.mode) || (bytes != other.bytes) || (cycles != other.cycles));
        if(type != other.type) return false;
        if(mode != other.mode) return false;
        if(bytes != other.bytes) return false;
        if(cycles != other.cycles) return false;
        return true;
    }

    OperationTypes type;
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