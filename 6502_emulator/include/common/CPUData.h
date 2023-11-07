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
        memory[0x03] = 0xA9;
        // setting reset vector at 0xFFFC and 0xFFFD
        memory[0xFFFC] = 0x0000;
        memory[0xFFFC] = 0x0001;
    }

    // resetting these registers to a known state
    void reset(){
        // pc = 0x0000;
        // sp = 0x00;
        // x = 0x00;
        // y = 0x00;
        // ac = 0x00;
        // ir = 0x00;
        uint16_t low = memory[0xFFFC + 0];
        uint16_t high = memory[0xFFFC + 1];
        pc = (high << 8) | low; // We are setting the low bit to the 8th bit
        sp = 0xFD; // setting and initializing stack ptr to known state
        x = 0x00;
        y = 0x00;
        ac = 0x00;
        ir = 0x00;
        status = 0x00 | Status::U; // setting status to unused state
        cycles = 8; // resetting time
    }

    uint8_t& operator[](uint64_t address) {
        return memory[address];
    }

    uint16_t pc = 0x0000; // program counter
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