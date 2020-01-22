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
#include "Factory.hh"

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

void CPU::push(Memory memo, Chipset chip)
{
    Factory fact;
}

void CPU::store(Memory memo, Chipset chip)
{
    // do smthg
}
void CPU::load(Memory memo, Chipset chip)
{
    // do smthg
}
void CPU::assert(Memory memo, Chipset chip)
{
    // do smthg
}

void CPU::exit()
{
    // do smthg
}
