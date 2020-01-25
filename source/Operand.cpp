/*
** EPITECH PROJECT, 2019
** source/IOperand.cpp
** File description:
** IOperand file
*/

#include "Operand.hh"

Operand::Operand(eOperandType type, std::string value)
{
    this->type = type;
    this->value = value;
}

Operand::~Operand()
{
}

eOperandType Operand::getType() const
{
    return (this->type);
}

void Operand::setType(std::string newType, Operand *op) const 
{
    eOperandType value;
    if (newType.compare("int8") == 0)
        op->type = eOperandType::INT8;
    else if (newType.compare("int16") == 0)
        op->type = eOperandType::INT16;
    else if (newType.compare("int32") == 0)
        op->type = eOperandType::INT32;
    else if (newType.compare("float") == 0)
        op->type = eOperandType::FLOAT;
    else if (newType.compare("double") == 0)
        op->type = eOperandType::DOUBLE;
    else if (newType.compare("bigdecimal") == 0)
        op->type = eOperandType::BIGDECIMAL;
}

std::string Operand::getValue() const
{
    return this->value;
}

void Operand::setValue(std::string newValue, Operand *op) const
{
    op->value = newValue;
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

void Operand::setOperandCmd(Operand *operand)
{
    operand->cmdOperand["add"] = &Operand::add;
    operand->cmdOperand["sub"] = &Operand::sub;
    operand->cmdOperand["mul"] = &Operand::mul;
    operand->cmdOperand["div"] = &Operand::div;
    operand->cmdOperand["mod"] = &Operand::mod;
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

void Operand::add(Memory memory, CPU cpu)
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
