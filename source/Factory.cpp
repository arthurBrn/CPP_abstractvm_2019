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
    std::cout << "création de l'objet 8" << std::endl;
    IOperand *res;

    res = new Operand(eOperandType::INT8, value);
    return res;    
}

IOperand *Factory::createInt16(const std::string &value)
{
    std::cout << "création de l'objet 16" << std::endl;
    IOperand *res;

    res = new Operand(eOperandType::INT16, value);
    return res;
}
IOperand *Factory::createInt32(const std::string &value)
{
    std::string nb = "10";

    std::cout << "création de l'objet 32" << std::endl;
    IOperand *res = new Operand(eOperandType::INT32, value);
    res->debug_obj();
    res->setType(eOperandType::INT8);
    res->setValue(nb);
    res->debug_obj();
    return (res);
}

IOperand *Factory::createFloat(const std::string &value)
{
    std::cout << "CREATEFLOAT" << std::endl;
}
IOperand *Factory::createDouble(const std::string &value)
{
    std::cout << "CREATEDOUBLE" << std::endl;
}
IOperand *Factory::createBigDecimal(const std::string &value)
{
    std::cout << "CREATEBIGDECIMAL" << std::endl;
}

IOperand *Factory::createOperand(eOperandType type, const std::string &value)
{
    std::cout << "===== FACTORY =====" << std::endl;
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
    default:
        std::cout << "ERROORRO" << std::endl;
        break;
    }
    return (res);
}