/*
** EPITECH PROJECT, 2020
** IOperand.hh
** File description:
** ...
*/

#ifndef _IOperand_HH_
#define _IOperand_HH_

#include <string>
#include "eOperandType.hh"
#include "IOperand.hh"

class IOperand
{
public:
    virtual IOperand *operator+(const IOperand& rhs) const = 0; // sum
    virtual IOperand *operator-(const IOperand& rhs) const = 0; // difference
    virtual IOperand *operator*(const IOperand& rhs) const = 0; // mul
    virtual IOperand *operator/(const IOperand& rhs) const = 0; // division
    virtual IOperand *operator%(const IOperand& rhs) const = 0; // modulo
    virtual std::string toString() const = 0;
    virtual eOperandType getType() const = 0;
    virtual std::string getValue() const = 0;
    virtual void setValue(std::string &) = 0;
    virtual void setType(eOperandType) = 0;
    virtual void debug_obj() = 0;
    virtual ~IOperand() {}
};

#endif
