/*
** EPITECH PROJECT, 2020
** Memory.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include "IOperand.hh"

#ifndef _MEMORY_HH_
#define _MEMORY_HH_

class Memory
{
public:
    int getStackSize();
    // IOperand* getStackTopPile();
    void setStack(IOperand* obj);
    IOperand* getStackAtIndexX(int index);
    IOperand* setStackAtIndexX(int index, IOperand* value);
    std::vector<IOperand*> getAllStack();
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
