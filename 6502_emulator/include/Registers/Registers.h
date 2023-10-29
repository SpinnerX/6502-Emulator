#pragma once
#include <type_traits>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <common/types.h>
#include <Registers/RegisterTraits.h>


/***
 * 
 * 
 * Registers Types
 * - Reason why we want to access these specicifc registers based on opcodes is because of the fetch-cycle.
 * - Through the fetch, decode, execute cycle we use opcodes to search which instruction we want to execute.
 * - That is how the cycle process will look to when trying to check which instruction to execute.
 * 
*/


struct BaseRegister{
    virtual RegisterTraits data() = 0;
    AddressModes mode;
    RegisterTraits traits;
    InstructionStatus status; // SR Statuses
};


template<auto opcode = 0>
struct Register;




/**
 * 
 * Load, store, interregister transfer registers
 * 
*/


/**
 * 
 * 
 * LDA
 * -  Immediate
 * - ZeroPage
 * - ZeroPageX
 * - Absolute
 * - Absolute  X
 * - Absolute Y
 * -  Indirect X
 * - Indirect Y
 * 
 * 
*/

template<>
struct Register<0xA9> : public BaseRegister{
    Register<0xA9>(){
        traits = RegisterTraits(RegisterTypes::LDA, AddressModes::IMMEDIATE, 0xA9, 2, 2);
    }

    void execute(opcode_t opcode){
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xA9>& ins){
        return outs << ins.traits;
    }

    RegisterTraits data() override{
        return traits;
    }
};

template<>
struct Register<0xA5> : public BaseRegister{
    Register<0xA5>(){
        traits = RegisterTraits(RegisterTypes::LDA, AddressModes::ZPG, 0xA5, 2, 3);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xA5>& ins){
        return outs;
    }
};

template<>
struct Register<0xB5> : public BaseRegister{
     Register<0xB5>(){
        traits = RegisterTraits(RegisterTypes::LDA, AddressModes::ZPG_X, 0xA5, 2, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xB5>& ins){
        return outs;
    }
};


template<>
struct Register<0xAD> : public BaseRegister{
     Register<0xAD>(){
        traits = RegisterTraits(RegisterTypes::LDA, AddressModes::ABS, 0xAD, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xAD>& ins){
        return outs;
    }
};

template<>
struct Register<0xBD> : public BaseRegister{
     Register<0xBD>(){
        traits = RegisterTraits(RegisterTypes::LDA, AddressModes::ABSX, 0xBD, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xBD>& ins){
        return outs;
    }
};

template<>
struct Register<0xB9> : public BaseRegister{
     Register<0xB9>(){
        traits = RegisterTraits(RegisterTypes::LDA, AddressModes::ABSY, 0xB9, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xB9>& ins){
        return outs;
    }
};


template<>
struct Register<0xA1> : public BaseRegister{
     Register<0xA1>(){
        traits = RegisterTraits(RegisterTypes::LDA, AddressModes::INDIRECT_X, 0xA1, 2, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xA1>& ins){
        return outs;
    }
};

template<>
struct Register<0xB1> : public BaseRegister{
     Register<0xB1>(){
        traits = RegisterTraits(RegisterTypes::LDA, AddressModes::INDIRECT_Y, 0xB1, 2, 5);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xB1>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * LDX
 * - Immediate
 * - ZeroPage
 * - ZeroPage Y
 * - Absolute
 * - Absolute Y
 * 
*/


template<>
struct Register<0xA2> : public BaseRegister{
     Register<0xA2>(){
        traits = RegisterTraits(RegisterTypes::LDX, AddressModes::IMMEDIATE, 0xA2, 2, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xA2>& ins){
        return outs;
    }
};

template<>
struct Register<0xA6> : public BaseRegister{
     Register<0xA6>(){
        traits = RegisterTraits(RegisterTypes::LDX, AddressModes::ZPG, 0xA6, 2, 3);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xA6>& ins){
        return outs;
    }
};

template<>
struct Register<0xB6> : public BaseRegister{
     Register<0xB6>(){
        traits = RegisterTraits(RegisterTypes::LDX, AddressModes::ZPG_Y, 0xB6, 2, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xB6>& ins){
        return outs;
    }
};



template<>
struct Register<0xAE> : public BaseRegister{
     Register<0xAE>(){
        traits = RegisterTraits(RegisterTypes::LDX, AddressModes::ABS, 0xAE, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xAE>& ins){
        return outs;
    }
};


template<>
struct Register<0xBE> : public BaseRegister{
     Register<0xBE>(){
        traits = RegisterTraits(RegisterTypes::LDX, AddressModes::ABSY, 0xBE, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xBE>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * LDY (Load Index Y with Memory)
 * - Immediate
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/

template<>
struct Register<0xA0> : public BaseRegister{
     Register<0xA0>(){
        traits = RegisterTraits(RegisterTypes::LDY, AddressModes::IMMEDIATE, 0xA0, 2, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xA0>& ins){
        return outs;
    }
};

template<>
struct Register<0xA4> : public BaseRegister{
     Register<0xA4>(){
        traits = RegisterTraits(RegisterTypes::LDY, AddressModes::ZPG, 0xA4, 2, 3);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xA4>& ins){
        return outs;
    }
};

template<>
struct Register<0xB4> : public BaseRegister{
     Register<0xB4>(){
        traits = RegisterTraits(RegisterTypes::LDY, AddressModes::ZPG_X, 0xB4, 2, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xB4>& ins){
        return outs;
    }
};


template<>
struct Register<0xAC> : public BaseRegister{
     Register<0xAC>(){
        traits = RegisterTraits(RegisterTypes::LDY, AddressModes::ABS, 0xAC, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xAC>& ins){
        return outs;
    }
};

template<>
struct Register<0xBC> : public BaseRegister{
     Register<0xBC>(){
        traits = RegisterTraits(RegisterTypes::LDY, AddressModes::ABSX, 0xBC, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xBC>& ins){
        return outs;
    }
};






/**
 * 
 * 
 * STA (Store Accumulator in Memory)
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * - Indirect X
 * - Indirect Y
 * 
*/


template<>
struct Register<0x85> : public BaseRegister{
     Register<0x85>(){
        traits = RegisterTraits(RegisterTypes::STA, AddressModes::ZPG, 0x85, 2, 3);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x85>& ins){
        return outs;
    }
};

template<>
struct Register<0x95> : public BaseRegister{
     Register<0x95>(){
        traits = RegisterTraits(RegisterTypes::STA, AddressModes::ZPG_X, 0x95, 2, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x95>& ins){
        return outs;
    }
};


template<>
struct Register<0x8D> : public BaseRegister{
     Register<0x8D>(){
        traits = RegisterTraits(RegisterTypes::STA, AddressModes::ABS, 0x8D, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x8D>& ins){
        return outs;
    }
};

template<>
struct Register<0x9D> : public BaseRegister{
     Register<0x9D>(){
        traits = RegisterTraits(RegisterTypes::STA, AddressModes::ABSX, 0x9D, 3, 5);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x9D>& ins){
        return outs;
    }
};

template<>
struct Register<0x99> : public BaseRegister{
     Register<0x99>(){
        traits = RegisterTraits(RegisterTypes::STA, AddressModes::ABSY, 0x99, 3, 5);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x99>& ins){
        return outs;
    }
};

template<>
struct Register<0x81> : public BaseRegister{
     Register<0x81>(){
        traits = RegisterTraits(RegisterTypes::STA, AddressModes::INDIRECT_X, 0x81, 2, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x81>& ins){
        return outs;
    }
};

template<>
struct Register<0x91> : public BaseRegister{
     Register<0x91>(){
        traits = RegisterTraits(RegisterTypes::STA, AddressModes::INDIRECT_Y, 0x91, 2, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x91>& ins){
        return outs;
    }
};



/**
 * 
 * 
 * STX (Store Index X in Memory)
 * - ZeroPage
 * - ZeroPage Y
 * - Absolute
 * 
*/

template<>
struct Register<0x86> : public BaseRegister{
     Register<0x86>(){
        traits = RegisterTraits(RegisterTypes::STX, AddressModes::ZPG, 0x86, 2, 3);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x86>& ins){
        return outs;
    }
};

template<>
struct Register<0x96> : public BaseRegister{
     Register<0x96>(){
        traits = RegisterTraits(RegisterTypes::STX, AddressModes::ZPG_Y, 0x96, 2, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x96>& ins){
        return outs;
    }
};


template<>
struct Register<0x8E> : public BaseRegister{
     Register<0x8E>(){
        traits = RegisterTraits(RegisterTypes::STX, AddressModes::ABS, 0x8E, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x8E>& ins){
        return outs;
    }
};


/**
 * 
 * 
 * STY (Store Index Y in Memory)
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * 
*/


template<>
struct Register<0x84> : public BaseRegister{
     Register<0x84>(){
        traits = RegisterTraits(RegisterTypes::STY, AddressModes::ZPG, 0x84, 2, 3);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x84>& ins){
        return outs;
    }
};

template<>
struct Register<0x94> : public BaseRegister{
     Register<0x94>(){
        traits = RegisterTraits(RegisterTypes::STY, AddressModes::ZPG_X, 0x94, 2, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x94>& ins){
        return outs;
    }
};

template<>
struct Register<0x8C> : public BaseRegister{
     Register<0x8C>(){
        traits = RegisterTraits(RegisterTypes::STY, AddressModes::ABS, 0x8C, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x8C>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * TAX (Transfer Accumulator to Index X)
 * - IMPLIED
 * 
*/

template<>
struct Register<0xAA> : public BaseRegister{
     Register<0xAA>(){
        traits = RegisterTraits(RegisterTypes::TAX, AddressModes::IMPLIED, 0xAA, 1, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xAA>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * TAY (Transfer Accumulator to Index X)
 * - IMPLIED
 * 
*/

template<>
struct Register<0xA8> : public BaseRegister{
     Register<0xA8>(){
        traits = RegisterTraits(RegisterTypes::TAY, AddressModes::IMPLIED, 0xA8, 1, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xA8>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * TSX (Transfer Stack Ptr to Index X)
 * - IMPLIED
 * 
*/

template<>
struct Register<0xBA> : public BaseRegister{
     Register<0xBA>(){
        traits = RegisterTraits(RegisterTypes::TSX, AddressModes::IMPLIED, 0xBA, 1, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xBA>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * TXA (Transfer Index X to Accumulator)
 * - IMPLIED
 * 
*/

template<>
struct Register<0x8A> : public BaseRegister{
     Register<0x8A>(){
        traits = RegisterTraits(RegisterTypes::TXA, AddressModes::IMPLIED, 0x8A, 1, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x8A>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * TXS (Transfer Index X to Stack Register)
 * - IMPLIED
 * 
*/

template<>
struct Register<0x9A> : public BaseRegister{
     Register<0x9A>(){
        traits = RegisterTraits(RegisterTypes::TXS, AddressModes::IMPLIED, 0x9A, 1, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x9A>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * TYA (Transfer Index Y to Accumulator)
 * - IMPLIED
 * 
*/

template<>
struct Register<0x98> : public BaseRegister{
     Register<0x98>(){
        traits = RegisterTraits(RegisterTypes::TYA, AddressModes::IMPLIED, 0x98, 1, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x98>& ins){
        return outs;
    }
};


/**
 * 
 * 
 * Stack Instructions
 * 
 * 
 * 
*/


/**
 * 
 * PHA (Push Accumulator on Stack)
 * - IMPLIED
 * 
*/
template<>
struct Register<0x48> : public BaseRegister{
     Register<0x48>(){
        traits = RegisterTraits(RegisterTypes::PHA, AddressModes::IMPLIED, 0x48, 1, 3);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x48>& ins){
        return outs;
    }
};


/**
 * 
 * PHP (Push Processor Status on Stack)
 * - IMPLIED
 * 
*/
template<>
struct Register<0x08> : public BaseRegister{
     Register<0x08>(){
        traits = RegisterTraits(RegisterTypes::PHP, AddressModes::IMPLIED, 0x08, 1, 3);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x08>& ins){
        return outs;
    }
};

/**
 * 
 * PLA (Pull Processor Status from Stack)
 * - IMPLIED
 * 
*/
template<>
struct Register<0x68> : public BaseRegister{
     Register<0x68>(){
        traits = RegisterTraits(RegisterTypes::PLA, AddressModes::IMPLIED, 0x68, 1, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x68>& ins){
        return outs;
    }
};


/**
 * 
 * PLP (Pull Processor Status from Stack)
 * - IMPLIED
 * 
*/
template<>
struct Register<0x28> : public BaseRegister{
     Register<0x28>(){
        traits = RegisterTraits(RegisterTypes::PLP, AddressModes::IMPLIED, 0x28, 1, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x28>& ins){
        return outs;
    }
};




/** Decrement * Increments **/

/**
 * 
 * DEC (Decrement Memory by One)
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/

template<>
struct Register<0xC6> : public BaseRegister{
     Register<0xC6>(){
        traits = RegisterTraits(RegisterTypes::DEC, AddressModes::ZPG, 0xC6, 2, 5);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xC6>& ins){
        return outs;
    }
};

template<>
struct Register<0xD6> : public BaseRegister{
     Register<0xD6>(){
        traits = RegisterTraits(RegisterTypes::DEC, AddressModes::ZPG_X, 0xD6, 2, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xD6>& ins){
        return outs;
    }
};

template<>
struct Register<0xCE> : public BaseRegister{
     Register<0xCE>(){
        traits = RegisterTraits(RegisterTypes::DEC, AddressModes::ABS, 0xCE, 3, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xCE>& ins){
        return outs;
    }
};

template<>
struct Register<0xDE> : public BaseRegister{
     Register<0xDE>(){
        traits = RegisterTraits(RegisterTypes::DEC, AddressModes::ABSX, 0xDE, 3, 7);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xDE>& ins){
        return outs;
    }
};



/**
 * 
 * DEX (Decrement Index X by One)
 * - IMPLIED
 * 
*/

template<>
struct Register<0xCA> : public BaseRegister{
     Register<0xCA>(){
        traits = RegisterTraits(RegisterTypes::DEX, AddressModes::IMPLIED, 0xCA, 1, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xCA>& ins){
        return outs;
    }
};


/**
 * 
 * DEY (Decrement Index Y by One)
 * - IMPLIED
 * 
*/

template<>
struct Register<0x88> : public BaseRegister{
     Register<0x88>(){
        traits = RegisterTraits(RegisterTypes::DEY, AddressModes::IMPLIED, 0x88, 1, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x88>& ins){
        return outs;
    }
};


/**
 * 
 * INC (Increment Memory By One)
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/

template<>
struct Register<0xE6> : public BaseRegister{
     Register<0xE6>(){
        traits = RegisterTraits(RegisterTypes::INC, AddressModes::ZPG, 0xE6, 2, 5);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xE6>& ins){
        return outs;
    }
};

template<>
struct Register<0xF6> : public BaseRegister{
     Register<0xF6>(){
        traits = RegisterTraits(RegisterTypes::INC, AddressModes::ZPG_X, 0xF6, 2, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xF6>& ins){
        return outs;
    }
};

template<>
struct Register<0xEE> : public BaseRegister{
     Register<0xEE>(){
        traits = RegisterTraits(RegisterTypes::INC, AddressModes::ABS, 0xEE, 3, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xEE>& ins){
        return outs;
    }
};

template<>
struct Register<0xFE> : public BaseRegister{
     Register<0xFE>(){
        traits = RegisterTraits(RegisterTypes::INC, AddressModes::ABSX, 0xFE, 3, 7);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xFE>& ins){
        return outs;
    }
};



/**
 * 
 * INX (Increment Index X by One)
 * - IMPLIED
 * 
*/

template<>
struct Register<0xE8> : public BaseRegister{
     Register<0xE8>(){
        traits = RegisterTraits(RegisterTypes::INX, AddressModes::IMPLIED, 0xE8, 1, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xE8>& ins){
        return outs;
    }
};


/**
 * 
 * INY (Increment Index Y by One)
 * - IMPLIED
 * 
*/

template<>
struct Register<0xC8> : public BaseRegister{
     Register<0xC8>(){
        traits = RegisterTraits(RegisterTypes::INY, AddressModes::IMPLIED, 0xC8, 1, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xC8>& ins){
        return outs;
    }
};




/**
 * 
 * ADC (Add Memory to Accumulator with Carry)
 * - IMMEDIATE
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * - Absolute Y
 * - Indirect X
 * - Indirect Y
 * 
*/

template<>
struct Register<0x69> : public BaseRegister{
     Register<0x69>(){
        traits = RegisterTraits(RegisterTypes::ADC, AddressModes::IMMEDIATE, 0x69, 2, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x69>& ins){
        return outs;
    }
};

template<>
struct Register<0x65> : public BaseRegister{
     Register<0x65>(){
        traits = RegisterTraits(RegisterTypes::ADC, AddressModes::ZPG, 0x65, 2, 3);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x65>& ins){
        return outs;
    }
};

template<>
struct Register<0x75> : public BaseRegister{
     Register<0x75>(){
        traits = RegisterTraits(RegisterTypes::ADC, AddressModes::ZPG_X, 0x75, 2, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x75>& ins){
        return outs;
    }
};

template<>
struct Register<0x6D> : public BaseRegister{
     Register<0x6D>(){
        traits = RegisterTraits(RegisterTypes::ADC, AddressModes::ABS, 0x6D, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x6D>& ins){
        return outs;
    }
};

template<>
struct Register<0x7D> : public BaseRegister{
     Register<0x7D>(){
        traits = RegisterTraits(RegisterTypes::ADC, AddressModes::ABSX, 0x7D, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x7D>& ins){
        return outs;
    }
};

template<>
struct Register<0x79> : public BaseRegister{
     Register<0x79>(){
        traits = RegisterTraits(RegisterTypes::ADC, AddressModes::ABSY, 0x79, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x79>& ins){
        return outs;
    }
};

template<>
struct Register<0x61> : public BaseRegister{
     Register<0x61>(){
        traits = RegisterTraits(RegisterTypes::ADC, AddressModes::INDIRECT_X, 0x61, 2, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x61>& ins){
        return outs;
    }
};

template<>
struct Register<0x71> : public BaseRegister{
     Register<0x71>(){
        traits = RegisterTraits(RegisterTypes::ADC, AddressModes::INDIRECT_Y, 0x71, 2, 5);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x71>& ins){
        return outs;
    }
};


/**
 * 
 * SBC (Subtract Memory from Accumulator with Borrow)
 * - IMMEDIATE
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * - Absolute Y
 * - Indirect X
 * - Indirect Y
 * 
*/
template<>
struct Register<0xE9> : public BaseRegister{
     Register<0xE9>(){
        traits = RegisterTraits(RegisterTypes::SBC, AddressModes::IMMEDIATE, 0xE9, 2, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xE9>& ins){
        return outs;
    }
};

template<>
struct Register<0xE5> : public BaseRegister{
     Register<0xE5>(){
        traits = RegisterTraits(RegisterTypes::SBC, AddressModes::ZPG, 0xE5, 2, 3);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xE5>& ins){
        return outs;
    }
};

template<>
struct Register<0xF5> : public BaseRegister{
     Register<0xF5>(){
        traits = RegisterTraits(RegisterTypes::SBC, AddressModes::ZPG_X, 0xF5, 2, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xF5>& ins){
        return outs;
    }
};

template<>
struct Register<0xED> : public BaseRegister{
     Register<0xED>(){
        traits = RegisterTraits(RegisterTypes::SBC, AddressModes::ABS, 0xED, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xED>& ins){
        return outs;
    }
};

template<>
struct Register<0xFD> : public BaseRegister{
     Register<0xFD>(){
        traits = RegisterTraits(RegisterTypes::SBC, AddressModes::ABSX, 0xFD, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xFD>& ins){
        return outs;
    }
};

template<>
struct Register<0xF9> : public BaseRegister{
     Register<0xF9>(){
        traits = RegisterTraits(RegisterTypes::SBC, AddressModes::ABSY, 0xF9, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xF9>& ins){
        return outs;
    }
};

template<>
struct Register<0xE1> : public BaseRegister{
     Register<0xE1>(){
        traits = RegisterTraits(RegisterTypes::SBC, AddressModes::INDIRECT_X, 0xE1, 2, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xE1>& ins){
        return outs;
    }
};

template<>
struct Register<0xF1> : public BaseRegister{
     Register<0xF1>(){
        traits = RegisterTraits(RegisterTypes::SBC, AddressModes::INDIRECT_Y, 0xF1, 2, 5);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xF1>& ins){
        return outs;
    }
};


/** Logical Operations **/

/**
 * 
 * AND (AND Memory with Accumulator)
 * - IMMEDIATE
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * - Absolute Y
 * - Indirect X
 * - Indirect Y
 * 
*/

template<>
struct Register<0x29> : public BaseRegister{
     Register<0x29>(){
        traits = RegisterTraits(RegisterTypes::AND, AddressModes::IMMEDIATE, 0x29, 2, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x29>& ins){
        return outs;
    }
};

template<>
struct Register<0x25> : public BaseRegister{
     Register<0x25>(){
        traits = RegisterTraits(RegisterTypes::AND, AddressModes::ZPG, 0x25, 2, 3);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x25>& ins){
        return outs;
    }
};

template<>
struct Register<0x35> : public BaseRegister{
     Register<0x35>(){
        traits = RegisterTraits(RegisterTypes::AND, AddressModes::ZPG_X, 0x35, 2, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x35>& ins){
        return outs;
    }
};

template<>
struct Register<0x2D> : public BaseRegister{
     Register<0x2D>(){
        traits = RegisterTraits(RegisterTypes::AND, AddressModes::ABS, 0x2D, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x2D>& ins){
        return outs;
    }
};

template<>
struct Register<0x3D> : public BaseRegister{
     Register<0x3D>(){
        traits = RegisterTraits(RegisterTypes::AND, AddressModes::ABSX, 0x3D, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x3D>& ins){
        return outs;
    }
};

template<>
struct Register<0x39> : public BaseRegister{
     Register<0x39>(){
        traits = RegisterTraits(RegisterTypes::AND, AddressModes::ABSY, 0x39, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x39>& ins){
        return outs;
    }
};

template<>
struct Register<0x21> : public BaseRegister{
     Register<0x21>(){
        traits = RegisterTraits(RegisterTypes::AND, AddressModes::INDIRECT_X, 0x21, 2, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x21>& ins){
        return outs;
    }
};

template<>
struct Register<0x31> : public BaseRegister{
     Register<0x31>(){
        traits = RegisterTraits(RegisterTypes::AND, AddressModes::INDIRECT_Y, 0x31, 2, 5);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x31>& ins){
        return outs;
    }
};



/**
 * 
 * EOR (Exclusive-OR Memory with Accumulator)
 * - IMMEDIATE
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * - Absolute Y
 * - Indirect X
 * - Indirect Y
 * 
*/

template<>
struct Register<0x49> : public BaseRegister{
     Register<0x49>(){
        traits = RegisterTraits(RegisterTypes::EOR, AddressModes::IMMEDIATE, 0x49, 2, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x49>& ins){
        return outs;
    }
};

template<>
struct Register<0x45> : public BaseRegister{
     Register<0x45>(){
        traits = RegisterTraits(RegisterTypes::EOR, AddressModes::ZPG, 0x45, 2, 3);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x45>& ins){
        return outs;
    }
};

template<>
struct Register<0x55> : public BaseRegister{
     Register<0x55>(){
        traits = RegisterTraits(RegisterTypes::EOR, AddressModes::ZPG_X, 0x55, 2, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x55>& ins){
        return outs;
    }
};

template<>
struct Register<0x4D> : public BaseRegister{
     Register<0x4D>(){
        traits = RegisterTraits(RegisterTypes::EOR, AddressModes::ABS, 0x4D, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x4D>& ins){
        return outs;
    }
};

template<>
struct Register<0x5D> : public BaseRegister{
     Register<0x5D>(){
        traits = RegisterTraits(RegisterTypes::EOR, AddressModes::ABSX, 0x5D, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x5D>& ins){
        return outs;
    }
};

template<>
struct Register<0x59> : public BaseRegister{
     Register<0x59>(){
        traits = RegisterTraits(RegisterTypes::EOR, AddressModes::ABSY, 0x59, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x59>& ins){
        return outs;
    }
};

template<>
struct Register<0x41> : public BaseRegister{
     Register<0x41>(){
        traits = RegisterTraits(RegisterTypes::EOR, AddressModes::INDIRECT_X, 0x41, 2, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x41>& ins){
        return outs;
    }
};

template<>
struct Register<0x51> : public BaseRegister{
     Register<0x51>(){
        traits = RegisterTraits(RegisterTypes::EOR, AddressModes::INDIRECT_Y, 0x51, 2, 5);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x51>& ins){
        return outs;
    }
};



/**
 * 
 * ORA (Or Memory with Accumulator)
 * - IMMEDIATE
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * - Absolute Y
 * - Indirect X
 * - Indirect Y
 * 
*/

template<>
struct Register<0x09> : public BaseRegister{
     Register<0x09>(){
        traits = RegisterTraits(RegisterTypes::ORA, AddressModes::IMMEDIATE, 0x09, 2, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x09>& ins){
        return outs;
    }
};

template<>
struct Register<0x05> : public BaseRegister{
     Register<0x05>(){
        traits = RegisterTraits(RegisterTypes::ORA, AddressModes::ZPG, 0x05, 2, 3);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x05>& ins){
        return outs;
    }
};

template<>
struct Register<0x15> : public BaseRegister{
     Register<0x15>(){
        traits = RegisterTraits(RegisterTypes::ORA, AddressModes::ZPG_X, 0x15, 2, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x15>& ins){
        return outs;
    }
};

template<>
struct Register<0x0D> : public BaseRegister{
     Register<0x0D>(){
        traits = RegisterTraits(RegisterTypes::ORA, AddressModes::ABS, 0x0D, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x0D>& ins){
        return outs;
    }
};

template<>
struct Register<0x1D> : public BaseRegister{
     Register<0x1D>(){
        traits = RegisterTraits(RegisterTypes::ORA, AddressModes::ABSX, 0x1D, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x1D>& ins){
        return outs;
    }
};

template<>
struct Register<0x19> : public BaseRegister{
     Register<0x19>(){
        traits = RegisterTraits(RegisterTypes::ORA, AddressModes::ABSY, 0x19, 3, 4);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x19>& ins){
        return outs;
    }
};

template<>
struct Register<0x01> : public BaseRegister{
     Register<0x01>(){
        traits = RegisterTraits(RegisterTypes::ORA, AddressModes::INDIRECT_X, 0x01, 2, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x01>& ins){
        return outs;
    }
};

template<>
struct Register<0x11> : public BaseRegister{
     Register<0x11>(){
        traits = RegisterTraits(RegisterTypes::ORA, AddressModes::INDIRECT_Y, 0x11, 2, 5);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x11>& ins){
        return outs;
    }
};




/** Shihft & Rotate Instructions **/

/**
 * 
 * ASL (Shift Left One Bit(Memory or Accumulator) )
 * - Accumulator (A)
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/


template<>
struct Register<0x0A> : public BaseRegister{
     Register<0x0A>(){
        traits = RegisterTraits(RegisterTypes::ASL, AddressModes::A, 0x0A, 1, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x0A>& ins){
        return outs;
    }
};


template<>
struct Register<0x06> : public BaseRegister{
     Register<0x06>(){
        traits = RegisterTraits(RegisterTypes::ASL, AddressModes::ZPG, 0x06, 2, 5);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x06>& ins){
        return outs;
    }
};

template<>
struct Register<0x16> : public BaseRegister{
     Register<0x16>(){
        traits = RegisterTraits(RegisterTypes::ASL, AddressModes::ZPG_X, 0x16, 2, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x16>& ins){
        return outs;
    }
};

template<>
struct Register<0x0E> : public BaseRegister{
     Register<0x0E>(){
        traits = RegisterTraits(RegisterTypes::ASL, AddressModes::ABS, 0x0E, 3, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x0E>& ins){
        return outs;
    }
};

template<>
struct Register<0x1E> : public BaseRegister{
     Register<0x1E>(){
        traits = RegisterTraits(RegisterTypes::ASL, AddressModes::ABSX, 0x1E, 3, 7);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x1E>& ins){
        return outs;
    }
};

/**
 * 
 * 
 * LSR (Shift One Bit Right ** Memory or Accumulator **)
 * - Immediate
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/

template<>
struct Register<0x4A> : public BaseRegister{
     Register<0x4A>(){
        traits = RegisterTraits(RegisterTypes::LSR, AddressModes::A, 0x4A, 1, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x4A>& ins){
        return outs;
    }
};

template<>
struct Register<0x46> : public BaseRegister{
     Register<0x46>(){
        traits = RegisterTraits(RegisterTypes::LSR, AddressModes::ZPG, 0x46, 2, 5);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x46>& ins){
        return outs;
    }
};

template<>
struct Register<0x56> : public BaseRegister{
     Register<0x56>(){
        traits = RegisterTraits(RegisterTypes::LSR, AddressModes::ZPG_X, 0x56, 2, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x56>& ins){
        return outs;
    }
};

template<>
struct Register<0x4E> : public BaseRegister{
     Register<0x4E>(){
        traits = RegisterTraits(RegisterTypes::LSR, AddressModes::ABS, 0x4E, 3, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x4E>& ins){
        return outs;
    }
};

template<>
struct Register<0x5E> : public BaseRegister{
     Register<0x5E>(){
        traits = RegisterTraits(RegisterTypes::LSR, AddressModes::ABSX, 0x5E, 3, 7);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x5E>& ins){
        return outs;
    }
};


/**
 * 
 * ROL (Rotate One Bit Left (Memory or Accumulator) )
 * - Accumulator (A)
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/

template<>
struct Register<0x2A> : public BaseRegister{
     Register<0x2A>(){
        traits = RegisterTraits(RegisterTypes::ROL, AddressModes::A, 0x2A, 1, 2);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x2A>& ins){
        return outs;
    }
};

template<>
struct Register<0x26> : public BaseRegister{
     Register<0x26>(){
        traits = RegisterTraits(RegisterTypes::ROL, AddressModes::ZPG, 0x26, 2, 5);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x26>& ins){
        return outs;
    }
};

template<>
struct Register<0x36> : public BaseRegister{
     Register<0x36>(){
        traits = RegisterTraits(RegisterTypes::ROL, AddressModes::ZPG_X, 0x36, 2, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x36>& ins){
        return outs;
    }
};

template<>
struct Register<0x2E> : public BaseRegister{
     Register<0x2E>(){
        traits = RegisterTraits(RegisterTypes::ROL, AddressModes::ABS, 0x2E, 3, 6);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x2E>& ins){
        return outs;
    }
};

template<>
struct Register<0x3E> : public BaseRegister{
     Register<0x3E>(){
        traits = RegisterTraits(RegisterTypes::ROL, AddressModes::ABSX, 0x3E, 3, 7);
    }

    void execute(){
    }

    RegisterTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0x3E>& ins){
        return outs;
    }
};
