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

void Operand::debug_obj()
{
    eOperandType type = this->type;
    std::ostringstream eOperandType;
    eOperandType << type;
    std::string type_s = eOperandType.str();
    std::cout << "type : " + type_s << std::endl;
    std::cout << "value : " + this->value << std::endl;
}

eOperandType Operand::getType()
{
    return (this->type);
}

std::string Operand::getValue()
{
    return (this->value);
}

void Operand::setValue(std::string& val)
{
    this->value = val;
}

void Operand::setType(eOperandType typ)
{
    this->type = typ;
}

// void Operand::setType(std::string value)
// {

// }

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