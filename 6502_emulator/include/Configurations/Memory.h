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
 * 1.) RAM (Random Access Memory)
 * - Volatile memory, means when data is lost when the CPU is turned off.
 * 
 * 2.) ROM (Read Only Memory)
 * - Generally holds firmware or permanent code that cannot be modified during runtime
 * 
 * 
 * NOTE:
 * - 6502 CPU supports up to 64kb of memory.
 * - Which is the size of RAM, and ROM memory array.
 * 
 * 
 * 
 * NOTE:
 * 
*/

/**
 * 
 * 
 *  ----[Memory Visualization]---
    +---------------------------+
    |                           |
    |          RAM              |
    |                           |
    |      (0x0000 - 0x1FFF)    |
    |                           |
    +---------------------------+
    |                           |
    |      Mirrors of RAM       |
    |                           |
    |  (0x2000 - 0x3FFF)        |
    |                           |
    +---------------------------+
    |                           |
    |      I/O Registers        |
    |                           |
    |  (0x4000 - 0x5FFF)        |
    |                           |
    +---------------------------+
    |                           |
    |         Expansion         |
    |                           |
    |  (0x6000 - 0x7FFF)        |
    |                           |
    +---------------------------+
    |                           |
    |           ROM             |
    |                           |
    |  (0x8000 - 0xFFFF)        |
    |                           |
    +---------------------------+
    |                           |
    |       Reset Vector        |
    |      (0xFFFC - 0xFFFD)    |
    |                           |
    +---------------------------+
 * 
*/

/**
 * 
 * 
 * Memory is memory
 * - When we have different regions of memory means that we are not having seperate arrays
 * - They are contained into one array of memory, with just specific ranges in that array allocated only specific regions.
 * 
*/

class Memory{
public:
   // allocating and initialize memory
   void allocate(){}

   // reading to memory
   void read(uint64_t address){}

   // writing to memory
   void write(uint64_t address, uint64_t value){}

   // accessing memory through the operator[]
   uint64_t operator[](std::size_t index){
      return memory[index];
   }
private:
   std::array<uint64_t, 65536> memory;
};