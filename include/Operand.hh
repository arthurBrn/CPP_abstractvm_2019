/*
** EPITECH PROJECT, 2020
** Operand.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include "IOperand.hh"
#include "CPU.hh"
#include "Memory.hh"


#ifndef _OPERAND_HH_
#define _OPERAND_HH_

class Operand
{
    public:
        IOperand* getValue();
        void setValue(IOperand* newValue);
        void sub(Memory objMemory, CPU objCPU);
        void mul(Memory objMemory, CPU objCPU);
        void div(Memory objMemory, CPU objCPU);
        void mod(Memory objMemory, CPU objCPU);
    private:
        IOperand* value;
};

#endif
