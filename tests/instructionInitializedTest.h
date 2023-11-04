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
    testInstruction->operation(conf, 2);

    BaseInstruction* testInstruction2 = new Instruction<0xA2>();
    testInstruction2->operation(conf, 2);

    "LDAInitialized Address Modes"_test = [&]{
        expect(that % conf.ac == 0x02);
        expect(that % conf.x == 0x02);
    };

}