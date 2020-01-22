/*
** EPITECH PROJECT, 2020
** CPU.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include "IOperand.hh"
#include "Chipset.hh"
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
        void push(Memory memo, Chipset chip);
        void store(Memory memo, Chipset chip);
        void load(Memory memo, Chipset chip);
        void assert(Memory memo, Chipset chip);
        void exit();
    private:
        std::vector<std::string> registre;
};

#endif