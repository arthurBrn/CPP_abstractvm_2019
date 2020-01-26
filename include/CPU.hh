/*
** EPITECH PROJECT, 2020
** CPU.hh
** File description:
** ...
*/

#ifndef _CPU_HH_
#define _CPU_HH_

#include "abstractvm.hh"
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
    void setCpuRegularCmd(CPU *cpu);
    void setCpuOperatorCmd(CPU *cpu);
    void push(Memory *memo, std::string type, std::string value);
    void store(Memory *memo, std::string type, std::string value);
    void load(Memory *memo, std::string type, std::string value);
    void assert(Memory *memo, std::string type, std::string value);
    int exit();
    void move_stack(Memory *memory, IOperand *nb);
    void add(Memory *memory);
    void sub(Memory *memory);
    void mul(Memory *memory);
    void div(Memory *memory);
    void mod(Memory *memory);
    std::map<std::string, void (CPU::*)(Memory *, std::string, std::string)> cpuRegularMap;
    std::map<std::string, void (CPU::*)(Memory *)> cpuOperatorMap;
private:
    std::vector<IOperand *> registre;
    Operand *_operand;
};

#endif