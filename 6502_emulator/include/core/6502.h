#pragma once
#include <core/CPU.h>

/**
 * 
 * 
 * 6502.h
 * - Is where the application user, will call functions.
 * - Possible helper functions calls.
 * - Runs the mainloop
 * 
*/

void execute(bool isCpuRunning){
    CPU cpu = CPU();
    std::array<u8, 65536> ramMemory;


    /*
    while(isCpuRunning){
        // opcode_t opcode = cpu.fetch();
        opcode_t opcode = ramMemory[cpu.PC++];
        InstructionTraits* t = lda.decode(opcode);
        std::cout << "Current Iterating Opcode: " << reinterpret_cast<void *>(opcode) << '\n';
        if(t != nullptr){
            std::cout << t << '\n';
        }
        // cpu.PC++;
        sleep(1);
    }
    */
}