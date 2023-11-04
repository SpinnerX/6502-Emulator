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
void testLDAInstruction(CPUConfigs& conf){
    // Testing operations
    BaseInstruction* testInstruction = new Instruction<0xA9>();
    testInstruction->operation(conf, 2); // testing that we are loading number 2 into accumualator, essentially doing: LDA $2

    BaseInstruction* testInstruction2 = new Instruction<0xA2>();
    testInstruction2->operation(conf, 2); // testing that we are loading 2 into register x, essentially doing: LDX $2

    BaseInstruction* testInstruction3 = new Instruction<0xA0>();
    testInstruction3->operation(conf, 5); // testing that we are loading 2 into register x, essentially doing: LDX $2

    "LDAInitialized Address Modes"_test = [&]{
        expect(that % conf.ac == 0x02);
        expect(that % conf.x == 0x02);
        expect(that % conf.y == 0x05);
    };

}