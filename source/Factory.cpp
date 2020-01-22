/*
** EPITECH PROJECT, 2020
** Factory.cpp
** File description:
** ...
*/

#include "abstractvm.hh"
#include "IOperand.hh"
#include <iostream>

IOperand *createInt8(const std::string &value)
{
    int8_t *nb = new int8_t(std::stoi(value));
    return ((IOperand *)nb);
}

IOperand *createInt16(const std::string &value)
{
    int16_t *nb = new int16_t(std::stoi(value));
    return ((IOperand *)nb);
}
IOperand *createInt32(const std::string &value)
{
    int32_t *nb = new int32_t(std::stoi(value));
    return ((IOperand*)nb);
}
IOperand *createFloat(const std::string &value)
{
    float *nb = new float(std::stoi(value));
    return ((IOperand*)nb);
}
IOperand *createDouble(const std::string &value)
{   
}

IOperand *createBigDecimal(const std::string &value)
{
}

static IOperand* createOperand(eOperandType type, const std::string& value)
{
    switch(type)
    {
        case  'INT8':
            return (createInt8(value));
        case 'INT16':
            return (createInt16(value));
        case 'INT32':
            return (createInt32(value));
        case 'FLOAT':
            return (createFloat(value));
        case 'DOUBLE':
            return (createDouble(value));
        case 'BIGDECIMAL':
            createBigDecimal(value);
        default:
            std::cout << "SWITCH ERROR" << std::endl;
    }
}