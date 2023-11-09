#pragma once
#include <cstring>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <array>

/**
 * 
 * CPUData
 * - Struct that is a POD (Plain Old Data)
 * - Contains the registers that'll be used to do operations, moving data, etc.
 * 
 * 
 * Visually to see how it works
 * 
 * whihle loop:
 *  opcode = fetch()
 *  ir = decode(opcode)
 *  
 * 
 * Example (When looking at reading a word, and the next instruction)
 * => example, if you have an instruction like LDA #$10, it would be represented in memory as
 *      two bytes: A9 (opcode for LDA immediate mode) and 10 (operand). After fetching the first byte
 *      (A9), the PC will increment by 1 to fetch the operand (10).
 * => However, when reading a word (incrementing PC by 2), it does not necessarily mean you are
 *      grabbing two instructions. It may mean that you are grabbing one instruction and its operand, or
 *      part of an instruction that takes more than one or two bytes. Alternatively, if an operand is a
 *      memory address (which is 16 bits, or 2 bytes in 6502), you may be reading in the full address with
 *      a two-byte (word) read.
 * =>Ultimately, the interpretation depends on the instructions set to be executed and how the data is encoded in memory.
*/

struct CPUData{
    // Keeping track of our status inside CPUConfigs, since the entire CPU will be utilizing this configurations
    enum Status{
		C = (1 << 0),	// Carry Bit
		Z = (1 << 1),	// Zero
		I = (1 << 2),	// Disable Interrupts
		D = (1 << 3),	// Decimal Mode (unused in this implementation)
		B = (1 << 4),	// Break
		U = (1 << 5),	// Unused
		V = (1 << 6),	// Overflow
		N = (1 << 7),	// Negative
	};

    void initializeMemory(){
        memory.fill(0x00); // initializing array to 0
        // memory[0x03] = 0xA9;
        // setting reset vector at 0xFFFC and 0xFFFD
        memory[0xFFFC] = 0x0000;
        memory[0xFFFC] = 0x0001;
    }

    // resetting these registers to a known state
    void reset(){
        uint16_t low = memory[0xFFFC + 0]; // we take the low byte
        uint16_t high = memory[0xFFFC + 1]; // we take the high byte
        pc = (high << 8) | low; // We are setting the low bit to the 8th bit
        sp = 0xFD; // setting and initializing stack ptr to known state
        x = 0x00;
        y = 0x00;
        ac = 0x00;
        ir = 0x00;
        status = 0x00 | Status::U; // setting status to unused state
        cycles = 8; // resetting time
    }


    uint8_t read(){
        uint8_t data = memory[pc] | (memory[pc+1] << 8);
        pc++;
        return data;
    }

    uint8_t& operator[](uint64_t address) {
        return memory[address];
    }

    uint16_t pc = 0x0000; // program counter
    // Stack can only be 256 bytes which is 0100 to 01FF
    // If stack ptr is out of range (in other words decrements lower then 0100 then overflow)
    uint8_t sp = 0x00; // stack pointer (points to location on bus)
    uint8_t x = 0x00; // x indexed register
    uint8_t y = 0x00; // y indexed register
    uint8_t ac = 0x00; // accumulator
    uint8_t ir = 0x00; // instruction register. Used during the fetch process. Containing the instruction we are gonna use for decoding
    uint8_t status; // Containing current statuses
    uint8_t cycles = 0; // Counts how meny cycles an instruction has remaining
    uint32_t clock_count = 0; // global accumulation of number of clocks
    std::array<uint8_t, 1024 * 64> memory; // contains virtual memory data
};