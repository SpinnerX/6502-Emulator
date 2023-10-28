#pragma once
#include <cstdint>
#include <type_traits>

// Aliasing types
// 1 byte = 8 bits
// 2 bytes = 16 bits
using Byte = uint8_t;
using Bytes2 = uint16_t;
using u8 = uint8_t;
using u16 = uint16_t;
using opcode_t = uint8_t;

using hex_t = unsigned char;


/**
 * 
 * Containing types that'll be recognize and used in this emulator.
 * 
 * External @note
 * 
 * This instruction struct is not to contain any functions
 * - Struct is to represent the different instructions we are executing
 * - Containing information about those executed instructions, included cycles, opcodes, address modes, etc.
 * 
 * 
 * START: @note
 * 
 * - Only the Instructions class shhould know what type this instruction
 * - Such as what kind 
 * 
 * END: @note
 * 
 * 
*/

enum class RegisterTypes{
    // Main core instructions reserved for the CPU
    PC, // program counter (16 bits)
    SP, // stack pointer (8 bits)
    AC, // Accumulator (8 bits)
    X, // index register (8 bits)
    Y, // index register (8 bits)

    // below here are status flags
    // Deciding on whether these may be needed
    C,
    Z,
    I,
    D,
    V,
    N,

    // Instructions names used by the assembler
    ADC, // ....    add with carry
    AND, // ....    And (with accumulator)
    ASL, // ....    Arithmetic Shift Left
    BCC, // ....    branch on carry clear
    BCS, // ....    branch on carry set
    BEQ, // ....    branchh on equal (zero set)
    BIT, // ....    bit test
    BMI, // ....    branch on minus (negative set)
    BNE, // ....    branch on not equal (zero clear)
    BPL, // ....    branch on plus (negative clear)
    BRK, // ....    break / interrupt
    BVC, // ....    branch on overflow clear
    BVS, // ....    branchh on overflow set
    CLC, // ....    clear carry
    CLD, // ....    clear decimal
    CLI, // ....    clear interrupt disable
    CLV, // ....    clear overflow
    CMP, // ....    compare (with accumulator)
    CPX, // ....    compare with X
    CPY, // ....    compare with Y
    DEC, // ....    decrement
    DEX, // ....    decrement with X
    DEY, // ....    decrement with Y
    EOR, // ....    exclusive OR (with accumulator)
    INC, // ....    increment
    INX, // ....    increment X
    INY, // ....    increment Y
    JMP, // ....    jump
    JSR, // ....    jump subroutine
    LDA, // ....    load accumulator
    LDX, // ....    load X
    LDY, // ....    load Y
    LSR, // ....    logical shift right
    NOP, // ....    no operation
    ORA, // ....    or withh accumulator
    PHA, // ....    push accumualator
    PHP, // ....    push process status (SR)
    PLA, // ....    pull accumulator
    PLP, // ....    pull processor status (SR)
    ROL, // ....    rotate left
    ROR, // ....    rotate right
    RTI, // ....    return from interrupt
    RTS, // ....    return from subroutine
    SBC, // ....    subtract with carry
    SEC, // ....    set carry
    SED, // ....    set decimal
    SEI, // ....    set interrupt disable
    STA, // ....    store accumulator
    STX, // ....    store X
    STY, // ....    store Y
    TAX, // ....    transfer accumulator to X
    TAY, // ....    transfer accumulator to Y
    TSX, // ....    transfer stack  pointer to X
    TXA, // ....    transfer X to accumulator
    TXS, // ....    transfer X to stack pointer
    TYA, // ....    transfer Y to accumulator
    DEFAULT = -1 // .... default value
};

/**
 * 
 * Check Address Modes in this link: https://www.masswerk.at/6502/6502_instruction_set.html
 * 
*/
enum class AddressModes{
    A,                  // Accumulator address mode
    ABS,                // Absolute
    ABSX,               // Absolute, X => Absolute, X-indexed
    ABSY,               // Absolute, Y => Absolute, Y-indexed
    IMMEDIATE,          // means immediate
    IMPLIED,               // implied
    IND,                // indirect
    INDIRECT_X,         // x-indexed, indirect
    INDIRECT_Y,         // indirect, y-indexed
    REL,                // Relative
    ZPG,                // zeropage
    ZPG_X,              // Zeropage, X-indexed
    ZPG_Y,              // Zeropage, Y-indexed
    NOT_FOUND,          // Indicating Address is not found.
};

// Different states that the CPU will be in.
enum State{
    ON, // starting up (booting up the CPU)
    RESET, // resetting the CPU
    RUNNING, // CPU still running
    QUIT, // If the CPU has been quit
    OFF
};

enum MemoryRegions{
    RandomAccessMemory,
    ReadOnlyMemory
};
