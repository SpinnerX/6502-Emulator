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

void checkingLDAInstructionCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0xA9>();
    BaseRegister* reg2 = cpu.decode<0xA5>();
    BaseRegister* reg3 = cpu.decode<0xB5>();
    BaseRegister* reg4 = cpu.decode<0xAD>();
    BaseRegister* reg5 = cpu.decode<0xBD>();
    BaseRegister* reg6 = cpu.decode<0xB9>();
    BaseRegister* reg7 = cpu.decode<0xA1>();
    BaseRegister* reg8 = cpu.decode<0xB1>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::LDA, AddressModes::IMMEDIATE, 0xA9, 2, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::LDA, AddressModes::ZPG, 0xA5, 2, 3);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::LDA, AddressModes::ZPG_X, 0xB5, 2, 4);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::LDA, AddressModes::ABS, 0xAD, 3, 4);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::LDA, AddressModes::ABSX, 0xBD, 3, 4);
    RegisterTraits traitsMock6 = RegisterTraits(RegisterTypes::LDA, AddressModes::ABSY, 0xB9, 3, 4);
    RegisterTraits traitsMock7 = RegisterTraits(RegisterTypes::LDA, AddressModes::INDIRECT_X, 0xA1, 2, 6);
    RegisterTraits traitsMock8 = RegisterTraits(RegisterTypes::LDA, AddressModes::INDIRECT_Y, 0xB1, 2, 5);

    RegisterTraits actualTrait1 = reg1->data();
    RegisterTraits actualTrait2 = reg2->data();
    RegisterTraits actualTrait3 = reg3->data();
    RegisterTraits actualTrait4 = reg4->data();
    RegisterTraits actualTrait5 = reg5->data();
    RegisterTraits actualTrait6 = reg6->data();
    RegisterTraits actualTrait7 = reg7->data();
    RegisterTraits actualTrait8 = reg8->data();

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

void checkLDXInstructionCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0xA2>();
    BaseRegister* reg2 = cpu.decode<0xA6>();
    BaseRegister* reg3 = cpu.decode<0xB6>();
    BaseRegister* reg4 = cpu.decode<0xAE>();
    BaseRegister* reg5 = cpu.decode<0xBE>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::LDX, AddressModes::IMMEDIATE, 0xA2, 2, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::LDX, AddressModes::ZPG, 0xA6, 2, 3);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::LDX, AddressModes::ZPG_Y, 0xB6, 2, 4);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::LDX, AddressModes::ABS, 0xAE, 3, 4);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::LDX, AddressModes::ABSY, 0xBE, 3, 4);

    RegisterTraits actualTrait1 = reg1->data();
    RegisterTraits actualTrait2 = reg2->data();
    RegisterTraits actualTrait3 = reg3->data();
    RegisterTraits actualTrait4 = reg4->data();
    RegisterTraits actualTrait5 = reg5->data();


    "LDX_Register_Init_Test"_test = [&]{
        expect(actualTrait1 == traitsMock1);
        expect(actualTrait2 == traitsMock2);
        expect(actualTrait3 == traitsMock3);
        expect(actualTrait4 == traitsMock4);
        expect(actualTrait5 == traitsMock5);
    };
}


void checkLDYInstructionCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0xA0>();
    BaseRegister* reg2 = cpu.decode<0xA4>();
    BaseRegister* reg3 = cpu.decode<0xB4>();
    BaseRegister* reg4 = cpu.decode<0xAC>();
    BaseRegister* reg5 = cpu.decode<0xBC>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::LDY, AddressModes::IMMEDIATE, 0xA0, 2, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::LDY, AddressModes::ZPG, 0xA4, 2, 3);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::LDY, AddressModes::ZPG_X, 0xB4, 2, 4);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::LDY, AddressModes::ABS, 0xAC, 3, 4);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::LDY, AddressModes::ABSX, 0xBC, 3, 4);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();

    "LDY_Register_Init_Test"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
    };
}

void checkingSTAInstructionCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0x85>();
    BaseRegister* reg2 = cpu.decode<0x95>();
    BaseRegister* reg3 = cpu.decode<0x8D>();
    BaseRegister* reg4 = cpu.decode<0x9D>();
    BaseRegister* reg5 = cpu.decode<0x99>();
    BaseRegister* reg6 = cpu.decode<0x81>();
    BaseRegister* reg7 = cpu.decode<0x91>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::STA, AddressModes::ZPG, 0x85, 2, 3);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::STA, AddressModes::ZPG_X, 0x95, 2, 4);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::STA, AddressModes::ABS, 0x8D, 3, 4);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::STA, AddressModes::ABSX, 0x9D, 3, 5);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::STA, AddressModes::ABSY, 0x99, 3, 5);
    RegisterTraits traitsMock6 = RegisterTraits(RegisterTypes::STA, AddressModes::INDIRECT_X, 0x81, 2, 6);
    RegisterTraits traitsMock7 = RegisterTraits(RegisterTypes::STA, AddressModes::INDIRECT_Y, 0x91, 2, 6);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();
    RegisterTraits actualTraits6 = reg6->data();
    RegisterTraits actualTraits7 = reg7->data();


    "STA_Register_Init_Test"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
        expect(actualTraits6 == traitsMock6);
        expect(actualTraits7 == traitsMock7);
    };
    

}

void checkingSTXInstructionCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0x86>();
    BaseRegister* reg2 = cpu.decode<0x96>();
    BaseRegister* reg3 = cpu.decode<0x8E>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::STX, AddressModes::ZPG, 0x86, 2, 3);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::STX, AddressModes::ZPG_Y, 0x96, 2, 4);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::STX, AddressModes::ABS, 0x8E, 3, 4);


    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();

    "STX_Register_Init_Test"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
    };
}


void checkingSTYInstructionCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0x84>();
    BaseRegister* reg2 = cpu.decode<0x94>();
    BaseRegister* reg3 = cpu.decode<0x8C>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::STY, AddressModes::ZPG, 0x84, 2, 3);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::STY, AddressModes::ZPG_X, 0x94, 2, 4);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::STY, AddressModes::ABS, 0x8C, 3, 4);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();

    "STY_Register_Init_Test"_test  = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
    };
}

void checking_TransferInstructions_CorrectnessInit(CPU& cpu){
    // Since these transfer registers only have one address mode corresponding with thhem
    // then we will contain thhem under one unit test case
    BaseRegister* reg1 = cpu.decode<0xAA>(); // TAX
    BaseRegister* reg2 = cpu.decode<0xA8>(); // TAY
    BaseRegister* reg3 = cpu.decode<0xBA>(); // TSX
    BaseRegister* reg4 = cpu.decode<0x8A>(); // TXA
    BaseRegister* reg5 = cpu.decode<0x9A>(); // TXS
    BaseRegister* reg6 = cpu.decode<0x98>(); // TYA

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::TAX, AddressModes::IMPLIED, 0xAA, 1, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::TAY, AddressModes::IMPLIED, 0xA8, 1, 2);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::TSX, AddressModes::IMPLIED, 0xBA, 1, 2);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::TXA, AddressModes::IMPLIED, 0x8A, 1, 2);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::TXS, AddressModes::IMPLIED, 0x9A, 1, 2);
    RegisterTraits traitsMock6 = RegisterTraits(RegisterTypes::TYA, AddressModes::IMPLIED, 0x98, 1, 2);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();
    RegisterTraits actualTraits6 = reg6->data();


    "Transfer_Registers_Init_Test"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock3);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
        expect(actualTraits6 == traitsMock6);
    };
}

/*
void checkLSRInstructionCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0x4A>();
    BaseRegister* reg2 = cpu.decode<0x46>();
    BaseRegister* reg3 = cpu.decode<0x56>();
    BaseRegister* reg4 = cpu.decode<0x4E>();
    BaseRegister* reg5 = cpu.decode<0x5E>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::LSR, AddressModes::A, 0x4A, 1, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::LSR, AddressModes::ZPG, 0x46, 2, 5);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::LSR, AddressModes::ZPG_X, 0x56, 2, 6);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::LSR, AddressModes::ABS, 0x4E, 3, 6);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::LSR, AddressModes::ABSX, 0x5E, 3, 7);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();

    
    "LSR_Register_Init_Test"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
    };

}
*/

int main() {
    CPU cpu;

    checkingLDAInstructionCorrectnessInit(cpu);
    checkLDXInstructionCorrectnessInit(cpu);
    checkLDYInstructionCorrectnessInit(cpu);
    checkingSTAInstructionCorrectnessInit(cpu);
    checkingSTXInstructionCorrectnessInit(cpu);
    checkingSTYInstructionCorrectnessInit(cpu);
    checking_TransferInstructions_CorrectnessInit(cpu);
    // checkLSRInstructionCorrectnessInit(cpu);
}