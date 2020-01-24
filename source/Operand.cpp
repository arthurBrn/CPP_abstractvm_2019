/*
** EPITECH PROJECT, 2019
** source/IOperand.cpp
** File description:
** IOperand file
*/

#include <stdexcept>
#include "abstractvm.hh"
#include "IOperand.hh"

Operand::Operand()
{
}

Operand::~Operand()
{
}

IOperand* Operand::getValue()
{
    return (this->value);
}

void Operand::setValue(IOperand *newValue)
{
    this->value = newValue;
}

void Operand::setOperandCmd(Operand *operand)
{
    operand->cmdOperand["add"] = &Operand::add;
    operand->cmdOperand["sub"] = &Operand::sub;
    operand->cmdOperand["mul"] = &Operand::mul;
    operand->cmdOperand["div"] = &Operand::div;
    operand->cmdOperand["mod"] = &Operand::mod;
}

std::string Operand::toString() const
{
    std::ostringstream ss;
    ss << this->value;
    return (ss.str());
}

std::map<std::string, void (Operand::*)(Memory, CPU)> Operand::getOperandCmd()
{
    return (this->cmdOperand);
}

eOperandType Operand::getType() const
{
    return (this->getType());
}

// IOperand Operand::*operator+(const IOperand &rhs)
// {
    // IOperand *aoo;
// 
    // aoo->value = aoo->value + rhs.value;
// }

// IOperand Operand::*operator-(const IOperand &rhs)
// {
// }

// IOperand Operand::*operator*(const IOperand &rhs)
// {
// }   

// IOperand Operand::*operator/(const IOperand &rhs)
// {
// }

// IOperand Operand::*operator%(const IOperand &rhs)
// {
// }

void Operand::sub(Memory objMemory, CPU objCPU)
{
}
void Operand::mul(Memory objMemory, CPU objCPU)
{
}
void Operand::div(Memory objMemory, CPU objCPU)
{
}
void Operand::mod(Memory objMemory, CPU objCPU)
{
}
void Operand::add(Memory memory, CPU cpu)
{
}

void setOperandCmd(Operand *operand)
{
}