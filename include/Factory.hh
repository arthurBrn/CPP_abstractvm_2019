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
        Factory();
        ~Factory();
        IOperand* createOperand(eOperandType type, const std::string& value);
    private:
        IOperand* createInt8(const std::string& value);
        IOperand* createInt16(const std::string& value);
        IOperand* createInt32(const std::string& value);
        IOperand* createFloat(const std::string& value);
        IOperand* createDouble(const std::string& value);
        IOperand* createBigDecimal(const std::string& value);
};

#endif
