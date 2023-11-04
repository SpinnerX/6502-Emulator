#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <common/CPUConfigs.h>
#include <common/types.h>

// BaseInstruction
// Initialized operations corresponding to eachh instruction name
// Handling if depending on the instructions if there are any additional cycles 

struct BaseInstruction{
    BaseInstruction() = default;
    BaseInstruction(std::string n, std::string mode, uint16_t cyc) : name(n), addressMode(mode), cycles(cyc) {}
    BaseInstruction(uint16_t op){
        name = instructionData(op).name;
        addressMode = instructionData(op).addressMode;
        opcode = instructionData(op).opcode;

        // This hash table will contain the instructions and operations corresponding with eachh instruction
        // Creating an unordered map to the corresponding function which this lambda function is essentially
        // data that is uint8_t is the data fetched from memory (M)
        // unordered_map<instructionName, operation>

        //  LDA Function: M -> A  (Putting data into the Accumulator)
        // Loading data from Memory to Accumulator
        // Status Flags for LDA
        // N	Z	C	I	D	V
        // +	+	-	-	-	-
        operations.emplace("LDA", [&](CPUConfigs& configs, uint8_t data){
            configs.ac = data;
            setFlag(CPUConfigs::Status::Z, configs.ac == 0x00);
            setFlag(CPUConfigs::Status::N, configs.ac & 0x80);
        });

        // // Function: M -> X (Putting data into the x register)
        // Loading data from Memory to X register
        operations.emplace("LDX", [&](CPUConfigs& configs, uint8_t data){
            configs.x = data;
        });

        operations.emplace("LDY", [&](CPUConfigs& configs, uint8_t data){
            configs.y = data;
        });


    }


    virtual void operation(CPUConfigs& configs, uint8_t){
        std::cout << "Default operation() call\n";
    }

    // Will vary if there needs to be an additional cycles for specific instructions
    virtual uint8_t cycle(CPUConfigs&){
        std::cout << "Default cycle() call\n";
        return 0x00;
    }

    virtual void getFlag(CPUConfigs::Status flag, bool condition){
        printf("Default getFlag() function!\n");
    }

    virtual void setFlag(CPUConfigs::Status flag, bool condition){
        printf("Default setFlag() function!\n");
    }

    friend std::ostream& operator<<(std::ostream& outs, BaseInstruction* rhs){
        outs << "Name: " << rhs->name << '\n';
        outs << "Address Mode: " << rhs->addressMode << '\n';
        outs << "Opcode: " << reinterpret_cast<void*>(rhs->opcode) << '\n';
        outs << "Cycles: " << rhs->cycles << '\n';
        return outs;
    }

    std::string name="Default Name";
    std::string addressMode = "Default Address Mode";
    uint16_t opcode=0;
    uint16_t cycles=0;
    std::unordered_map<std::string, std::function<void(CPUConfigs&, uint8_t)> > operations; // unordered_map<instructionName, operation>
};

// Idea behind thihs templated class
// Allowing one creation of Instruction class
// Generic class to simply handle the different instruction in instruction set with address mode, and opcodes
// Handling the same operations and while checking 
// Instruction class allows for us to create different opcodes of instructions
// While still maintaining having a default type (hence the use of BaseInstruction)
template<uint16_t Opcode>
struct Instruction : public BaseInstruction {
    Instruction() : BaseInstruction(Opcode) {}

    void operation(CPUConfigs& configs, uint8_t data) override {
        operations[name](configs, data);
    }

    uint8_t cycle(CPUConfigs& configs) override {
        return instructionData(Opcode).cycle(configs);
    }

};