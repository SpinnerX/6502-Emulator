#include <iostream>
#include "boost/ut.hpp"
#include <core/CPU.h>
using namespace std;
using namespace boost::ut;

/**
 * 
 * Creating test cases
 * 
 * 
 * 
*/

void checkingLDAInstructionCorrectness(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0xA9>();
    BaseRegister* reg2 = cpu.decode<0xA5>();
    BaseRegister* reg3 = cpu.decode<0xB5>();
    BaseRegister* reg4 = cpu.decode<0xAD>();
    BaseRegister* reg5 = cpu.decode<0xBD>();
    BaseRegister* reg6 = cpu.decode<0xB9>();
    BaseRegister* reg7 = cpu.decode<0xA1>();
    BaseRegister* reg8 = cpu.decode<0xB1>();

    InstructionTraits traitsMock1 = InstructionTraits(RegisterTypes::LDA, AddressModes::IMMEDIATE, 0xA9, 2, 2);
    InstructionTraits traitsMock2 = InstructionTraits(RegisterTypes::LDA, AddressModes::ZPG, 0xA5, 2, 3);
    InstructionTraits traitsMock3 = InstructionTraits(RegisterTypes::LDA, AddressModes::ZPG_X, 0xB5, 2, 4);
    InstructionTraits traitsMock4 = InstructionTraits(RegisterTypes::LDA, AddressModes::ABS, 0xAD, 3, 4);
    InstructionTraits traitsMock5 = InstructionTraits(RegisterTypes::LDA, AddressModes::ABSX, 0xBD, 3, 4);
    InstructionTraits traitsMock6 = InstructionTraits(RegisterTypes::LDA, AddressModes::ABSY, 0xB9, 3, 4);
    InstructionTraits traitsMock7 = InstructionTraits(RegisterTypes::LDA, AddressModes::INDIRECT_X, 0xA1, 2, 6);
    InstructionTraits traitsMock8 = InstructionTraits(RegisterTypes::LDA, AddressModes::INDIRECT_Y, 0xB1, 2, 5);

    InstructionTraits actualTrait1 = reg1->data();
    InstructionTraits actualTrait2 = reg2->data();
    InstructionTraits actualTrait3 = reg3->data();
    InstructionTraits actualTrait4 = reg4->data();
    InstructionTraits actualTrait5 = reg5->data();
    InstructionTraits actualTrait6 = reg6->data();
    InstructionTraits actualTrait7 = reg7->data();
    InstructionTraits actualTrait8 = reg8->data();

    /**
     * 
     * Test case making sure that these registers data are set correctly, and test for any incorrection.
     * 
    */
    "LDA_Register_Init_Test"_test = [&] {
        expect(actualTrait1 == traitsMock1);
        expect(actualTrait2 == traitsMock2);
        expect(actualTrait3 == traitsMock3);
        expect(actualTrait4 == traitsMock4);
        expect(actualTrait5 == traitsMock5);
        expect(actualTrait6 == traitsMock6);
        expect(actualTrait7 == traitsMock7);
        expect(actualTrait8 == traitsMock8);
        

    };
}

void checkLDXInstructionCorrectness(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0xA2>();
    BaseRegister* reg2 = cpu.decode<0xA6>();

    InstructionTraits traitsMock1 = InstructionTraits(RegisterTypes::LDX, AddressModes::IMMEDIATE, 0xA2, 2, 2);
    InstructionTraits traitsMock2 = InstructionTraits(RegisterTypes::LDX, AddressModes::ZPG, 0xA6, 2, 3);

    InstructionTraits actualTrait1 = reg1->data();
    InstructionTraits actualTrait2 = reg2->data();


    "LDA_Register_Init_Test"_test = [&]{
        expect(actualTrait1 == traitsMock1);
        expect(actualTrait2 == traitsMock2);
    };
}


int main() {
    CPU cpu;

    checkingLDAInstructionCorrectness(cpu);
    checkLDXInstructionCorrectness(cpu);
}