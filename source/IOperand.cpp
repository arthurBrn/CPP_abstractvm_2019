/*
** EPITECH PROJECT, 2020
** AAnimal.cpp
** File description:
** ...
*/

#include <iostream>
#include <string.h>
#include <cstring>

// #include "../include/AAnimal.hh"
// #include "../include/cat.hh"
// #include "../include/mouse.hh"

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
};