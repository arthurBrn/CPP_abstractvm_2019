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
    void displayRegistre();
    void setCpuRegularCmd(CPU *cpu);
    void setCpuOperatorCmd(CPU *cpu);
    // std::map<std::string, void (CPU::*)(Memory, std::string, std::string)> getCpuCmd();
    void push(Memory *memo, std::string type, std::string value);
    void store(Memory *memo, std::string type, std::string value);
    void load(Memory *memo, std::string type, std::string value);
    void assert(Memory *memo, std::string type, std::string value);
    int exit();
    std::map<std::string, void (CPU::*)(Memory*, std::string, std::string)> cpuRegularMap;
    std::map<std::string, void (CPU::*)(Memory*, CPU*)> cpuOperatorMap;

    // std::map<std::string, void (Operand::*)(Memory, CPU)> getOperandCmd();
    void add(Memory *memory, CPU *cpu);
    void sub(Memory *memory, CPU *cpu);
    void mul(Memory *memory, CPU *cpu);
    void div(Memory *memory, CPU *cpu);
    void mod(Memory *memory, CPU *cpu);
private:
    // std::map<std::string, void (Operand::*)(Memory, CPU)> cmdOperand;
    std::vector<IOperand *> registre;
    Operand *_operand;
};

#endif