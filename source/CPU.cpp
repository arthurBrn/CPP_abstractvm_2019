/*
** EPITECH PROJECT, 2020
** CPU.cpp
** File description:
** ...
*/

#include "abstractvm.hh"
#include "CPU.hh"
#include "IOperand.hh"
#include "Memory.hh"
#include "Chipset.hh"
#include "Output.hh"

CPU::CPU()
{
}

CPU::~CPU()
{
}

int CPU::getRegistreSize()
{
    return (this->registre.size());
}

std::vector<std::string> CPU::getFullRegistre()
{
    return (this->registre);
}

std::string CPU::getRegistreStackAtIndex(int index)
{
    return (this->registre.at(index));
}

void CPU::setRegistreStackAtIndex(int index, std::string someStack)
{
    // take in account the difference of type etc...
    this->registre.at(index) = someStack;
}

void CPU::push(IOperand &object)
{
    // do smthg
}
void CPU::store(IOperand &object)
{
    // do smthg
}
void CPU::load(IOperand &object)
{
    // do smthg
}
void CPU::assert(IOperand &object)
{
    // do smthg
}

void CPU::exit()
{
    // do smthg
}
