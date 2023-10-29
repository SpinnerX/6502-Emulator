#pragma once
#include "boost/ut.hpp"
#include <core/CPU.h>
#include <exception>
#include <stdexcept>

using namespace std;
using namespace boost::ut;

/**
 * 
 * Idea (for having a script generate test cases for initializing test cases)
 * 
*/

/**
 * 
 * @brief
 * 
 * Testing for Initialized Registers
 * - Testing if lookup table is able to retreive all the registers
 * - Test to extract registers extracted based on the opcode using the decode<opcode_t> function
 * - Checks if the registers all have the right data set into their instances
 * - Checks for correctness in those set values.
 * 
 * 
*/

/** These are test cases for Transfer Instructions such as Loading, Storing, and Interregister transfers. **/
void checking_LDA_InstructionCorrectnessInit(CPU& cpu){
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

void check_LDX_InstructionCorrectnessInit(CPU& cpu){
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


void check_LDY_InstructionCorrectnessInit(CPU& cpu){
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

void checking_STA_InstructionCorrectnessInit(CPU& cpu){
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

void checking_STX_InstructionCorrectnessInit(CPU& cpu){
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

void checking_STY_InstructionCorrectnessInit(CPU& cpu){
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
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
        expect(actualTraits6 == traitsMock6);
    };
}

/** These are test cases for Stack Instructions **/

void check_StackInstructions_CorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0x48>();
    BaseRegister* reg2 = cpu.decode<0x08>();
    BaseRegister* reg3 = cpu.decode<0x68>();
    BaseRegister* reg4 = cpu.decode<0x28>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::PHA, AddressModes::IMPLIED, 0x48, 1, 3);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::PHP, AddressModes::IMPLIED, 0x08, 1, 3);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::PLA, AddressModes::IMPLIED, 0x68, 1, 4);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::PLP, AddressModes::IMPLIED, 0x28, 1, 4);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();



    "Stack_Registers_Init_Test"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
    };
}

void check_DecrementIncrement_InstructionCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0xE6>();
    BaseRegister* reg2 = cpu.decode<0xF6>();
    BaseRegister* reg3 = cpu.decode<0xEE>();
    BaseRegister* reg4 = cpu.decode<0xFE>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::INC, AddressModes::ZPG, 0xE6, 2, 5);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::INC, AddressModes::ZPG_X, 0xF6, 2, 6);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::INC, AddressModes::ABS, 0xEE, 3, 6);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::INC, AddressModes::ABSX, 0xFE, 3, 7);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();



    BaseRegister* reg5 = cpu.decode<0xE8>();
    BaseRegister* reg6 = cpu.decode<0xC8>();

    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::INX, AddressModes::IMPLIED, 0xE8, 1, 2);
    RegisterTraits traitsMock6 = RegisterTraits(RegisterTypes::INY, AddressModes::IMPLIED, 0xC8, 1, 2);

    RegisterTraits actualTraits5 = reg5->data();
    RegisterTraits actualTraits6 = reg6->data();




    "Increment_and_Decrement_Test_Init"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);

        expect(actualTraits5 == traitsMock5);
        expect(actualTraits6 == traitsMock6);

    };
}


void check_ADC_ArtihmeticOperations1_InstructionsCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0x69>();
    BaseRegister* reg2 = cpu.decode<0x65>();
    BaseRegister* reg3 = cpu.decode<0x75>();
    BaseRegister* reg4 = cpu.decode<0x6D>();
    BaseRegister* reg5 = cpu.decode<0x7D>();
    BaseRegister* reg6 = cpu.decode<0x79>();
    BaseRegister* reg7 = cpu.decode<0x61>();
    BaseRegister* reg8 = cpu.decode<0x71>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::ADC, AddressModes::IMMEDIATE, 0x69, 2, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::ADC, AddressModes::ZPG, 0x65, 2, 3);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::ADC, AddressModes::ZPG_X, 0x75, 2, 4);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::ADC, AddressModes::ABS, 0x6D, 3, 4);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::ADC, AddressModes::ABSX, 0x7D, 3, 4);
    RegisterTraits traitsMock6 = RegisterTraits(RegisterTypes::ADC, AddressModes::ABSY, 0x79, 3, 4);
    RegisterTraits traitsMock7 = RegisterTraits(RegisterTypes::ADC, AddressModes::INDIRECT_X, 0x61, 2, 6);
    RegisterTraits traitsMock8 = RegisterTraits(RegisterTypes::ADC, AddressModes::INDIRECT_Y, 0x71, 2, 5);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();
    RegisterTraits actualTraits6 = reg6->data();
    RegisterTraits actualTraits7 = reg7->data();
    RegisterTraits actualTraits8 = reg8->data();

    "ADC_ArithhmeticOperationsTests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
        expect(actualTraits6 == traitsMock6);
        expect(actualTraits7 == traitsMock7);
        expect(actualTraits8 == traitsMock8);
    };
}

void check_SBC_ArtihmeticOperations2_InstructionsCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0xE9>();
    BaseRegister* reg2 = cpu.decode<0xE5>();
    BaseRegister* reg3 = cpu.decode<0xF5>();
    BaseRegister* reg4 = cpu.decode<0xED>();
    BaseRegister* reg5 = cpu.decode<0xFD>();
    BaseRegister* reg6 = cpu.decode<0xF9>();
    BaseRegister* reg7 = cpu.decode<0xE1>();
    BaseRegister* reg8 = cpu.decode<0xF1>();


    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::SBC, AddressModes::IMMEDIATE, 0xE9, 2, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::SBC, AddressModes::ZPG, 0xE5, 2, 3);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::SBC, AddressModes::ZPG_X, 0xF5, 2, 4);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::SBC, AddressModes::ABS, 0xED, 3, 4);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::SBC, AddressModes::ABSX, 0xFD, 3, 4);
    RegisterTraits traitsMock6 = RegisterTraits(RegisterTypes::SBC, AddressModes::ABSY, 0xF9, 3, 4);
    RegisterTraits traitsMock7 = RegisterTraits(RegisterTypes::SBC, AddressModes::INDIRECT_X, 0xE1, 2, 6);
    RegisterTraits traitsMock8 = RegisterTraits(RegisterTypes::SBC, AddressModes::INDIRECT_Y, 0xF1, 2, 5);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();
    RegisterTraits actualTraits6 = reg6->data();
    RegisterTraits actualTraits7 = reg7->data();
    RegisterTraits actualTraits8 = reg8->data();

    "ADC_ArithhmeticOperationsTests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
        expect(actualTraits6 == traitsMock6);
        expect(actualTraits7 == traitsMock7);
        expect(actualTraits8 == traitsMock8);
    };
}

void check_AND_LogicalOperations_InstructionsCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0x29>();
    BaseRegister* reg2 = cpu.decode<0x25>();
    BaseRegister* reg3 = cpu.decode<0x35>();
    BaseRegister* reg4 = cpu.decode<0x2D>();
    BaseRegister* reg5 = cpu.decode<0x3D>();
    BaseRegister* reg6 = cpu.decode<0x39>();
    BaseRegister* reg7 = cpu.decode<0x21>();
    BaseRegister* reg8 = cpu.decode<0x31>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::AND, AddressModes::IMMEDIATE, 0x29, 2, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::AND, AddressModes::ZPG, 0x25, 2, 3);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::AND, AddressModes::ZPG_X, 0x35, 2, 4);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::AND, AddressModes::ABS, 0x2D, 3, 4);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::AND, AddressModes::ABSX, 0x3D, 3, 4);
    RegisterTraits traitsMock6 = RegisterTraits(RegisterTypes::AND, AddressModes::ABSY, 0x39, 3, 4);
    RegisterTraits traitsMock7 = RegisterTraits(RegisterTypes::AND, AddressModes::INDIRECT_X, 0x21, 2, 6);
    RegisterTraits traitsMock8 = RegisterTraits(RegisterTypes::AND, AddressModes::INDIRECT_Y, 0x31, 2, 5);


    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();
    RegisterTraits actualTraits6 = reg6->data();
    RegisterTraits actualTraits7 = reg7->data();
    RegisterTraits actualTraits8 = reg8->data();


    "AND_LogicalOperationsTests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
        expect(actualTraits6 == traitsMock6);
        expect(actualTraits7 == traitsMock7);
        expect(actualTraits8 == traitsMock8);
    };

}

void check_EOR_LogicalOperations_InstructionsCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0x49>();
    BaseRegister* reg2 = cpu.decode<0x45>();
    BaseRegister* reg3 = cpu.decode<0x55>();
    BaseRegister* reg4 = cpu.decode<0x4D>();
    BaseRegister* reg5 = cpu.decode<0x5D>();
    BaseRegister* reg6 = cpu.decode<0x59>();
    BaseRegister* reg7 = cpu.decode<0x41>();
    BaseRegister* reg8 = cpu.decode<0x51>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::EOR, AddressModes::IMMEDIATE, 0x49, 2, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::EOR, AddressModes::ZPG, 0x45, 2, 3);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::EOR, AddressModes::ZPG_X, 0x55, 2, 4);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::EOR, AddressModes::ABS, 0x4D, 3, 4);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::EOR, AddressModes::ABSX, 0x5D, 3, 4);
    RegisterTraits traitsMock6 = RegisterTraits(RegisterTypes::EOR, AddressModes::ABSY, 0x59, 3, 4);
    RegisterTraits traitsMock7 = RegisterTraits(RegisterTypes::EOR, AddressModes::INDIRECT_X, 0x41, 2, 6);
    RegisterTraits traitsMock8 = RegisterTraits(RegisterTypes::EOR, AddressModes::INDIRECT_Y, 0x41, 2, 5);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();
    RegisterTraits actualTraits6 = reg6->data();
    RegisterTraits actualTraits7 = reg7->data();
    RegisterTraits actualTraits8 = reg8->data();

    "EOR_LogicalOperationsTests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
        expect(actualTraits6 == traitsMock6);
        expect(actualTraits7 == traitsMock7);
        expect(actualTraits8 == traitsMock8);
    };

}

void check_ORA_LogicalOperations_InstructionsCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0x09>();
    BaseRegister* reg2 = cpu.decode<0x05>();
    BaseRegister* reg3 = cpu.decode<0x15>();
    BaseRegister* reg4 = cpu.decode<0x0D>();
    BaseRegister* reg5 = cpu.decode<0x1D>();
    BaseRegister* reg6 = cpu.decode<0x19>();
    BaseRegister* reg7 = cpu.decode<0x01>();
    BaseRegister* reg8 = cpu.decode<0x11>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::ORA, AddressModes::IMMEDIATE, 0x09, 2, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::ORA, AddressModes::ZPG, 0x05, 2, 3);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::ORA, AddressModes::ZPG_X, 0x15, 2, 4);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::ORA, AddressModes::ABS, 0x0D, 3, 4);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::ORA, AddressModes::ABSX, 0x1D, 3, 4);
    RegisterTraits traitsMock6 = RegisterTraits(RegisterTypes::ORA, AddressModes::ABSY, 0x19, 3, 4);
    RegisterTraits traitsMock7 = RegisterTraits(RegisterTypes::ORA, AddressModes::INDIRECT_X, 0x01, 2, 6);
    RegisterTraits traitsMock8 = RegisterTraits(RegisterTypes::ORA, AddressModes::INDIRECT_Y, 0x01, 2, 5);


    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();
    RegisterTraits actualTraits6 = reg6->data();
    RegisterTraits actualTraits7 = reg7->data();
    RegisterTraits actualTraits8 = reg8->data();

    "EOR_LogicalOperationsTests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
        expect(actualTraits6 == traitsMock6);
        expect(actualTraits7 == traitsMock7);
        expect(actualTraits8 == traitsMock8);
    };
}

void check_ASL_LogicalOperations_InstructionsCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0x0A>();
    BaseRegister* reg2 = cpu.decode<0x06>();
    BaseRegister* reg3 = cpu.decode<0x16>();
    BaseRegister* reg4 = cpu.decode<0x0E>();
    BaseRegister* reg5 = cpu.decode<0x1E>();


    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::ASL, AddressModes::A, 0x0A, 1, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::ASL, AddressModes::ZPG, 0x06, 2, 5);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::ASL, AddressModes::ZPG_X, 0x16, 2, 6);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::ASL, AddressModes::ABS, 0x0E, 3, 6);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::ASL, AddressModes::ABSX, 0x1E, 3, 7);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();

    "ASL_ShiftOperationsTests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
    };
}

void check_LSR_InstructionCorrectnessInit(CPU& cpu){
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

    
    "LSR_ShiftOperationsTests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
    };

}

void check_ROL_InstructionCorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0x2A>();
    BaseRegister* reg2 = cpu.decode<0x26>();
    BaseRegister* reg3 = cpu.decode<0x36>();
    BaseRegister* reg4 = cpu.decode<0x2E>();
    BaseRegister* reg5 = cpu.decode<0x3E>();


    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::ROL, AddressModes::A, 0x2A, 1, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::ROL, AddressModes::ZPG, 0x26, 2, 5);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::ROL, AddressModes::ZPG_X, 0x36, 2, 6);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::ROL, AddressModes::ABS, 0x2E, 3, 6);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::ROL, AddressModes::ABSX, 0x3E, 3, 7);


    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();


    "ROL_ShiftOperationsTests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
    };
}

void check_ROR_InstructionCorrectnessInit(CPU& cpu){
    
    BaseRegister* reg1 = cpu.decode<0x6A>();
    BaseRegister* reg2 = cpu.decode<0x66>();
    BaseRegister* reg3 = cpu.decode<0x76>();
    BaseRegister* reg4 = cpu.decode<0x6E>();
    BaseRegister* reg5 = cpu.decode<0x7E>();


    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::ROR, AddressModes::A, 0x6A, 1, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::ROR, AddressModes::ZPG, 0x66, 2, 5);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::ROR, AddressModes::ZPG_X, 0x76, 2, 6);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::ROR, AddressModes::ABS, 0x6E, 3, 6);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::ROR, AddressModes::ABSX, 0x7E, 3, 7);


    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();

    "ROR_ShiftOperationsTests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
    };
}


void check_FlagsInstruction_CorrectnessInit(CPU& cpu){
    
    // In this one test case we are testing both instructions since, there are only one address modes each
    // Testing registers, CLC, CLD, CLI, CLV, SEC, SED, SEI

    BaseRegister* reg1 = cpu.decode<0x18>();
    BaseRegister* reg2 = cpu.decode<0xD8>();
    BaseRegister* reg3 = cpu.decode<0x58>();
    BaseRegister* reg4 = cpu.decode<0xB8>();
    BaseRegister* reg5 = cpu.decode<0x38>();
    BaseRegister* reg6 = cpu.decode<0xF8>();
    BaseRegister* reg7 = cpu.decode<0x78>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::CLC, AddressModes::IMPLIED, 0x18, 1, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::CLD, AddressModes::IMPLIED, 0xD8, 1, 2);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::CLI, AddressModes::IMPLIED, 0x58, 1, 2);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::CLV, AddressModes::IMPLIED, 0xB8, 1, 2);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::SEC, AddressModes::IMPLIED, 0x38, 1, 2);
    RegisterTraits traitsMock6 = RegisterTraits(RegisterTypes::SED, AddressModes::IMPLIED, 0xF8, 1, 2);
    RegisterTraits traitsMock7 = RegisterTraits(RegisterTypes::SEI, AddressModes::IMPLIED, 0x78, 1, 2);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();
    RegisterTraits actualTraits6 = reg6->data();
    RegisterTraits actualTraits7 = reg7->data();



    "FlagInstructions_Tests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
        expect(actualTraits6 == traitsMock6);
        expect(actualTraits7 == traitsMock7);
    };
}

void check_CMP_Instruction_CorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0xC9>();
    BaseRegister* reg2 = cpu.decode<0xC5>();
    BaseRegister* reg3 = cpu.decode<0xD5>();
    BaseRegister* reg4 = cpu.decode<0xCD>();
    BaseRegister* reg5 = cpu.decode<0xDD>();
    BaseRegister* reg6 = cpu.decode<0xD9>();
    BaseRegister* reg7 = cpu.decode<0xC1>();
    BaseRegister* reg8 = cpu.decode<0xD1>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::CMP, AddressModes::IMMEDIATE, 0xC9, 2, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::CMP, AddressModes::ZPG, 0xC5, 2, 3);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::CMP, AddressModes::ZPG_X, 0xD5, 2, 4);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::CMP, AddressModes::ABS, 0xCD, 3, 4);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::CMP, AddressModes::ABSX, 0xDD, 3, 4);
    RegisterTraits traitsMock6 = RegisterTraits(RegisterTypes::CMP, AddressModes::ABSY, 0xD9, 3, 4);
    RegisterTraits traitsMock7 = RegisterTraits(RegisterTypes::CMP, AddressModes::INDIRECT_X, 0xC1, 2, 6);
    RegisterTraits traitsMock8 = RegisterTraits(RegisterTypes::CMP, AddressModes::INDIRECT_Y, 0xD1, 2, 5);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();
    RegisterTraits actualTraits6 = reg6->data();
    RegisterTraits actualTraits7 = reg7->data();
    RegisterTraits actualTraits8 = reg8->data();


    "CMP_Instructions_Tests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
        expect(actualTraits6 == traitsMock6);
        expect(actualTraits7 == traitsMock7);
        expect(actualTraits8 == traitsMock8);
    };
}

void check_CPX_Instruction_CorrectnessInit(CPU& cpu){

    BaseRegister* reg1 = cpu.decode<0xE0>();
    BaseRegister* reg2 = cpu.decode<0xE4>();
    BaseRegister* reg3 = cpu.decode<0xEC>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::CPX, AddressModes::IMMEDIATE, 0xE0, 2, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::CPX, AddressModes::ZPG, 0xE4, 2, 3);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::CPX, AddressModes::ABS, 0xEC, 3, 4);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();

    "CPX_Instructions_Tests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
    };
}

void check_CPY_Instruction_CorrectnessInit(CPU& cpu){

    BaseRegister* reg1 = cpu.decode<0xC0>();
    BaseRegister* reg2 = cpu.decode<0xC4>();
    BaseRegister* reg3 = cpu.decode<0xCC>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::CPY, AddressModes::IMMEDIATE, 0xC0, 2, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::CPY, AddressModes::ZPG, 0xC4, 2, 3);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::CPY, AddressModes::ABS, 0xCC, 3, 4);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();

    "CPX_Instructions_Tests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
    };
}

void check_ConditionalBranch_Instruction_CorrectnessInit(CPU& cpu){
    // Testing all branch registers under one test case, since they only have one address mode
    // Address Mode: RELATIVE
    BaseRegister* reg1 = cpu.decode<0x90>();
    BaseRegister* reg2 = cpu.decode<0xB0>();
    BaseRegister* reg3 = cpu.decode<0xF0>();
    BaseRegister* reg4 = cpu.decode<0x30>();
    BaseRegister* reg5 = cpu.decode<0xD0>();
    BaseRegister* reg6 = cpu.decode<0x10>();
    BaseRegister* reg7 = cpu.decode<0x50>();
    BaseRegister* reg8 = cpu.decode<0x70>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::BCC, AddressModes::RELATIVE, 0x90, 2, 2);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::BCS, AddressModes::RELATIVE, 0xB0, 2, 2);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::BEQ, AddressModes::RELATIVE, 0xF0, 2, 2);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::BMI, AddressModes::RELATIVE, 0x30, 2, 2);
    RegisterTraits traitsMock5 = RegisterTraits(RegisterTypes::BNE, AddressModes::RELATIVE, 0xD0, 2, 2);
    RegisterTraits traitsMock6 = RegisterTraits(RegisterTypes::BPL, AddressModes::RELATIVE, 0x10, 2, 2);
    RegisterTraits traitsMock7 = RegisterTraits(RegisterTypes::BVC, AddressModes::RELATIVE, 0x50, 2, 2);
    RegisterTraits traitsMock8 = RegisterTraits(RegisterTypes::BVS, AddressModes::RELATIVE, 0x70, 2, 2);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();
    RegisterTraits actualTraits5 = reg5->data();
    RegisterTraits actualTraits6 = reg6->data();
    RegisterTraits actualTraits7 = reg7->data();
    RegisterTraits actualTraits8 = reg8->data();

    "ConditionalBranch_Instructions_Tests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
        expect(actualTraits5 == traitsMock5);
        expect(actualTraits6 == traitsMock6);
        expect(actualTraits7 == traitsMock7);
        expect(actualTraits8 == traitsMock8);
    };
}

void check_JumpsAndSubroutines_Instruction_CorrectnessInit(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0x4C>();
    BaseRegister* reg2 = cpu.decode<0x6C>();
    BaseRegister* reg3 = cpu.decode<0x20>();
    BaseRegister* reg4 = cpu.decode<0x60>();
    
    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::JMP, AddressModes::ABS, 0x4C, 3, 3);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::JMP, AddressModes::INDIRECT, 0x6C, 3, 5);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::JSR, AddressModes::ABS, 0x20, 3, 6);
    RegisterTraits traitsMock4 = RegisterTraits(RegisterTypes::RTS, AddressModes::IMPLIED, 0x60, 1, 6);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();
    RegisterTraits actualTraits4 = reg4->data();

    "JumpsAndSubroutines_Instructions_Tests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);
    };
}

void check_OtherInstructions_Init(CPU& cpu){
    BaseRegister* reg1 = cpu.decode<0x24>();
    BaseRegister* reg2 = cpu.decode<0x2C>();
    BaseRegister* reg3 = cpu.decode<0xEA>();

    RegisterTraits traitsMock1 = RegisterTraits(RegisterTypes::BIT, AddressModes::ZPG, 0x24, 2, 3);
    RegisterTraits traitsMock2 = RegisterTraits(RegisterTypes::BIT, AddressModes::ABS, 0x24, 3, 4);
    RegisterTraits traitsMock3 = RegisterTraits(RegisterTypes::NOP, AddressModes::IMPLIED, 0x2C, 1, 2);

    RegisterTraits actualTraits1 = reg1->data();
    RegisterTraits actualTraits2 = reg2->data();
    RegisterTraits actualTraits3 = reg3->data();


    "JumpsAndSubroutines_Instructions_Tests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(actualTraits3 == traitsMock3);
    };
}

/*
* Running registers, checking if the data corresponding to their opcodes are set correctly
* This is assurance thhat thhese registers when we emulate the decoding process
*   we can extract those registers based on their opcodes, and at least be confident the registers
*   informations are correctly through these test cases here.
*/

void runRegistersInitializedTestsInit(CPU& cpu) {
    checking_LDA_InstructionCorrectnessInit(cpu);
    check_LDX_InstructionCorrectnessInit(cpu);
    check_LDY_InstructionCorrectnessInit(cpu);
    checking_STA_InstructionCorrectnessInit(cpu);
    checking_STX_InstructionCorrectnessInit(cpu);
    checking_STY_InstructionCorrectnessInit(cpu);
    checking_TransferInstructions_CorrectnessInit(cpu);
    check_StackInstructions_CorrectnessInit(cpu);
    check_DecrementIncrement_InstructionCorrectnessInit(cpu);
    check_ADC_ArtihmeticOperations1_InstructionsCorrectnessInit(cpu);
    check_SBC_ArtihmeticOperations2_InstructionsCorrectnessInit(cpu);
    check_AND_LogicalOperations_InstructionsCorrectnessInit(cpu);
    check_EOR_LogicalOperations_InstructionsCorrectnessInit(cpu);
    check_ORA_LogicalOperations_InstructionsCorrectnessInit(cpu);
    check_ASL_LogicalOperations_InstructionsCorrectnessInit(cpu);
    check_LSR_InstructionCorrectnessInit(cpu);
    check_ROL_InstructionCorrectnessInit(cpu);
    check_ROR_InstructionCorrectnessInit(cpu);
    check_FlagsInstruction_CorrectnessInit(cpu);
    check_CMP_Instruction_CorrectnessInit(cpu);
    check_CPX_Instruction_CorrectnessInit(cpu);
    check_ConditionalBranch_Instruction_CorrectnessInit(cpu);
    check_JumpsAndSubroutines_Instruction_CorrectnessInit(cpu);
    check_OtherInstructions_Init(cpu);

}