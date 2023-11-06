#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <any>
#include <variant>
#include <common/CPUConfigs.h>
#include <common/types.h>

// BaseInstruction
// Initialized operations corresponding to eachh instruction name
// Handling if depending on the instructions if there are any additional cycles 

struct BaseInstruction{
    template<typename T>
    using um_map = std::unordered_map<std::string, std::function<void(T&, uint8_t)> >;
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
            setFlag(configs.status, CPUConfigs::Status::Z, configs.ac == 0x00);
            setFlag(configs.status, CPUConfigs::Status::N, configs.ac & 0x80);
        });

        // // Function: M -> X (Putting data into the x register)
        // Loading data from Memory to X register
        operations.emplace("LDX", [&](CPUConfigs& configs, uint8_t data){
            configs.x = data;
        });

        // Function: M -> Y (Storing data into y register)
        operations.emplace("LDY", [&](CPUConfigs& configs, uint8_t data){
            configs.y = data;
        });

        // Function: A -> M
        operations.emplace("STA", [&](CPUConfigs& configs, uint8_t data){
            configs.ac = data;
            configs[this->opcode] = configs.ac;
        });

        operations.emplace("STX", [&](CPUConfigs& configs, uint8_t data){
            configs.x = data;
            configs[this->opcode] = configs.x;
        });

        operations.emplace("STY", [&](CPUConfigs& configs, uint8_t data){
            configs.y = data;
            configs[this->opcode] = configs.y;
        });

        // NOTE: For testing purposes, using primitive passed into specific registers
        //      then testing if the data transferred from one register to the stack pointer reg
        //      are working correctly, as in the stack pointer now contains that data.
        // Second Note: Now for actually running the emulator, probably somewhere in (virtual)memory
        //              assign transfer data from registers to a 256 byte stack memory, rangining
        //              from $0100 to 01FF, such as those range is only available for stack memory.
        // Third Note: 0x0000 to 0x00FF: is for the Zero Page (cpu caching)
        // ** Just noting, since we are trying to verify if these exists in unit test cases, but when running the emulator
        //    then to actually consider the following for actually emulating the cpu.
        operations.emplace("TAX", [&](CPUConfigs& configs, uint8_t a){
            configs.x = a; // transfering data from the accumulator into the x register
        });
        
        operations.emplace("TAY", [&](CPUConfigs& configs, uint8_t a){
            configs.y = a; // transferring data from accumulator into index y register
        });

        operations.emplace("TSX", [&](CPUConfigs& configs, uint8_t sp){
            configs.x = sp; // transferring data from register index x to store in stack ptr
        });

        operations.emplace("TXA", [&](CPUConfigs& configs, uint8_t x){
            configs.ac = x; // transferring data from index x register to store in accumulator
        });

        operations.emplace("TXS", [&](CPUConfigs& configs, uint8_t x){
            configs.sp = x; // transferring data from index x register to the stack register
        });

        operations.emplace("TYA", [&](CPUConfigs& configs, uint8_t y){
            configs.ac = y; // transferring from index y to the accumulator
        });

        // No defined operations will look like this, essentially
        // And may show an ideal way of how these may be read.
        operations.emplace("PHA", [&](CPUConfigs& configs, uint8_t reg){
            // PHA (Push Accumulator on Stack)
            // Function: push A
            // Example: Probably would look like something like:
            // sp++;
            // configs[0x0100 + configs.sp] = data  (in this case, accumulator)
            configs[0x0100 + configs.sp] = reg;
            configs.sp--; // Whenever we write to memory, we decrement.
        });

        operations.emplace("PHP", [&](CPUConfigs& configs, uint8_t data){
            // PHP (Push Procssor Status on Stack)
            // Function: push SR // SR is referring to Status flags
            // Example: Probably would look like:
            // configs[0x0100 + sp] =   (status | B | U)
            // NOTE: Break flag is set to 1 before pushing

            configs[0x0100 + configs.sp] = data;
            setFlag(configs.status, CPUConfigs::Status::B, 0);
            setFlag(configs.status, CPUConfigs::Status::U, 0);
            configs.sp--; // since we are writing to memory we need to decrement the stack pointer
        });

        operations.emplace("PLA", [&](CPUConfigs& configs, uint8_t data){
            // PLA (Pull Accumulator from Stack)
            // Function: pull A
            // Example: Probably would look like:
            // sp++;
            // configs.status = configs[0x0100 + configs.sp]
            configs.sp++;
            configs.status = configs[0x0100 + configs.sp];
        });

    }

    virtual uint16_t getOpcode() const{
        printf("Default getOpcode() called instead!\n");
        return 0x00;
    }


    virtual void operation(CPUConfigs& configs, uint8_t){
        std::cout << "Default operation() call\n";
    }

    // Will vary if there needs to be an additional cycles for specific instructions
    virtual uint8_t cycle(CPUConfigs&){
        std::cout << "Default cycle() call\n";
        return 0x00;
    }

    // Returns value of specific bit of status reg
    // takes the original variable (that we want to modify, until I can find a better way of doing it later...)
    // for both setFlag and getFlag functions
    virtual uint8_t getFlag(uint8_t& s, CPUConfigs::Status flag){
        printf("Default getFlag() function!\n");
        return 0x00;
    }

    // Sets or clears a specific bit of the status register
    virtual void setFlag(uint8_t& s, CPUConfigs::Status flag, bool condition){
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

    // NOTE: Since we are loading, storing, and transferring information from memory
    // should use std::array virtual memory to load data
    // For testing purposes, we are just loading primitive data, but for the actual running of the emulator
    // we will want to read from memory instead of primitive variables(data)
    std::unordered_map<std::string, std::function<void(CPUConfigs&, uint8_t)> > operations; // unordered_map<instructionName, operation>
};

// Idea behind thihs templated class
// Allowing one creation of Instruction class
// Generic class to simply handle the different instruction in instruction set with address mode, and opcodes
// Handling the same operations and while checking 
// Instruction class allows for us to create different opcodes of instructions
// While still maintaining having a default type (hence the use of BaseInstruction)
template<auto Opcode>
struct Instruction : public BaseInstruction {
    Instruction() : BaseInstruction(Opcode) {}


    // Allows us to get the operation based on the instruction name
    // which may also depend on our opcodes
    void operation(CPUConfigs& configs, uint8_t data) override {
        operations[name](configs, data);
    }

    uint8_t cycle(CPUConfigs& configs) override {
        return instructionData(Opcode).cycle(configs);
    }

    uint16_t getOpcode() const override {
        return this->opcode;
    }

    // For now this is how we will set the statuses
    // using setFlag and getFlag the way they're implemented for rn
    // We pass in the status we want to modify

    // Either returning a specific bit for the status register
    uint8_t getFlag(uint8_t& status, CPUConfigs::Status flag) override {
        return ((status & flag) > 0) ? 1 : 0;
    }

    // Passing status to modify whether we will actually modify the value
    // To either setting that bit, or clearing that bit.
    void setFlag(uint8_t& status, CPUConfigs::Status flag, bool condition) override{
        if(condition){
            status |= flag;
        }
        else{
            status &= ~flag;
        }
    }

};