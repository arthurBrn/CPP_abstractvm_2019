/*
** EPITECH PROJECT, 2020
** Factory.hh
** File description:
** ...
*/

#ifndef _FACTORY__HH_
#define _FACTORY__HH_

#include "abstractvm.hh"
#include "IOperand.hh"
#include "Operand.hh"
#include "eOperandType.hh"


class Factory 
{
    public:
        static IOperand* createOperand(eOperandType type, const std::string& value);
    private:
        static IOperand* createInt8(const std::string& value);
        static IOperand* createInt16(const std::string& value);
        static IOperand* createInt32(const std::string& value);
        static  IOperand* createFloat(const std::string& value);
        static  IOperand* createDouble(const std::string& value);
        static IOperand* createBigDecimal(const std::string& value);
};

#endif
