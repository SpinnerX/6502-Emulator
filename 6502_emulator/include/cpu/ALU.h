#pragma once
#include <array>
#include <bitset>

/**
 * @brief 
 * 
 * ALU: Arithmetic Logic Unit
 * - Will handle arithmetic operations
 * - Operations: Additions, Subtraction, Multiplication
 * - Logic Operations: Increment, Decrement, Shifting, Branching
 * 
 * 
 * Functionality (Such as idea on how the ALU will work)
 * - ALU takes in two inputs such as two registers
 * - Considering the following operations:
 * => Adder, OR, XOR, AND, Right and Left shifting, Carry Out, and Overflow
 * - The ALU will produce the output, which will load the output to another register
 * 
 * 
 */


struct ALU{



    std::array<uint8_t, 1024 * 64> buffer; 
};