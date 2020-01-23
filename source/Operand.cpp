/*
** EPITECH PROJECT, 2019
** source/IOperand.cpp
** File description:
** IOperand file
*/

#include "abstractvm.hh"
#include "IOperand.hh"

Operand::Operand()
{
}

Operand::~Operand()
{
}

IOperand *Operand::getValue()
{
    IOperand *obj;
    return (obj);
}

void Operand::setValue(IOperand *newValue)
{
}
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

void Operand::setOperandCmd(Operand *operand)
{
    operand->cmdOperand["add"] = &Operand::add;
    operand->cmdOperand["sub"] = &Operand::sub;
    operand->cmdOperand["mul"] = &Operand::mul;
    operand->cmdOperand["div"] = &Operand::div;
    operand->cmdOperand["mod"] = &Operand::mod;
}

std::map<std::string, void (Operand::*)(Memory, CPU)> Operand::getOperandCmd()
{
    return (this->cmdOperand);
}

std::string Operand::toString() const
{
    return "str";
}

eOperandType Operand::getType() const
{
    // A CHANGER 
    return (eOperandType::INT8);
}

// IOperand Operand::*operator+(const IOperand &rhs)
// {
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
