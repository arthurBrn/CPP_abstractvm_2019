/*
** EPITECH PROJECT, 2020
** CPU.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include "IOperand.hh"

#ifndef _CPU_HH_
#define _CPU_HH_

class CPU {
    public:
        int getStorageSize();
        std::vector<std::string> getAllStorage();
        std::string getLastStored();
        void push(IOperand &object);
        void store(IOperand &object);
        void load(IOperand &object);
        void assert(IOperand &object);
        void dup();
        void swap();
        void pop();
        void add();
        void clear();
        void exit();
    private:
        std::vector<std::string> storage;
};

#endif