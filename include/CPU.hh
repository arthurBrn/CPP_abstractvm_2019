/*
** EPITECH PROJECT, 2020
** CPU.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include "IOperand.hh"
#include "Memory.hh"


#ifndef _CPU_HH_
#define _CPU_HH_

class CPU {
    public:
        CPU();
        ~CPU();
        int getRegistreSize();
        std::vector<std::string> getFullRegistre();
        std::string getRegistreStackAtIndex(int index);
        void setRegistreStackAtIndex(int index, std::string newStack);
        void push(IOperand &object);
        void store(IOperand &object);
        void load(IOperand &object);
        void assert(IOperand &object);
        void dup(std::vector<IOperand*> vector);
        void swap(Memory memoryObject);
        void pop(std::vector<IOperand*> stack) throw();
        void add();
        void dump(Memory memoryObject);
        void clear(std::vector<IOperand*> stack);
        void exit();
    private:
        std::vector<std::string> registre;
};

#endif