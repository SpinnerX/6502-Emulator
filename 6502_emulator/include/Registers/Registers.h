#pragma once
#include <type_traits>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <common/types.h>
#include <Registers/RegisterTraits.h>

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
        traits = RegisterTraits(RegisterTypes::TAX, AddressModes::IMPLIED, 0xA8, 1, 2);
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
        traits = RegisterTraits(RegisterTypes::TAX, AddressModes::IMPLIED, 0xBA, 1, 2);
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
        traits = RegisterTraits(RegisterTypes::TAX, AddressModes::IMPLIED, 0x8A, 1, 2);
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
        traits = RegisterTraits(RegisterTypes::TAX, AddressModes::IMPLIED, 0x9A, 1, 2);
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
        traits = RegisterTraits(RegisterTypes::TAX, AddressModes::IMPLIED, 0x98, 1, 2);
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
 * LSR (Shift One Bit Right ** Memory or Accumulator **)
 * - Immediate
 * - ZeroPage
 * - ZeroPage X
 * - Absolute
 * - Absolute X
 * 
*/

/*
* LSR Implementation may come back to this
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

*/