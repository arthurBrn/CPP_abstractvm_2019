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
    IOperand *operator+(const IOperand& rhs) const override;
    IOperand *operator-(const IOperand& rhs) const override;
    IOperand *operator*(const IOperand& rhs) const override;
    IOperand *operator/(const IOperand& rhs) const override;
    IOperand *operator%(const IOperand& rhs) const override;
    double create_nb_1() const;
    std::string toString() const override;
    eOperandType getType() const override;
    std::string getValue() const override;
    void setValue(std::string&) override;
    void setType(eOperandType) override;
    void debug_obj() override;
private:
    CPU *_cpu;
    std::string value;
    eOperandType type;
};

#endif
