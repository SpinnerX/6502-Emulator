#pragma once
#include <cstring>
#include <cstdlib>
#include <common/types.h>
#include <memory>
#include <array>

/**
 * 
 * Since we know that its all memory
 * - We need to specify which region of memory we may want to read, write, and fetch
 * - Therefore we create a few specializsed template classes/structs
 * - Since we know RAM is random access memory allows to read and write
 * - And ROM allows to only read in memory.
 * 
*/

template<MemoryRegions region>
class Memory;

template<>
class Memory<MemoryRegions::RandomAccessMemory>{
public:
    Memory<MemoryRegions::RandomAccessMemory>() = default;
    
    // read memory
    uint16_t read(uint16_t address){
        return memory[address];
    }

    // write memory
    void write(uint16_t address, uint16_t value){
        memory[address] = value;
    }

    std::array<uint16_t, 65536> memory;
};

template<>
class Memory<MemoryRegions::ReadOnlyMemory>{
public:
    Memory<MemoryRegions::ReadOnlyMemory>() = default;
    
    // read memory
    uint16_t read(uint16_t address){
        return memory[address];
    }

    std::array<uint16_t, 65536> memory;
};