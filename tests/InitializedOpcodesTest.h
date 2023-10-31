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
 * 
 * 
 * 
*/

/** These are test cases for Transfer Instructions such as Loading, Storing, and Interregister transfers. **/
void checking_LDA_InstructionCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0xA9>();
    BaseOperation* reg2 = cpu.decode<0xA5>();
    BaseOperation* reg3 = cpu.decode<0xB5>();
    BaseOperation* reg4 = cpu.decode<0xAD>();
    BaseOperation* reg5 = cpu.decode<0xBD>();
    BaseOperation* reg6 = cpu.decode<0xB9>();
    BaseOperation* reg7 = cpu.decode<0xA1>();
    BaseOperation* reg8 = cpu.decode<0xB1>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::LDA, AddressModes::IMMEDIATE, 0xA9, 2, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::LDA, AddressModes::ZPG, 0xA5, 2, 3);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::LDA, AddressModes::ZPG_X, 0xB5, 2, 4);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::LDA, AddressModes::ABS, 0xAD, 3, 4);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::LDA, AddressModes::ABSX, 0xBD, 3, 4);
    OperationTraits traitsMock6 = OperationTraits(OperationTypes::LDA, AddressModes::ABSY, 0xB9, 3, 4);
    OperationTraits traitsMock7 = OperationTraits(OperationTypes::LDA, AddressModes::INDIRECT_X, 0xA1, 2, 6);
    OperationTraits traitsMock8 = OperationTraits(OperationTypes::LDA, AddressModes::INDIRECT_Y, 0xB1, 2, 5);

    OperationTraits actualTrait1 = reg1->data();
    OperationTraits actualTrait2 = reg2->data();
    OperationTraits actualTrait3 = reg3->data();
    OperationTraits actualTrait4 = reg4->data();
    OperationTraits actualTrait5 = reg5->data();
    OperationTraits actualTrait6 = reg6->data();
    OperationTraits actualTrait7 = reg7->data();
    OperationTraits actualTrait8 = reg8->data();

    /**
     * 
     * Test case making sure that these registers data are set correctly, and test for any incorrection.
     * 
    */
    "LDA_Register_Init_Test"_test = [&] {
        expect(that % actualTrait1 == traitsMock1);
        expect(that % actualTrait2 == traitsMock2);
        expect(that % actualTrait3 == traitsMock3);
        expect(that % actualTrait4 == traitsMock4);
        expect(that % actualTrait5 == traitsMock5);
        expect(that % actualTrait6 == traitsMock6);
        expect(that % actualTrait7 == traitsMock7);
        expect(that % actualTrait8 == traitsMock8);
    };
}

void check_LDX_InstructionCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0xA2>();
    BaseOperation* reg2 = cpu.decode<0xA6>();
    BaseOperation* reg3 = cpu.decode<0xB6>();
    BaseOperation* reg4 = cpu.decode<0xAE>();
    BaseOperation* reg5 = cpu.decode<0xBE>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::LDX, AddressModes::IMMEDIATE, 0xA2, 2, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::LDX, AddressModes::ZPG, 0xA6, 2, 3);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::LDX, AddressModes::ZPG_Y, 0xB6, 2, 4);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::LDX, AddressModes::ABS, 0xAE, 3, 4);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::LDX, AddressModes::ABSY, 0xBE, 3, 4);

    OperationTraits actualTrait1 = reg1->data();
    OperationTraits actualTrait2 = reg2->data();
    OperationTraits actualTrait3 = reg3->data();
    OperationTraits actualTrait4 = reg4->data();
    OperationTraits actualTrait5 = reg5->data();


    "LDX_Register_Init_Test"_test = [&]{
        expect(that % actualTrait1 == traitsMock1);
        expect(that % actualTrait2 == traitsMock2);
        expect(that % actualTrait3 == traitsMock3);
        expect(that % actualTrait4 == traitsMock4);
        expect(that % actualTrait5 == traitsMock5);
    };
}


void check_LDY_InstructionCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0xA0>();
    BaseOperation* reg2 = cpu.decode<0xA4>();
    BaseOperation* reg3 = cpu.decode<0xB4>();
    BaseOperation* reg4 = cpu.decode<0xAC>();
    BaseOperation* reg5 = cpu.decode<0xBC>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::LDY, AddressModes::IMMEDIATE, 0xA0, 2, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::LDY, AddressModes::ZPG, 0xA4, 2, 3);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::LDY, AddressModes::ZPG_X, 0xB4, 2, 4);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::LDY, AddressModes::ABS, 0xAC, 3, 4);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::LDY, AddressModes::ABSX, 0xBC, 3, 4);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();

    "LDY_Register_Init_Test"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
    };
}

void checking_STA_InstructionCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0x85>();
    BaseOperation* reg2 = cpu.decode<0x95>();
    BaseOperation* reg3 = cpu.decode<0x8D>();
    BaseOperation* reg4 = cpu.decode<0x9D>();
    BaseOperation* reg5 = cpu.decode<0x99>();
    BaseOperation* reg6 = cpu.decode<0x81>();
    BaseOperation* reg7 = cpu.decode<0x91>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::STA, AddressModes::ZPG, 0x85, 2, 3);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::STA, AddressModes::ZPG_X, 0x95, 2, 4);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::STA, AddressModes::ABS, 0x8D, 3, 4);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::STA, AddressModes::ABSX, 0x9D, 3, 5);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::STA, AddressModes::ABSY, 0x99, 3, 5);
    OperationTraits traitsMock6 = OperationTraits(OperationTypes::STA, AddressModes::INDIRECT_X, 0x81, 2, 6);
    OperationTraits traitsMock7 = OperationTraits(OperationTypes::STA, AddressModes::INDIRECT_Y, 0x91, 2, 6);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();
    OperationTraits actualTraits6 = reg6->data();
    OperationTraits actualTraits7 = reg7->data();


    "STA_Register_Init_Test"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
        expect(that % actualTraits6 == traitsMock6);
        expect(that % actualTraits7 == traitsMock7);
    };
    

}

void checking_STX_InstructionCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0x86>();
    BaseOperation* reg2 = cpu.decode<0x96>();
    BaseOperation* reg3 = cpu.decode<0x8E>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::STX, AddressModes::ZPG, 0x86, 2, 3);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::STX, AddressModes::ZPG_Y, 0x96, 2, 4);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::STX, AddressModes::ABS, 0x8E, 3, 4);


    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();

    "STX_Register_Init_Test"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
    };
}

void checking_STY_InstructionCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0x84>();
    BaseOperation* reg2 = cpu.decode<0x94>();
    BaseOperation* reg3 = cpu.decode<0x8C>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::STY, AddressModes::ZPG, 0x84, 2, 3);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::STY, AddressModes::ZPG_X, 0x94, 2, 4);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::STY, AddressModes::ABS, 0x8C, 3, 4);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();

    "STY_Register_Init_Test"_test  = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
    };
}

void checking_TransferInstructions_CorrectnessInit(CPU& cpu){
    // Since these transfer registers only have one address mode corresponding with thhem
    // then we will contain thhem under one unit test case
    BaseOperation* reg1 = cpu.decode<0xAA>(); // TAX
    BaseOperation* reg2 = cpu.decode<0xA8>(); // TAY
    BaseOperation* reg3 = cpu.decode<0xBA>(); // TSX
    BaseOperation* reg4 = cpu.decode<0x8A>(); // TXA
    BaseOperation* reg5 = cpu.decode<0x9A>(); // TXS
    BaseOperation* reg6 = cpu.decode<0x98>(); // TYA

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::TAX, AddressModes::IMPLIED, 0xAA, 1, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::TAY, AddressModes::IMPLIED, 0xA8, 1, 2);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::TSX, AddressModes::IMPLIED, 0xBA, 1, 2);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::TXA, AddressModes::IMPLIED, 0x8A, 1, 2);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::TXS, AddressModes::IMPLIED, 0x9A, 1, 2);
    OperationTraits traitsMock6 = OperationTraits(OperationTypes::TYA, AddressModes::IMPLIED, 0x98, 1, 2);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();
    OperationTraits actualTraits6 = reg6->data();


    "Transfer_Registers_Init_Test"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
        expect(that % actualTraits6 == traitsMock6);
    };
}

/** These are test cases for Stack Instructions **/

void check_StackInstructions_CorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0x48>();
    BaseOperation* reg2 = cpu.decode<0x08>();
    BaseOperation* reg3 = cpu.decode<0x68>();
    BaseOperation* reg4 = cpu.decode<0x28>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::PHA, AddressModes::IMPLIED, 0x48, 1, 3);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::PHP, AddressModes::IMPLIED, 0x08, 1, 3);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::PLA, AddressModes::IMPLIED, 0x68, 1, 4);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::PLP, AddressModes::IMPLIED, 0x28, 1, 4);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();



    "Stack_Registers_Init_Test"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
    };
}

void check_DecrementIncrement_InstructionCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0xE6>();
    BaseOperation* reg2 = cpu.decode<0xF6>();
    BaseOperation* reg3 = cpu.decode<0xEE>();
    BaseOperation* reg4 = cpu.decode<0xFE>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::INC, AddressModes::ZPG, 0xE6, 2, 5);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::INC, AddressModes::ZPG_X, 0xF6, 2, 6);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::INC, AddressModes::ABS, 0xEE, 3, 6);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::INC, AddressModes::ABSX, 0xFE, 3, 7);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();



    BaseOperation* reg5 = cpu.decode<0xE8>();
    BaseOperation* reg6 = cpu.decode<0xC8>();

    OperationTraits traitsMock5 = OperationTraits(OperationTypes::INX, AddressModes::IMPLIED, 0xE8, 1, 2);
    OperationTraits traitsMock6 = OperationTraits(OperationTypes::INY, AddressModes::IMPLIED, 0xC8, 1, 2);

    OperationTraits actualTraits5 = reg5->data();
    OperationTraits actualTraits6 = reg6->data();




    "Increment_and_Decrement_Test_Init"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(actualTraits4 == traitsMock4);

        expect(that % actualTraits5 == traitsMock5);
        expect(that % actualTraits6 == traitsMock6);

    };
}


void check_ADC_ArtihmeticOperations1_InstructionsCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0x69>();
    BaseOperation* reg2 = cpu.decode<0x65>();
    BaseOperation* reg3 = cpu.decode<0x75>();
    BaseOperation* reg4 = cpu.decode<0x6D>();
    BaseOperation* reg5 = cpu.decode<0x7D>();
    BaseOperation* reg6 = cpu.decode<0x79>();
    BaseOperation* reg7 = cpu.decode<0x61>();
    BaseOperation* reg8 = cpu.decode<0x71>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::ADC, AddressModes::IMMEDIATE, 0x69, 2, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::ADC, AddressModes::ZPG, 0x65, 2, 3);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::ADC, AddressModes::ZPG_X, 0x75, 2, 4);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::ADC, AddressModes::ABS, 0x6D, 3, 4);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::ADC, AddressModes::ABSX, 0x7D, 3, 4);
    OperationTraits traitsMock6 = OperationTraits(OperationTypes::ADC, AddressModes::ABSY, 0x79, 3, 4);
    OperationTraits traitsMock7 = OperationTraits(OperationTypes::ADC, AddressModes::INDIRECT_X, 0x61, 2, 6);
    OperationTraits traitsMock8 = OperationTraits(OperationTypes::ADC, AddressModes::INDIRECT_Y, 0x71, 2, 5);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();
    OperationTraits actualTraits6 = reg6->data();
    OperationTraits actualTraits7 = reg7->data();
    OperationTraits actualTraits8 = reg8->data();

    "ADC_ArithhmeticOperationsTests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
        expect(that % actualTraits6 == traitsMock6);
        expect(that % actualTraits7 == traitsMock7);
        expect(that % actualTraits8 == traitsMock8);
    };
}

void check_SBC_ArtihmeticOperations2_InstructionsCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0xE9>();
    BaseOperation* reg2 = cpu.decode<0xE5>();
    BaseOperation* reg3 = cpu.decode<0xF5>();
    BaseOperation* reg4 = cpu.decode<0xED>();
    BaseOperation* reg5 = cpu.decode<0xFD>();
    BaseOperation* reg6 = cpu.decode<0xF9>();
    BaseOperation* reg7 = cpu.decode<0xE1>();
    BaseOperation* reg8 = cpu.decode<0xF1>();


    OperationTraits traitsMock1 = OperationTraits(OperationTypes::SBC, AddressModes::IMMEDIATE, 0xE9, 2, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::SBC, AddressModes::ZPG, 0xE5, 2, 3);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::SBC, AddressModes::ZPG_X, 0xF5, 2, 4);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::SBC, AddressModes::ABS, 0xED, 3, 4);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::SBC, AddressModes::ABSX, 0xFD, 3, 4);
    OperationTraits traitsMock6 = OperationTraits(OperationTypes::SBC, AddressModes::ABSY, 0xF9, 3, 4);
    OperationTraits traitsMock7 = OperationTraits(OperationTypes::SBC, AddressModes::INDIRECT_X, 0xE1, 2, 6);
    OperationTraits traitsMock8 = OperationTraits(OperationTypes::SBC, AddressModes::INDIRECT_Y, 0xF1, 2, 5);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();
    OperationTraits actualTraits6 = reg6->data();
    OperationTraits actualTraits7 = reg7->data();
    OperationTraits actualTraits8 = reg8->data();

    "ADC_ArithhmeticOperationsTests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
        expect(that % actualTraits6 == traitsMock6);
        expect(actualTraits7 == traitsMock7);
        expect(actualTraits8 == traitsMock8);
    };
}

void check_AND_LogicalOperations_InstructionsCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0x29>();
    BaseOperation* reg2 = cpu.decode<0x25>();
    BaseOperation* reg3 = cpu.decode<0x35>();
    BaseOperation* reg4 = cpu.decode<0x2D>();
    BaseOperation* reg5 = cpu.decode<0x3D>();
    BaseOperation* reg6 = cpu.decode<0x39>();
    BaseOperation* reg7 = cpu.decode<0x21>();
    BaseOperation* reg8 = cpu.decode<0x31>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::AND, AddressModes::IMMEDIATE, 0x29, 2, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::AND, AddressModes::ZPG, 0x25, 2, 3);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::AND, AddressModes::ZPG_X, 0x35, 2, 4);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::AND, AddressModes::ABS, 0x2D, 3, 4);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::AND, AddressModes::ABSX, 0x3D, 3, 4);
    OperationTraits traitsMock6 = OperationTraits(OperationTypes::AND, AddressModes::ABSY, 0x39, 3, 4);
    OperationTraits traitsMock7 = OperationTraits(OperationTypes::AND, AddressModes::INDIRECT_X, 0x21, 2, 6);
    OperationTraits traitsMock8 = OperationTraits(OperationTypes::AND, AddressModes::INDIRECT_Y, 0x31, 2, 5);


    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();
    OperationTraits actualTraits6 = reg6->data();
    OperationTraits actualTraits7 = reg7->data();
    OperationTraits actualTraits8 = reg8->data();


    "AND_LogicalOperationsTests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
        expect(that % actualTraits6 == traitsMock6);
        expect(that % actualTraits7 == traitsMock7);
        expect(that % actualTraits8 == traitsMock8);
    };

}

void check_EOR_LogicalOperations_InstructionsCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0x49>();
    BaseOperation* reg2 = cpu.decode<0x45>();
    BaseOperation* reg3 = cpu.decode<0x55>();
    BaseOperation* reg4 = cpu.decode<0x4D>();
    BaseOperation* reg5 = cpu.decode<0x5D>();
    BaseOperation* reg6 = cpu.decode<0x59>();
    BaseOperation* reg7 = cpu.decode<0x41>();
    BaseOperation* reg8 = cpu.decode<0x51>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::EOR, AddressModes::IMMEDIATE, 0x49, 2, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::EOR, AddressModes::ZPG, 0x45, 2, 3);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::EOR, AddressModes::ZPG_X, 0x55, 2, 4);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::EOR, AddressModes::ABS, 0x4D, 3, 4);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::EOR, AddressModes::ABSX, 0x5D, 3, 4);
    OperationTraits traitsMock6 = OperationTraits(OperationTypes::EOR, AddressModes::ABSY, 0x59, 3, 4);
    OperationTraits traitsMock7 = OperationTraits(OperationTypes::EOR, AddressModes::INDIRECT_X, 0x41, 2, 6);
    OperationTraits traitsMock8 = OperationTraits(OperationTypes::EOR, AddressModes::INDIRECT_Y, 0x41, 2, 5);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();
    OperationTraits actualTraits6 = reg6->data();
    OperationTraits actualTraits7 = reg7->data();
    OperationTraits actualTraits8 = reg8->data();

    "EOR_LogicalOperationsTests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
        expect(that % actualTraits6 == traitsMock6);
        expect(that % actualTraits7 == traitsMock7);
        expect(that % actualTraits8 == traitsMock8);
    };

}

void check_ORA_LogicalOperations_InstructionsCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0x09>();
    BaseOperation* reg2 = cpu.decode<0x05>();
    BaseOperation* reg3 = cpu.decode<0x15>();
    BaseOperation* reg4 = cpu.decode<0x0D>();
    BaseOperation* reg5 = cpu.decode<0x1D>();
    BaseOperation* reg6 = cpu.decode<0x19>();
    BaseOperation* reg7 = cpu.decode<0x01>();
    BaseOperation* reg8 = cpu.decode<0x11>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::ORA, AddressModes::IMMEDIATE, 0x09, 2, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::ORA, AddressModes::ZPG, 0x05, 2, 3);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::ORA, AddressModes::ZPG_X, 0x15, 2, 4);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::ORA, AddressModes::ABS, 0x0D, 3, 4);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::ORA, AddressModes::ABSX, 0x1D, 3, 4);
    OperationTraits traitsMock6 = OperationTraits(OperationTypes::ORA, AddressModes::ABSY, 0x19, 3, 4);
    OperationTraits traitsMock7 = OperationTraits(OperationTypes::ORA, AddressModes::INDIRECT_X, 0x01, 2, 6);
    OperationTraits traitsMock8 = OperationTraits(OperationTypes::ORA, AddressModes::INDIRECT_Y, 0x01, 2, 5);


    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();
    OperationTraits actualTraits6 = reg6->data();
    OperationTraits actualTraits7 = reg7->data();
    OperationTraits actualTraits8 = reg8->data();

    "EOR_LogicalOperationsTests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
        expect(that % actualTraits6 == traitsMock6);
        expect(that % actualTraits7 == traitsMock7);
        expect(that % actualTraits8 == traitsMock8);
    };
}

void check_ASL_LogicalOperations_InstructionsCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0x0A>();
    BaseOperation* reg2 = cpu.decode<0x06>();
    BaseOperation* reg3 = cpu.decode<0x16>();
    BaseOperation* reg4 = cpu.decode<0x0E>();
    BaseOperation* reg5 = cpu.decode<0x1E>();


    OperationTraits traitsMock1 = OperationTraits(OperationTypes::ASL, AddressModes::A, 0x0A, 1, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::ASL, AddressModes::ZPG, 0x06, 2, 5);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::ASL, AddressModes::ZPG_X, 0x16, 2, 6);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::ASL, AddressModes::ABS, 0x0E, 3, 6);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::ASL, AddressModes::ABSX, 0x1E, 3, 7);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();

    "ASL_ShiftOperationsTests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
    };
}

void check_LSR_InstructionCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0x4A>();
    BaseOperation* reg2 = cpu.decode<0x46>();
    BaseOperation* reg3 = cpu.decode<0x56>();
    BaseOperation* reg4 = cpu.decode<0x4E>();
    BaseOperation* reg5 = cpu.decode<0x5E>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::LSR, AddressModes::A, 0x4A, 1, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::LSR, AddressModes::ZPG, 0x46, 2, 5);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::LSR, AddressModes::ZPG_X, 0x56, 2, 6);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::LSR, AddressModes::ABS, 0x4E, 3, 6);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::LSR, AddressModes::ABSX, 0x5E, 3, 7);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();

    
    "LSR_ShiftOperationsTests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
    };

}

void check_ROL_InstructionCorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0x2A>();
    BaseOperation* reg2 = cpu.decode<0x26>();
    BaseOperation* reg3 = cpu.decode<0x36>();
    BaseOperation* reg4 = cpu.decode<0x2E>();
    BaseOperation* reg5 = cpu.decode<0x3E>();


    OperationTraits traitsMock1 = OperationTraits(OperationTypes::ROL, AddressModes::A, 0x2A, 1, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::ROL, AddressModes::ZPG, 0x26, 2, 5);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::ROL, AddressModes::ZPG_X, 0x36, 2, 6);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::ROL, AddressModes::ABS, 0x2E, 3, 6);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::ROL, AddressModes::ABSX, 0x3E, 3, 7);


    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();


    "ROL_ShiftOperationsTests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
    };
}

void check_ROR_InstructionCorrectnessInit(CPU& cpu){
    
    BaseOperation* reg1 = cpu.decode<0x6A>();
    BaseOperation* reg2 = cpu.decode<0x66>();
    BaseOperation* reg3 = cpu.decode<0x76>();
    BaseOperation* reg4 = cpu.decode<0x6E>();
    BaseOperation* reg5 = cpu.decode<0x7E>();


    OperationTraits traitsMock1 = OperationTraits(OperationTypes::ROR, AddressModes::A, 0x6A, 1, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::ROR, AddressModes::ZPG, 0x66, 2, 5);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::ROR, AddressModes::ZPG_X, 0x76, 2, 6);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::ROR, AddressModes::ABS, 0x6E, 3, 6);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::ROR, AddressModes::ABSX, 0x7E, 3, 7);


    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();

    "ROR_ShiftOperationsTests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
    };
}


void check_FlagsInstruction_CorrectnessInit(CPU& cpu){
    
    // In this one test case we are testing both instructions since, there are only one address modes each
    // Testing registers, CLC, CLD, CLI, CLV, SEC, SED, SEI

    BaseOperation* reg1 = cpu.decode<0x18>();
    BaseOperation* reg2 = cpu.decode<0xD8>();
    BaseOperation* reg3 = cpu.decode<0x58>();
    BaseOperation* reg4 = cpu.decode<0xB8>();
    BaseOperation* reg5 = cpu.decode<0x38>();
    BaseOperation* reg6 = cpu.decode<0xF8>();
    BaseOperation* reg7 = cpu.decode<0x78>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::CLC, AddressModes::IMPLIED, 0x18, 1, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::CLD, AddressModes::IMPLIED, 0xD8, 1, 2);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::CLI, AddressModes::IMPLIED, 0x58, 1, 2);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::CLV, AddressModes::IMPLIED, 0xB8, 1, 2);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::SEC, AddressModes::IMPLIED, 0x38, 1, 2);
    OperationTraits traitsMock6 = OperationTraits(OperationTypes::SED, AddressModes::IMPLIED, 0xF8, 1, 2);
    OperationTraits traitsMock7 = OperationTraits(OperationTypes::SEI, AddressModes::IMPLIED, 0x78, 1, 2);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();
    OperationTraits actualTraits6 = reg6->data();
    OperationTraits actualTraits7 = reg7->data();



    "FlagInstructions_Tests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
        expect(that % actualTraits6 == traitsMock6);
        expect(that % actualTraits7 == traitsMock7);
    };
}

void check_CMP_Instruction_CorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0xC9>();
    BaseOperation* reg2 = cpu.decode<0xC5>();
    BaseOperation* reg3 = cpu.decode<0xD5>();
    BaseOperation* reg4 = cpu.decode<0xCD>();
    BaseOperation* reg5 = cpu.decode<0xDD>();
    BaseOperation* reg6 = cpu.decode<0xD9>();
    BaseOperation* reg7 = cpu.decode<0xC1>();
    BaseOperation* reg8 = cpu.decode<0xD1>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::CMP, AddressModes::IMMEDIATE, 0xC9, 2, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::CMP, AddressModes::ZPG, 0xC5, 2, 3);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::CMP, AddressModes::ZPG_X, 0xD5, 2, 4);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::CMP, AddressModes::ABS, 0xCD, 3, 4);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::CMP, AddressModes::ABSX, 0xDD, 3, 4);
    OperationTraits traitsMock6 = OperationTraits(OperationTypes::CMP, AddressModes::ABSY, 0xD9, 3, 4);
    OperationTraits traitsMock7 = OperationTraits(OperationTypes::CMP, AddressModes::INDIRECT_X, 0xC1, 2, 6);
    OperationTraits traitsMock8 = OperationTraits(OperationTypes::CMP, AddressModes::INDIRECT_Y, 0xD1, 2, 5);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();
    OperationTraits actualTraits6 = reg6->data();
    OperationTraits actualTraits7 = reg7->data();
    OperationTraits actualTraits8 = reg8->data();


    "CMP_Instructions_Tests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
        expect(that % actualTraits6 == traitsMock6);
        expect(that % actualTraits7 == traitsMock7);
        expect(that % actualTraits8 == traitsMock8);
    };
}

void check_CPX_Instruction_CorrectnessInit(CPU& cpu){

    BaseOperation* reg1 = cpu.decode<0xE0>();
    BaseOperation* reg2 = cpu.decode<0xE4>();
    BaseOperation* reg3 = cpu.decode<0xEC>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::CPX, AddressModes::IMMEDIATE, 0xE0, 2, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::CPX, AddressModes::ZPG, 0xE4, 2, 3);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::CPX, AddressModes::ABS, 0xEC, 3, 4);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();

    "CPX_Instructions_Tests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
    };
}

void check_CPY_Instruction_CorrectnessInit(CPU& cpu){

    BaseOperation* reg1 = cpu.decode<0xC0>();
    BaseOperation* reg2 = cpu.decode<0xC4>();
    BaseOperation* reg3 = cpu.decode<0xCC>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::CPY, AddressModes::IMMEDIATE, 0xC0, 2, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::CPY, AddressModes::ZPG, 0xC4, 2, 3);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::CPY, AddressModes::ABS, 0xCC, 3, 4);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();

    "CPX_Instructions_Tests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
    };
}

void check_ConditionalBranch_Instruction_CorrectnessInit(CPU& cpu){
    // Testing all branch registers under one test case, since they only have one address mode
    // Address Mode: RELATIVE
    BaseOperation* reg1 = cpu.decode<0x90>();
    BaseOperation* reg2 = cpu.decode<0xB0>();
    BaseOperation* reg3 = cpu.decode<0xF0>();
    BaseOperation* reg4 = cpu.decode<0x30>();
    BaseOperation* reg5 = cpu.decode<0xD0>();
    BaseOperation* reg6 = cpu.decode<0x10>();
    BaseOperation* reg7 = cpu.decode<0x50>();
    BaseOperation* reg8 = cpu.decode<0x70>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::BCC, AddressModes::RELATIVE, 0x90, 2, 2);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::BCS, AddressModes::RELATIVE, 0xB0, 2, 2);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::BEQ, AddressModes::RELATIVE, 0xF0, 2, 2);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::BMI, AddressModes::RELATIVE, 0x30, 2, 2);
    OperationTraits traitsMock5 = OperationTraits(OperationTypes::BNE, AddressModes::RELATIVE, 0xD0, 2, 2);
    OperationTraits traitsMock6 = OperationTraits(OperationTypes::BPL, AddressModes::RELATIVE, 0x10, 2, 2);
    OperationTraits traitsMock7 = OperationTraits(OperationTypes::BVC, AddressModes::RELATIVE, 0x50, 2, 2);
    OperationTraits traitsMock8 = OperationTraits(OperationTypes::BVS, AddressModes::RELATIVE, 0x70, 2, 2);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();
    OperationTraits actualTraits5 = reg5->data();
    OperationTraits actualTraits6 = reg6->data();
    OperationTraits actualTraits7 = reg7->data();
    OperationTraits actualTraits8 = reg8->data();

    "ConditionalBranch_Instructions_Tests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
        expect(that % actualTraits5 == traitsMock5);
        expect(that % actualTraits6 == traitsMock6);
        expect(that % actualTraits7 == traitsMock7);
        expect(that % actualTraits8 == traitsMock8);
    };
}

void check_JumpsAndSubroutines_Instruction_CorrectnessInit(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0x4C>();
    BaseOperation* reg2 = cpu.decode<0x6C>();
    BaseOperation* reg3 = cpu.decode<0x20>();
    BaseOperation* reg4 = cpu.decode<0x60>();
    
    OperationTraits traitsMock1 = OperationTraits(OperationTypes::JMP, AddressModes::ABS, 0x4C, 3, 3);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::JMP, AddressModes::INDIRECT, 0x6C, 3, 5);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::JSR, AddressModes::ABS, 0x20, 3, 6);
    OperationTraits traitsMock4 = OperationTraits(OperationTypes::RTS, AddressModes::IMPLIED, 0x60, 1, 6);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();
    OperationTraits actualTraits4 = reg4->data();

    "JumpsAndSubroutines_Instructions_Tests"_test = [&]{
        expect(that % actualTraits1 == traitsMock1);
        expect(that % actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
        expect(that % actualTraits4 == traitsMock4);
    };
}

void check_OtherInstructions_Init(CPU& cpu){
    BaseOperation* reg1 = cpu.decode<0x24>();
    BaseOperation* reg2 = cpu.decode<0x2C>();
    BaseOperation* reg3 = cpu.decode<0xEA>();

    OperationTraits traitsMock1 = OperationTraits(OperationTypes::BIT, AddressModes::ZPG, 0x24, 2, 3);
    OperationTraits traitsMock2 = OperationTraits(OperationTypes::BIT, AddressModes::ABS, 0x24, 3, 4);
    OperationTraits traitsMock3 = OperationTraits(OperationTypes::NOP, AddressModes::IMPLIED, 0x2C, 1, 2);

    OperationTraits actualTraits1 = reg1->data();
    OperationTraits actualTraits2 = reg2->data();
    OperationTraits actualTraits3 = reg3->data();


    "JumpsAndSubroutines_Instructions_Tests"_test = [&]{
        expect(actualTraits1 == traitsMock1);
        expect(actualTraits2 == traitsMock2);
        expect(that % actualTraits3 == traitsMock3);
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