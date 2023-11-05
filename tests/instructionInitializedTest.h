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
    BaseInstruction* sta = new Instruction<0x85>();
    int value = 2;
    sta->operation(conf, value); // we are storing value into a specific memory address depending on opcode.

    BaseInstruction* stx = new Instruction<0x86>();
    int value2 = 10;
    stx->operation(conf, value2); // storing value2 into the x register

    "StoreInstructionInitialized Address Modes"_test = [&]{
        expect(that %  conf[0x85] == value);
        expect(that % conf.x == value2);
    };
    
}