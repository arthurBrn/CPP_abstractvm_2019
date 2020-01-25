/*
** EPITECH PROJECT, 2020
** Memory.hh
** File description:
** ...
*/

#ifndef _MEMORY_HH_
#define _MEMORY_HH_

#include "abstractvm.hh"
#include "IOperand.hh"
#include "AbstractVmException.hh"
#include "Output.hh"

class Memory
{
public:
    int getStackSize();
    void setStack(IOperand* obj);
    IOperand* getStackAtIndexX(int index);
    void setStackAtIndexX(int index, IOperand *obj);
    std::vector<IOperand*> getAllStack();
    IOperand *unstackAtIndex(int index);
    void pop();
    void clear();
    void dup();
    void swap();
    void dump();
    void print();
    void setMemoryCmd(Memory *memory);
    std::map<std::string, void (Memory::*)()> getMemoryCmd();
    std::map<std::string, void (Memory::*)()> memoryCmd;
private:
    std::vector<IOperand*> stack;
};

#endif
