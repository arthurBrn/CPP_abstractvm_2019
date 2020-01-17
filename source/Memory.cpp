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
    return (stack.size());
}

IOperand* Memory::getTopPileStack()
{
    return (stack.at(getStackSize() - 1));
}

std::vector<IOperand*> Memory::getAllStack()
{
    return (stack);
}

void addStack(IOperand &object)
{
    // do smthg
}

void popTheStack()
{
    // do smthg
}
