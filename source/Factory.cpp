/*
** EPITECH PROJECT, 2020
** Factory.cpp
** File description:
** ...
*/

#include "abstractvm.hh"

Factory::Factory()
{
}

Factory::~Factory()
{
}

IOperand *Factory::createInt8(const std::string &value)
{
    IOperand *obj;
    return (obj);
}

IOperand *Factory::createInt16(const std::string &value)
{
    IOperand *obj;
    return (obj);
}
IOperand *Factory::createInt32(const std::string &value)
{
    IOperand *obj;
    return (obj);
}
IOperand *Factory::createFloat(const std::string &value)
{
    IOperand *obj;
    return (obj);
}
IOperand *Factory::createDouble(const std::string &value)
{
    IOperand *obj;
    return (obj);
}
IOperand *Factory::createBigDecimal(const std::string &value)
{
    IOperand *obj;
    return (obj);
}

IOperand *Factory::createOperand(eOperandType type, const std::string &value)
{
    IOperand *res;
    switch (type)
    {
    case eOperandType::INT8:
        res = createInt8(value);
    case eOperandType::INT16:
        res = createInt16(value);
    case eOperandType::INT32:
        res = createInt32(value);
    case eOperandType::FLOAT:
        res = createFloat(value);
    case eOperandType::DOUBLE:
        res = createDouble(value);
    case eOperandType::BIGDECIMAL:
        res = createBigDecimal(value);
    }
    return (res);
}