/*
** EPITECH PROJECT, 2019
** source/IOperand.cpp
** File description:
** IOperand file
*/

#include "abstractvm.hh"


class IOperand
{
    public:
        enum eOperandType {int8_t, int16_t, int32_t, _Float32};
        virtual std::string toString() const = 0; 
        virtual eOperandType getType() const = 0;
        virtual IOperand* operator+(const IOperand &rhs) const = 0;
        virtual IOperand* operator-(const IOperand &rhs) const = 0;
        virtual IOperand* operator*(const IOperand &rhs) const = 0;
        virtual IOperand* operator/(const IOperand &rhs) const = 0;
        virtual IOperand* operator%(const IOperand &rhs) const = 0;

        virtual -IOperand(){}
};
