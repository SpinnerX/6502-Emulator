#pragma once
#include "boost/ut.hpp"
#include <cpu/CPU.h>
using namespace boost::ut;

/**
 * 
 * Testing thhe LDA instruction
 * 
 * 
*/
void testLoadInstructions(CPUConfigs& conf){
    // Testing operations
    BaseInstruction* lda = new Instruction<0xA9>();
    lda->operation(conf, 2); // testing that we are loading number 2 into accumualator, essentially doing: LDA $2

    BaseInstruction* ldx = new Instruction<0xA2>();
    ldx->operation(conf, 2); // testing that we are loading 2 into register x, essentially doing: LDX $2

    BaseInstruction* ldy = new Instruction<0xA0>();
    ldy->operation(conf, 5); // testing that we are loading 2 into register y, essentially doing: LDY $5

    "LoadInstructionInitialized Address Modes"_test = [&]{
        expect(that % conf.ac == 0x02);
        expect(that % conf.x == 0x02);
        expect(that % conf.y == 0x05);
    };

}


void testStoringInstructions(CPUConfigs& conf){
    conf.reset(); // making sure we are resetting the registers to a known state
    BaseInstruction* sta = new Instruction<0x85>();
    int value = 2;
    sta->operation(conf, value); // Testing if storing value into a specific memory address depending on opcode.

    BaseInstruction* stx = new Instruction<0x86>();
    int value2 = 10;
    stx->operation(conf, value2); // Testing if storing value2 into the x register

    BaseInstruction* sty = new Instruction<0x84>();
    int value3 = 100;
    sty->operation(conf, value3); // Testing if storing value3 into register y works.

    "StoreInstructionInitialized Address Modes"_test = [&]{
        // Testing those specific locations in memory contain these stored data
        expect(that %  conf[sta->getOpcode()] == value);
        expect(that % conf[stx->getOpcode()] == value2);
        expect(that % conf[sty->getOpcode()] == value3);
    };
}

void testTransferInstructions(CPUConfigs& conf){
    conf.reset(); // making sure we are resetting the registers to a known state


    // Testing the transfer instructions
    // By testing the transfer instructions we are loading into accumulator, x, and y registers
    // And transferring data from accumulator and x registers, to stack ptr, x, y, and acumulator
    //  registers
    // Testing for correctness if loading and transfer instructions are working properly.


    // We are first loading data (in this case 10, into loadAccumulator)
    // Then we use the TAX instruction to transfer data from accumulator to the x register
    // Equivalent to doing: LDA $10
    BaseInstruction* loadAccumulator = new Instruction<0xA9>(); // Instruction to load accumulator
    int value0 = 10;
    loadAccumulator->operation(conf, value0);

    // Equivalent to doing: LDX $20
    BaseInstruction* loadX = new Instruction<0xA0>();
    int value1 = 20;
    loadX->operation(conf, value1); // Instruction for loading the x register to value1: 20
    
    // Equivalent to doing: TAX, $ldx (or something, just pseudocode visually to see how it look)
    BaseInstruction* tax = new Instruction<0xAA>(); // Function: A -> stored in -> x (index)
    tax->operation(conf, conf.ac); // transferring accumulator to x register

    "TaxInstructionTest"_test = [&]{
        expect(that % conf.x == value0); // Testing: Transferring ac to x reg
    };

    BaseInstruction* tay = new Instruction<0xA8>(); // Function: A -> Y
    tay->operation(conf, conf.ac); // transferring data in accumulator to indexed y register

    "TayInstructionTest"_test = [&]{
        expect(that % conf.y == conf.ac);
    };

    BaseInstruction* tsx = new Instruction<0xBA>(); // Function: SP -> X
    conf.sp = 30;
    tsx->operation(conf, conf.sp); // transferring data from stack register (SP) to index x register

    "TsxInstructionTest"_test = [&]{
        expect(that % conf.x == conf.sp);
    };

    BaseInstruction* txa = new Instruction<0x8A>(); // Function: X -> A
    txa->operation(conf, conf.x); // transferring data from x index register to accumulator

    "TxaInstructionTest"_test = [&]{
        expect(that % conf.ac == conf.x);
    };

    BaseInstruction* txs = new Instruction<0x9A>(); // Function: X -> SP
    txs->operation(conf, conf.x); // transferring x register to stack pointer reg (SP)

    "TxsInstructionTest"_test = [&]{
        expect(that % conf.sp == conf.x);
    };

    BaseInstruction* tya = new Instruction<0x98>(); // Function: Y -> A
    tya->operation(conf, conf.y); // transferring data from y indexed register to accumulator

    "TyaInstructionTest"_test = [&]{
        expect(that % conf.ac == conf.y);
    };
}


void testStackInstructions(CPUConfigs& conf){
    conf.reset();
    BaseInstruction* pha = new Instruction<0x48>(); //  PHA (Push Accumulator to Stack)
    conf.ac = 0x10;
    // Every time we write to the stack ptr we decrement, to test if the value's been set we increment the stack pointer for testing purposes
    pha->operation(conf, conf.ac);

    "PHAStackInstructionInitialized Address Modes"_test = [&]{
        expect(that % conf[0x0100 + (conf.sp+1)] == conf.ac); // TEST: Checking if that specific location in memory contains the value set from the accumulator
    };
    conf.reset(); // we are resetting the CPU to a known state

    BaseInstruction* php = new Instruction<0x08>(); // PLA (Pull Accumulator to Stack)
    php->operation(conf, (conf.status | CPUConfigs::Status::B));

    "PHPStackInstructionInitialized Address Modes"_test = [&]{
        expect(that % CPUConfigs::Status::B & 1); // TEST: Checking if the Break flag has been correctly set to 1
        expect(that % CPUConfigs::Status::U & 1); // TEST: Checking Unused flag correctly set to 1 
        // expect(that % 1 == (conf.status >> 5) & 1); // checking 5th bit has been set to 1.
    };
}



