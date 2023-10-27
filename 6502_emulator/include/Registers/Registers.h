#pragma once
#include <type_traits>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <common/types.h>
#include <Registers/RegisterTraits.h>
#include <formatCpp/formatCpp.h>

struct BaseRegister{
    virtual InstructionTraits data() = 0;
    AddressModes mode;
    InstructionTraits traits;
    InstructionStatus status; // SR Statuses
};


template<opcode_t opcode = 0>
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
        traits = InstructionTraits(RegisterTypes::LDA, AddressModes::IMMEDIATE, 0xA9, 2, 2);
    }

    void execute(opcode_t opcode){
        formatCpp::print("0xA9 execute()\n");
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xA9>& ins){
        return outs << ins.traits;
    }

    InstructionTraits data() override{
        return traits;
    }
};

template<>
struct Register<0xA5> : public BaseRegister{
    Register<0xA5>(){
        traits = InstructionTraits(RegisterTypes::LDA, AddressModes::ZPG, 0xA5, 2, 3);
    }

    void execute(){
        formatCpp::print("0xA5 execute()\n");
    }

    InstructionTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xA5>& ins){
        return outs;
    }
};

template<>
struct Register<0xB5> : public BaseRegister{
     Register<0xB5>(){
        traits = InstructionTraits(RegisterTypes::LDA, AddressModes::ZPG_X, 0xA5, 2, 4);
    }

    void execute(){
        formatCpp::print("0xB5 execute()\n");
    }

    InstructionTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xB5>& ins){
        return outs;
    }
};


template<>
struct Register<0xAD> : public BaseRegister{
     Register<0xAD>(){
        traits = InstructionTraits(RegisterTypes::LDA, AddressModes::ABS, 0xAD, 3, 4);
    }

    void execute(){
        formatCpp::print("0xAD execute()\n");
    }

    InstructionTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xAD>& ins){
        return outs;
    }
};

template<>
struct Register<0xBD> : public BaseRegister{
     Register<0xBD>(){
        traits = InstructionTraits(RegisterTypes::LDA, AddressModes::ABSX, 0xBD, 3, 4);
    }

    void execute(){
        formatCpp::print("0xBD execute()\n");
    }

    InstructionTraits data() override {
        formatCpp::print("0xBD data()\n");
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xBD>& ins){
        return outs;
    }
};

template<>
struct Register<0xB9> : public BaseRegister{
     Register<0xB9>(){
        traits = InstructionTraits(RegisterTypes::LDA, AddressModes::ABSY, 0xB9, 3, 4);
    }

    void execute(){
        formatCpp::print("0xB9 execute()\n");
    }

    InstructionTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xB9>& ins){
        return outs;
    }
};


template<>
struct Register<0xA1> : public BaseRegister{
     Register<0xA1>(){
        traits = InstructionTraits(RegisterTypes::LDA, AddressModes::INDIRECT_X, 0xA1, 2, 6);
    }

    void execute(){
        formatCpp::print("0xA1 execute()\n");
    }

    InstructionTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xA1>& ins){
        return outs;
    }
};

template<>
struct Register<0xB1> : public BaseRegister{
     Register<0xB1>(){
        traits = InstructionTraits(RegisterTypes::LDA, AddressModes::INDIRECT_Y, 0xB1, 2, 5);
    }

    void execute(){
        formatCpp::print("0xB1 execute()\n");
    }

    InstructionTraits data() override {
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
        traits = InstructionTraits(RegisterTypes::LDX, AddressModes::IMMEDIATE, 0xA2, 2, 2);
    }

    void execute(){
        formatCpp::print("0xA2 execute()\n");
    }

    InstructionTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xA2>& ins){
        return outs;
    }
};

template<>
struct Register<0xA6> : public BaseRegister{
     Register<0xA6>(){
        traits = InstructionTraits(RegisterTypes::LDX, AddressModes::ZPG, 0xA6, 2, 3);
    }

    void execute(){
        formatCpp::print("0xA6 execute()\n");
    }

    InstructionTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xA6>& ins){
        return outs;
    }
};

template<>
struct Register<0xB6> : public BaseRegister{
     Register<0xB6>(){
        traits = InstructionTraits(RegisterTypes::LDX, AddressModes::ZPG_Y, 0xB6, 2, 2);
    }

    void execute(){
        formatCpp::print("0xB6 execute()\n");
    }

    InstructionTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xB6>& ins){
        return outs;
    }
};



template<>
struct Register<0xAE> : public BaseRegister{
     Register<0xAE>(){
        traits = InstructionTraits(RegisterTypes::LDX, AddressModes::ABS, 0xAE, 2, 2);
    }

    void execute(){
        formatCpp::print("0xAE execute()\n");
    }

    InstructionTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xAE>& ins){
        return outs;
    }
};


template<>
struct Register<0xBE> : public BaseRegister{
     Register<0xBE>(){
        traits = InstructionTraits(RegisterTypes::LDX, AddressModes::ABSY, 0xBE, 2, 2);
    }

    void execute(){
        formatCpp::print("0xBE execute()\n");
    }

    InstructionTraits data() override {
        return traits;
    }

    friend std::ostream& operator<<(std::ostream& outs, Register<0xBE>& ins){
        return outs;
    }
};






