/*
** EPITECH PROJECT, 2020
** Factory.cpp
** File description:
** ...
*/

#include "Factory.hh"

IOperand *Factory::createInt8(const std::string &value)
{
    std::cout << "CREATEINT8" << std::endl;
    IOperand *res = new Operand(eOperandType::INT8, value);
    return (res); 
}

IOperand *Factory::createInt16(const std::string &value)
{
    std::cout << "CREATEINT16" << std::endl;
    IOperand *res = new Operand(eOperandType::INT16, value);

    std::cout << "Debug obj #1 avant setValue/setType" << std::endl;
    return (res);
}
IOperand *Factory::createInt32(const std::string &value)
{
    std::string val = value;

    std::cout << "CREATEINT32" << std::endl;
    IOperand *res = new Operand(eOperandType::INT32, value);
    std::cout << "Debug obj #1 avant setValue/setType" << std::endl;
    return (res);
}

IOperand *Factory::createFloat(const std::string &value)
{
    std::cout << "CREATEFLOAT" << std::endl;
    std::string val = value;
    IOperand *res = new Operand(eOperandType::FLOAT, value);
    return (res);
}
IOperand *Factory::createDouble(const std::string &value)
{
    std::cout << "CREATEDOUBLE" << std::endl;
    std::string val = value;
    IOperand *res = new Operand(eOperandType::DOUBLE, value);
    return (res);
}
IOperand *Factory::createBigDecimal(const std::string &value)
{
    std::cout << "CREATEBIGDECIMAL" << std::endl;
    IOperand *res = new Operand(eOperandType::BIGDECIMAL, value);
}

IOperand *Factory::createOperand(eOperandType type, const std::string &value)
{
    /*std::cout << "===== FACTORY =====" << std::endl;
    std::cout << "type : ";
    std::cout << type << std::endl;
    std::cout << "value : ";
    std::cout << value << std::endl;*/
    AbstractVmException exception;
    exception.setErrorMessage("incompatible type");
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
        throw exception;
        break;
    }
    return (res);
}