/*
** EPITECH PROJECT, 2020
** Memory.cpp
** File description:
** ...
*/

#include "Memory.hh"

int Memory::getStackSize()
{
    return (this->stack.size());
}

// IOperand* Memory::getStackTopPile()
// {   
//     return (this->stack.at(this->getStackSize()));
// }

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

void Memory::setStack(IOperand* obj)
{
    this->stack.push_back(obj);
}

void Memory::pop()
{
    // auto iterator = this->getAllStack().begin();

    // if (getAllStack().empty())
    //     throw new AbstractVmException("ERROR: pop() error. Stack is empty");
    // this->getAllStack().erase(iterator);
    std::cout << "POP" << std::endl;
}

void Memory::clear()
{
    // this->getAllStack().clear();
    std::cout << "CLEAR from memory" << std::endl;
}

/**
 * NOT SURE THIS WORK, TEST IT CPU
 * */
void Memory::dup()
{
    // NOT SURE BETWEEN begin() or end()
    // auto iterator = this->getAllStack().begin();

    // if (this->getAllStack().empty())
    //     throw new AbstractVmException("ERROR: can not dup() on empty stack");
    // IOperand *copiedValue = this->stack.front();
    // this->stack.push_back(copiedValue);
    std::cout << "DUP from memory" << std::endl;
}

// NOT TESTED EITHER 
void Memory::swap()
{
    // int stackSize = this->getStackSize();
    // IOperand *fstValueHolder = this->getStackAtIndexX(stackSize);
    // IOperand *sndValueHolder = this->getStackAtIndexX((stackSize - 1));
// 
    // if (this->getStackSize() < 2)
        // throw new AbstractVmException("ERROR: can not swap() on stack with less than two elements.");
    // this->setStackAtIndexX(stackSize, sndValueHolder);
    // this->setStackAtIndexX((stackSize - 1), fstValueHolder);
    std::cout << "SWAP from memory" << std::endl;
}

void Memory::dump()
{
    // Output out;
    // std::vector<IOperand*>::iterator ptr;

    // USE TOSTRING()
    // for (ptr = this->getAllStack().begin(); ptr < this->getAllStack().end(); ptr++)
        // out.print(*ptr);

    std::cout << "DUMP from memory" << std::endl;
}

void Memory::print()
{
    std::cout << "PRINT MEMORY " << std::endl;
}

void Memory::setMemoryCmd(Memory *memory)
{
    memory->memoryCmd["pop"] = &Memory::pop;
    memory->memoryCmd["clear"] = &Memory::clear;
    memory->memoryCmd["dup"] = &Memory::dup;
    memory->memoryCmd["swap"] = &Memory::swap;
    memory->memoryCmd["dump"] = &Memory::dump;
    memory->memoryCmd["print"] = &Memory::print;
}

std::map<std::string, void (Memory::*)()> Memory::getMemoryCmd()
{
    return (this->memoryCmd);
}