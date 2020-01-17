/*
** EPITECH PROJECT, 2020
** Memory.hh
** File description:
** ...
*/

#ifndef _PAIR_
#define _PAIR_

#include "abstractvm.hh"
#include "IOperand.hh"

class Factory 
{
    public:
        // static IOperand* createOperand(eOperandType type, const std::string& value);
        IOperand* createInt8(const std::string& value);
        IOperand* createInt16(const std::string& value);
        IOperand* createInt32(const std::string& value);
        IOperand* createFloat(const std::string& value);
        IOperand* createDouble(const std::string& value);
        IOperand* createBigDecimal(const std::string& value);
};

#endif
