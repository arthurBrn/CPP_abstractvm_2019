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
    std::string getValue();
    void setValue(std::string newValue);
    void setOperandCmd(Operand *operand);
    std::string toString() const override;
    eOperandType getType();
    void setType(eOperandType type);
    std::map<std::string, void (Operand::*)(Memory, CPU)> getOperandCmd();
    void add(Memory objMemory, CPU objCPU);
    void sub(Memory objMemory, CPU objCPU);
    void mul(Memory objMemory, CPU objCPU);
    void div(Memory objMemory, CPU objCPU);
    void mod(Memory objMemory, CPU objCPU);
    // IOperand *operator+(const IOperand &rhs) const override;
    // IOperand *operator-(const IOperand &rhs) const override;
    // IOperand *operator*(const IOperand &rhs) const override;
    // IOperand *operator/(const IOperand &rhs) const override;
    // IOperand *operator%(const IOperand &rhs) const override;
private:
    std::map<std::string, void (Operand::*)(Memory, CPU)> cmdOperand;
    std::string value;
    eOperandType type;
    CPU *_cpu;
};

#endif
