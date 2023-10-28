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

