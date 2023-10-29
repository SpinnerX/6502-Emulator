#pragma once
#include <core/CPU.h>

void execute(bool isCpuRunning){
    CPU cpu = CPU();
    std::array<u8, 65536> ramMemory;
    ramMemory[0xFFFC] = 12;
    // formatCpp::print("Value1: {}\n", ramMemory[0xFFFC]);
    std::cout << "Value1: " << ramMemory[0xFFFC] << '\n';

    uint16_t reset_vector_address = 0xFFFC;

    std::cout << reinterpret_cast<void *>(ramMemory[reset_vector_address+1]) << '\n';
    std::cout << reinterpret_cast<void *>( ramMemory[reset_vector_address+2]) << '\n';
    std::cout << reinterpret_cast<void *>( ramMemory[reset_vector_address+3]) << '\n';

    uint16_t resetVector = (ramMemory[reset_vector_address] << 8) | ramMemory[0xFFFC];
    uint16_t PC = resetVector; // This is how we start executing the first instructions.


    BaseRegister* register1 = cpu.decode<0xA9>();
    BaseRegister* register2 = cpu.decode<0xA5>();
    BaseRegister* register3 = cpu.decode<0xB5>();
    BaseRegister* register4 = cpu.decode<0xAD>();

    // formatCpp::print("Reg 1: {}\n",formatCpp::streamed(register1->data()));
    // formatCpp::print("Reg 2: {}\n",formatCpp::streamed(register2->data()));
    // formatCpp::print("Reg 3: {}\n",formatCpp::streamed(register3->data()));
    // formatCpp::print("Reg 4: {}\n",formatCpp::streamed(register4->data()));
    std::cout << "Reg 1: " << register1->data() << '\n';
    std::cout << "Reg 2: " << register2->data() << '\n';
    std::cout << "Reg 3: " << register3->data() << '\n';
    std::cout << "Reg 4: " << register4->data() << '\n';

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