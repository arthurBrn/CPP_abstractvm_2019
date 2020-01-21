/*
** EPITECH PROJECT, 2020
** Memory.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include "IOperand.hh"

#ifndef _MEMORY_HH_
#define _MEMORY_HH_

class Memory
{
public:
    int getStackSize();
    IOperand* getStackTopPile();
    IOperand* getStackAtIndexX(int index);
    IOperand* setStackAtIndexX(int index, IOperand* value);
    std::vector<IOperand*> getAllStack();
    void addStack(IOperand &object);
    void popTheStack();
private:
    std::vector<IOperand*> stack;
};

#endif
