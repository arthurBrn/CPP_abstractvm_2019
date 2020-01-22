/*
** EPITECH PROJECT, 2020
** IOperand.hh
** File description:
** ...
*/

#include "abstractvm.hh"

#ifndef _IOperand_HH_
#define _IOperand_HH_

class IOperand
{
public:
      enum eOperandType
      {
            int8_t,
            int16_t,
            int32_t,
            _Float32
      };
      virtual std::string toString() const = 0;
      virtual eOperandType getType() const = 0;
      virtual IOperand *operator+(const IOperand &rhs) const = 0;
      virtual IOperand *operator-(const IOperand &rhs) const = 0;
      virtual IOperand *operator*(const IOperand &rhs) const = 0;
      virtual IOperand *operator/(const IOperand &rhs) const = 0;
      virtual IOperand *operator%(const IOperand &rhs) const = 0;

      // virtual - IOperand() {}
};

#endif
