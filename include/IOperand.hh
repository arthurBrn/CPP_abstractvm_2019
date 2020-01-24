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

class IOperand
{
public:
    virtual std::string toString() const = 0;
    virtual eOperandType getType() = 0;
    virtual std::string getValue() = 0;
    virtual void setValue(std::string&) = 0;
    virtual void setType(eOperandType&) = 0;
    // virtual IOperand *operator+(const IOperand &rhs) const = 0;
    // virtual IOperand *operator-(const IOperand &rhs) const = 0;
    // virtual IOperand *operator*(const IOperand &rhs) const = 0;
    // virtual IOperand *operator/(const IOperand &rhs) const = 0;
    // virtual IOperand *operator%(const IOperand &rhs) const = 0;
    virtual ~IOperand() {}
};

#endif
