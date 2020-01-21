/*
** EPITECH PROJECT, 2020
** Memory.cpp
** File description:
** ...
*/

#include "abstractvm.hh"
#include "Memory.hh"

int Memory::getStackSize()
{
    return (this->stack.size());
}

IOperand* Memory::getStackTopPile()
{
    return (this->stack.at(this->getStackSize()));
}

IOperand* Memory::getStackAtIndexX(int index)
{
    IOperand* someobject;

    return (someobject);
}

IOperand* Memory::setStackAtIndexX(int index, IOperand* value)
{
    IOperand* someobject;

    return (someobject);
}


std::vector<IOperand*> Memory::getAllStack()
{
    return (this->stack);
}

void addStack(IOperand &object)
{
    // do smthg
}

void popTheStack()
{
    // do smthg
}
