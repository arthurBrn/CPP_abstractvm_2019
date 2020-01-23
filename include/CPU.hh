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

class CPU
{
public:
    CPU();
    ~CPU();
    int getRegistreSize();
    std::vector<IOperand *> getFullRegistre();
    IOperand *getRegistreStackAtIndex(int index);
    eOperandType defineEnum(std::string type);
    void setRegistre(IOperand *object);
    void setRegistreStackAtIndex(int index, IOperand *object);
    void setCpuCmd(CPU *cpu);
    std::map<std::string, void (CPU::*)(Memory, std::string, std::string)> getCpuCmd();
    void push(Memory memo, std::string type, std::string value);
    void store(Memory memo, std::string type, std::string value);
    void load(Memory memo, std::string type, std::string value);
    void assert(Memory memo, std::string type, std::string value);
    void exit();
private:
    std::vector<IOperand *> registre;
    std::map<std::string, void (CPU::*)(Memory, std::string, std::string)> cmdCpu;
};

#endif