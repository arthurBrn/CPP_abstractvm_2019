/*
** EPITECH PROJECT, 2020
** Memory.cpp
** File description:
** ...
*/

#include "Memory.hh"
#include "CPU.hh"

int Memory::getStackSize()
{
    return (this->stack.size());
}

IOperand *Memory::getStackAtIndexX(int index)
{
    std::vector<IOperand *>::iterator it = this->stack.begin();
    std::advance(it, index);
    IOperand *obj = this->getAllStack().at(index);
    return (obj);
}

void Memory::setStackAtIndexX(int index, IOperand *obj)
{
    std::vector<IOperand *>::iterator it = this->stack.begin() + index;

    this->stack.insert(it, obj);
}

std::vector<IOperand *> Memory::getAllStack()
{
    return (this->stack);
}

void Memory::setStack(IOperand *obj)
{
    this->setStackAtIndexX(0, obj);
}

IOperand *Memory::unstackAtIndex(int index)
{
    AbstractVmException exception;
    std::vector<IOperand*>::iterator it = this->stack.begin();

    exception.setErrorMessage("Error unstacking a memory stack. The index is greater than the stack.");
    if ((this->getStackSize() < index) || (index < 0))
        throw (exception);
    IOperand *obj = this->getStackAtIndexX(index);
    std::advance(it, index);
    this->stack.erase(it);
    return (obj);
}

void Memory::pop()
{
    AbstractVmException exception;

    exception.setErrorMessage("ERROR: pop() error. Stack is empty");
    if (this->stack.empty())
        throw(exception);
    std::vector<IOperand *>::iterator it = this->stack.begin();
    this->stack.erase(it);
}

void Memory::clear()
{
    this->stack.clear();
}

void Memory::dup()
{
    AbstractVmException exception;
    exception.setErrorMessage("ERROR: can not dup() on empty stack");

    std::vector<IOperand *>::iterator it = this->stack.begin();
    this->stack.insert(it, this->stack.front());
}

void Memory::swap()
{
    std::string holding_value;
    eOperandType holding_type;
    AbstractVmException exception;
    std::vector<IOperand *>::iterator it = this->stack.begin() + 1;

    exception.setErrorMessage("ERROR: can not swap() on stack with less than two elements.");
    if (this->stack.size() < 2)
        throw(exception);
    holding_value = this->getStackAtIndexX(0)->getValue();
    holding_type = this->getStackAtIndexX(0)->getType();
    std::string valSndObj = this->getStackAtIndexX(1)->getValue();
    eOperandType typeSndObj = this->getStackAtIndexX(1)->getType();
    this->getStackAtIndexX(0)->setValue(valSndObj);
    this->getStackAtIndexX(0)->setType(typeSndObj);
    this->getStackAtIndexX(1)->setValue(holding_value);
    this->getStackAtIndexX(1)->setType(holding_type);
}

void Memory::dump()
{
    Output out;
    IOperand *obj;

    for (int i = 0; i < this->getAllStack().size(); i++)
    {
        obj = this->getStackAtIndexX(i);
        std::cout << obj->getValue() << std::endl;
    }
}

void Memory::print()
{
    AbstractVmException exception;

    exception.setErrorMessage("Top stack value is not 8 bit integer");
    eOperandType op = this->getAllStack().front()->getType();
    IOperand *obj = this->getAllStack().front();
    if (!(this->stack.empty()))
    {
        if (op != 0)
            throw(exception);
        else
            std::cout << obj->getValue() << std::endl;
    }
    else
    {
        exception.setErrorMessage("EMPTY STACK, can't print");
        throw(exception);
    }
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