/*
** EPITECH PROJECT, 2020
** Factory.cpp
** File description:
** ...
*/

#include "Factory.hh"

Factory::Factory()
{
}

Factory::~Factory()
{
}

IOperand *Factory::createInt8(const std::string &value)
{
    std::cout << "création de l'objet" << std::endl;
    IOperand *res;

    res = new Operand(eOperandType::INT8, value);
}

IOperand *Factory::createInt16(const std::string &value)
{
    std::cout << "création de l'autre l'objet" << std::endl;
    IOperand *res;

    res = new Operand(eOperandType::INT16, value);
}
IOperand *Factory::createInt32(const std::string &value)
{

}
IOperand *Factory::createFloat(const std::string &value)
{

}
IOperand *Factory::createDouble(const std::string &value)
{

}
IOperand *Factory::createBigDecimal(const std::string &value)
{
}

IOperand *Factory::createOperand(eOperandType type, const std::string &value)
{
   
    IOperand *res;
    switch (type)
    {
    case eOperandType::INT8:
        res = createInt8(value);
        break;
    case eOperandType::INT16:
        res = createInt16(value);
        break;
    case eOperandType::INT32:
        res = createInt32(value);
        break;
    case eOperandType::FLOAT:
        res = createFloat(value);
        break;
    case eOperandType::DOUBLE:
        res = createDouble(value);
        break;
    case eOperandType::BIGDECIMAL:
        res = createBigDecimal(value);
        break;
    }

    return (res);
}