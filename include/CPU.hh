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
        std::vector<IOperand*> getFullRegistre();
        IOperand* getRegistreStackAtIndex(int index);
        eOperandType defineEnum(std::string type);
        void setRegistre(IOperand *object);
        void setRegistreStackAtIndex(int index, IOperand* object);
        void push(Memory memo, std::string type, std::string value);
        void store(Memory memo, Chipset chip, std::string value);
        void load(Memory memo, Chipset chip, std::string value);
        void assert(Memory memo, Chipset chip, std::string value);
        void exit();
    private:
        std::vector<IOperand*> registre;
};
#endif