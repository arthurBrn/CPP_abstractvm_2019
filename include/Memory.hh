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
// #include "Operand.hh"
#include "AbstractVmException.hh"
#include "Output.hh"

// class IOperand;

class Memory
{
public:
    int getStackSize();
    void setStack(IOperand* obj);
    IOperand* getStackAtIndexX(int index);
    void setStackAtIndexX(int index, IOperand *obj);
    std::vector<IOperand*> getAllStack();
    void pop();
    void clear();
    void dup();
    void swap();
    void dump();
    void print();
    // void store();
    void setMemoryCmd(Memory *memory);
    std::map<std::string, void (Memory::*)()> getMemoryCmd();
    std::map<std::string, void (Memory::*)()> memoryCmd;
private:
    std::vector<IOperand*> stack;
    // IOperand *_ioperand;
};

#endif
