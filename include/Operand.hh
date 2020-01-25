/*
** EPITECH PROJECT, 2020
** Operand.hh
** File description:
** ...
*/

#ifndef _OPERAND_HH_
#define _OPERAND_HH_

#include "abstractvm.hh"
#include "IOperand.hh"
#include "Memory.hh"
#include "CPU.hh"
#include "eOperandType.hh"

class CPU;

class Operand : public IOperand
{
public:
    Operand(eOperandType type, std::string value);
    ~Operand();
    void setOperandCmd(Operand *operand);
    std::string toString() const override;
    eOperandType getType() override;
    std::string getValue() override;
    void setValue(std::string&) override;
    void setType(eOperandType) override;
    void debug_obj() override;
    std::map<std::string, void (Operand::*)(Memory, CPU)> getOperandCmd();
    void add(Memory objMemory, CPU objCPU);
    void sub(Memory objMemory, CPU objCPU);
    void mul(Memory objMemory, CPU objCPU);
    void div(Memory objMemory, CPU objCPU);
    void mod(Memory objMemory, CPU objCPU);
    // eOperandType getType() const override;
    // void setType(std::string type, Operand *op) const override;
    // std::string getValue() const override;
    // void setValue(std::string newValue, Operand *op) const override;
    // IOperand *operator+(const IOperand &rhs) const override;
    // IOperand *operator-(const IOperand &rhs) const override;
    // IOperand *operator*(const IOperand &rhs) const override;
    // IOperand *operator/(const IOperand &rhs) const override;
    // IOperand *operator%(const IOperand &rhs) const override;
private:
    std::map<std::string, void (Operand::*)(Memory, CPU)> cmdOperand;
    CPU *_cpu;
    std::string value;
    eOperandType type;
};

#endif
