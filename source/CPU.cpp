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

std::vector<std::string> CPU::getAllStorage()
{
    return (this->storage);
}

int CPU::getStorageSize()
{
    return (this->storage.size());
}

std::string CPU::getLastStored()
{
    return (this->storage.at(getStorageSize() - 1));
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
void dup(std::vector<IOperand>)
{
    // Duplicates the value on the top of stack and copy the stack of the value

}

void swap(Memory objMemory)
{
    // do smthg
    // reverse the order of the first two values of the stack 
    int stackSize = objMemory.getStackSize();
    IOperand* fstValueHolder = objMemory.getStackAtIndexX(stackSize);
    IOperand* sndValueHolder = objMemory.getStackAtIndexX((stackSize - 1));

    objMemory.setStackAtIndexX(stackSize, sndValueHolder);
    objMemory.setStackAtIndexX((stackSize - 1), fstValueHolder);
}

void pop(std::vector<IOperand*> stack)
{
    // Unstack the value at the top of the stack 
    // If the stack is empty, the program stop error 
    if (!stack.empty()) {
        throw("Stack is empty");
    } else {

    }
}

void add()
{
    // do smthg
}

void clear(std::vector<IOperand*> stack)
{
    // Clear the stack
    // for (int i = 0; i < stack.size(); i++)
        // stack.erase(stack.at(i));
}
void exit()
{
    // do smthg

}
