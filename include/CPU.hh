/*
** EPITECH PROJECT, 2020
** CPU.hh
** File description:
** ...
*/

#ifndef _CPU_HH_
#define _CPU_HH_

#include "abstractvm.hh"
#include "AbstractVmException.hh"
#include "Factory.hh"
#include "Operand.hh"
#include "Memory.hh"
#include "IOperand.hh"
#include "eOperandType.hh"

class Operand;

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
    Operand *_operand;
};

#endif