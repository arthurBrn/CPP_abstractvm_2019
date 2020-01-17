/*
** EPITECH PROJECT, 2020
** Operand.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include "IOperand.hh"

#ifndef _OPERAND_HH_
#define _OPERAND_HH_

class Operand
{
public:
    void sub();
    void mul();
    void div();
    void mod();
    IOperand* getValue();
private:
    IOperand* value;
};

#endif
