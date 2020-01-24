/*
** EPITECH PROJECT, 2020
** IOperand.hh
** File description:
** ...
*/

#ifndef _IOperand_HH_
#define _IOperand_HH_

#include <string>

class IOperand
{
public:
      virtual std::string toString() const = 0;
      // virtual eOperandType getType() const = 0;
      virtual IOperand *operator+(const IOperand &rhs) const = 0;
      virtual IOperand *operator-(const IOperand &rhs) const = 0;
      virtual IOperand *operator*(const IOperand &rhs) const = 0;
      virtual IOperand *operator/(const IOperand &rhs) const = 0;
      virtual IOperand *operator%(const IOperand &rhs) const = 0;
      virtual ~IOperand() {}
};

#endif
