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
 * 
 * Operations
 * 
 * 
 * ADC (addition)
 * - Which calls the adder in the ALU
 * 
 * 
 * SBC (subtraction)
 * - Does subtraction, but is another form of addition initially
 * 
 * - ALU takes two inputs which are reg1 and reg2.
 * - Adder contains register substructure
 * 
 * Control FLow (Surrounding the ALU using registers)
 * 
 * ** Input Register 1 (is A) **
 * - Receives input from system bus (SB) of 6502.
 * - This reg has two control signals: SB/ADD and 0/ADD
 * - 0/ADD signal "zeroes out" input reg A by connecting all its data inputs into ground
 * - Input Register 1 only output its 8-bit data output, which directly connected to ALU
 *   and is "always on", meanining no signal to enable/disable registers output
 * 
 * ** Input Register 2 **
 * - Receives data input from either data bus (DB) or low address bus (ADL) of 6502.
 * - Register has three control input signals: DB/ADD, DB/ADD, and ADL?ADD
 * NOTE: "DB/ADD" should properly render with bar over "DB" portions to indicate inversion
 * => DB/ADD signal when active loads content of data bus into register 2 (is B)
 * => /DB/ADD signal loads inverted contents of data bus into input register 2 (is B); accomplishing
 *   with a bank of inverters .
 * => ADL/ADD signal loads contents of low address bus into input register 2 (is B).
 *      - Like input register 1 (is A), input reg 2 (B) has only one output: it's 8-bit data output
 *      - Which directly connected to the ALU and is "always on", meaning no signal to enable/disable regs output.
 * => Adder Hold Register (ADD) - receives output from the ALU
 *      - register is clocked by 6502's internal PHI2 clock signal, meaning that when PHI2 becomes active,
 *        contents of ALU are loaded into the ADD.
 *      - ADD has three output input signals, each of which control its output: ADD/ADL, ADD/SB(0-6), ADD/SB(7).
 *      => ADD/ADL signal when active, outputs contents of ADD onto low address bus (ADL) of the 6502.
 *      => ADD/SB(0-6) signal outputs the low seven bits of the ADD onto the system bus (SB) of 6502.
 *      => ADD/SB(7) signal outputs the highest bit of ADD onto the system bus(SB) of 6502.
 * 
 * DEFINITION: Inverters - are electronic devices that can turn DC(Direct Current) to AC (Alternative Current)
 *             - Also responsible for controlling speed and torque for electric motors
 * 
 * 
 * Register 1 (A) Substructure
 * - Substructure of ALU's input register 1 (A) consists of five chips: 74347 chip which constitutes actual 1(A) register itself
 * - Two, 74244 buffer chips, a 7404 NOT gate (inverter) chip, and a 7432 OR gate chip.
 * - 
 * 
 * 
 * 
 * 
 * 
 */


struct ALU{
    uint8_t registerInput1;
    uint8_t registerInput2;


    std::array<uint8_t, 1024 * 64> buffer; 
};