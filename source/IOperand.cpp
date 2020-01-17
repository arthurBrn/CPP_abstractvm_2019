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
        virtual std::string toString() const = 0;
        virtual eOperandType getType() const = 0;

        virtual IOperand* operator+(const IOperand &rhs) const = 0;
        virtual IOperand* operator-(const IOperand &rhs) const = 0;
        virtual IOperand* operator*(const IOperand &rhs) const = 0;
        virtual IOperand* operator/(const IOperand &rhs) const = 0;
        virtual IOperand* operator%(const IOperand &rhs) const = 0;

        virtual -IOperand(){}

    protected:
    // trv comment rajouter double et bigDecimal
        enum eOperandType {int8_t, int16_t, int32_t, _Float32}; 
};
