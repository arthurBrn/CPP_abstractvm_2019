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
void CPU::dup(std::vector<IOperand *> vector)
{
    // Duplicates the value on the top of stack and copy the stack of the value
}

void CPU::swap(Memory objMemory)
{
    int stackSize = objMemory.getStackSize();
    IOperand *fstValueHolder = objMemory.getStackAtIndexX(stackSize);
    IOperand *sndValueHolder = objMemory.getStackAtIndexX((stackSize - 1));

    objMemory.setStackAtIndexX(stackSize, sndValueHolder);
    objMemory.setStackAtIndexX((stackSize - 1), fstValueHolder);
}

void CPU::pop(std::vector<IOperand *> stack) throw()
{
    if (stack.empty())
    {
        throw("STACK IS EMPTY ERROR");
    }
    // stack.erase(stack.size());
}

void CPU::add()
{
    // do smthg
}

void CPU::clear(std::vector<IOperand *> stack)
{
    auto iterator = stack.begin();

    while (iterator != stack.end())
        iterator = stack.erase(iterator);
}

void CPU::dump(Memory memoryObject)
{
    // Create an Output object, to use its function print
    Output *out = new Output();
    // for (auto iterator = memoryObject.getAllStack().begin(); iterator != memoryObject.getAllStack().end(); ++iterator)
    // out->print(memoryObject.getAllStack().at(iterator));
}

void CPU::exit()
{
    // do smthg
}
