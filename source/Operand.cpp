/*
** EPITECH PROJECT, 2019
** source/IOperand.cpp
** File description:
** IOperand file
*/

#include "Operand.hh"
#include <regex>

Operand::Operand(eOperandType type, std::string value)
{
    this->type = type;
    this->value = value;
}

Operand::~Operand()
{
}

eOperandType choose_type(eOperandType type1, eOperandType type2)
{
    if (type1 >= type2)
        return (type1);
    return (type2);
}

double Operand::create_nb_1() const
{
    std::string value = this->toString();
    double nb1 = std::stod(value);
    return (nb1);
}

IOperand *Operand::operator+(const IOperand& rhs) const
{
    std::string value = rhs.toString();
    double nb2 = std::stod(value);

    double nb3 = create_nb_1() + nb2;
    eOperandType type = choose_type(this->getType(), rhs.getType());
    IOperand *nb = Factory::createOperand(type, std::to_string(nb3));
    return (nb);
}

IOperand *Operand::operator-(const IOperand& rhs) const
{
    std::string value = rhs.toString();
    double nb2 = std::stod(value);

    double nb3 = create_nb_1() - nb2;
    eOperandType type = choose_type(this->getType(), rhs.getType());
    IOperand *nb = Factory::createOperand(type, std::to_string(nb3));
    return (nb);
}

IOperand *Operand::operator*(const IOperand& rhs) const
{
    std::string value = rhs.toString();
    double nb2 = std::stod(value);

    double nb3 = create_nb_1() * nb2;
    eOperandType type = choose_type(this->getType(), rhs.getType());
    IOperand *nb = Factory::createOperand(type, std::to_string(nb3));
    return (nb);
}

IOperand *Operand::operator/(const IOperand& rhs) const
{
    std::string value = rhs.toString();
    double nb2 = std::stod(value);

    double nb3 = create_nb_1() / nb2;
    eOperandType type = choose_type(this->getType(), rhs.getType());
    IOperand *nb = Factory::createOperand(type, std::to_string(nb3));
    return (nb);
}

IOperand *Operand::operator%(const IOperand& rhs) const
{
    std::string value1 = rhs.toString();
    int nb1 = std::stoi(value1);
    std::string value2 = rhs.toString();
    int nb2 = std::stoi(value2);

    double nb3 = nb1 % nb2;
    eOperandType type = choose_type(this->getType(), rhs.getType());
    IOperand *nb = Factory::createOperand(type, std::to_string(nb3));
    return (nb);
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



