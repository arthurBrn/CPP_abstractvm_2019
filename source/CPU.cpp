/*
** EPITECH PROJECT, 2020
** CPU.cpp
** File description:
** ...
*/

#include "abstractvm.hh"
#include "CPU.hh"
#include "IOperand.hh"

std::vector<std::string> CPU::getAllStorage()
{
    return (storage);
}

int CPU::getStorageSize()
{
    return (storage.size());
}

std::string CPU::getLastStored()
{
    return (storage.at(getStorageSize() - 1));
}

void push(IOperand &object)
{
    // do smthg
}
void store(IOperand &object)
{
    // do smthg
}
void load(IOperand &object)
{
    // do smthg
}
void assert(IOperand &object)
{
    // do smthg
}
void dup()
{
    // do smthg
}
void swap()
{
    // do smthg
}
void pop()
{
    // do smthg
}
void add()
{
    // do smthg
}
void clear()
{
    // do smthg
}
void exit()
{
    // do smthg
}
