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

IOperand *Operand::operator+(const IOperand& rhs) const
{
    std::string value1 = this->toString();
    std::string value2 = rhs.toString();
    int nb1;
    int nb2;
    nb1 = std::stoi(value1);
    nb2 = std::stoi(value2);
    std::cout <<  nb1 << std::endl;
    std::cout <<  nb2 << std::endl;
}


std::string Operand::toString() const
{
    std::ostringstream ss;
    ss << this->value;
    return (ss.str());
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

eOperandType Operand::getType() const
{
    return (this->type);
}

std::string Operand::getValue () const
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



