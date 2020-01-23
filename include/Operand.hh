/*
** EPITECH PROJECT, 2020
** Operand.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include "IOperand.hh"
#include "CPU.hh"
#include "Memory.hh"

#ifndef _OPERAND_HH_
#define _OPERAND_HH_

class Operand : public IOperand
{
    public:
        Operand();
        ~Operand();
        IOperand* getValue();
        void setValue(IOperand* newValue);
        void add(Memory objMemory, CPU objCPU);
        void sub(Memory objMemory, CPU objCPU);
        void mul(Memory objMemory, CPU objCPU);
        void div(Memory objMemory, CPU objCPU);
        void mod(Memory objMemory, CPU objCPU);
        void setOperandCmd(Operand *operand);
        std::map<std::string, void(Operand::*)(Memory, CPU)> getOperandCmd();
        std::string toString() const override;
        eOperandType getType() const override;
        // IOperand *operator+(const IOperand &rhs) const override;
        // IOperand *operator-(const IOperand &rhs) const override;
        // IOperand *operator*(const IOperand &rhs) const override;
        // IOperand *operator/(const IOperand &rhs) const override;
        // IOperand *operator%(const IOperand &rhs) const override;
    private:
        IOperand* value;
        std::map<std::string, void(Operand::*)(Memory, CPU)> cmdOperand;
};

#endif
