/*
** EPITECH PROJECT, 2020
** CPU.cpp
** File description:
** ...
*/

#include "CPU.hh"

CPU::CPU()
{
}

CPU::~CPU()
{
}

int CPU::getRegistreSize()
{
    return (this->registre.size());
}

std::vector<IOperand *> CPU::getFullRegistre()
{
    return (this->registre);
}

IOperand *CPU::getRegistreStackAtIndex(int index)
{
    // std::vector<IOperand*>::iterator it = this->registre.begin();
    // std::advance(it, index);
    return (this->getFullRegistre().at(index));
}

void CPU::setRegistreStackAtIndex(int index, IOperand *ioperandobject)
{
    this->registre.at(index) = ioperandobject;
}

void CPU::setRegistre(IOperand *object)
{
    this->registre.push_back(object);
}

void CPU::displayRegistre()
{
    std::cout << "===== REGISTRE =====" << std::endl;
    for (int i = 0; i < this->registre.size(); i++)
    {
        std::cout << "Registre value : ";
        std::cout << this->registre.at(i)->getValue() << std::endl;
        std::cout << "Registre type : ";
        std::cout << this->registre.at(i)->getType() << std::endl;
    }
}

eOperandType CPU::defineEnum(std::string type)
{
    eOperandType value;
    if (type.compare("int8") == 0)
        value = eOperandType::INT8;
    else if (type.compare("int16") == 0)
        value = eOperandType::INT16;
    else if (type.compare("int32") == 0)
        value = eOperandType::INT32;
    else if (type.compare("float") == 0)
        value = eOperandType::FLOAT;
    else if (type.compare("double") == 0)
        value = eOperandType::DOUBLE;
    else if (type.compare("bigdecimal") == 0)
        value = eOperandType::BIGDECIMAL;
    return (value);
}

void CPU::setCpuCmd(CPU *cpu)
{
    cpu->cmdCpu["push"] = &CPU::push;
    cpu->cmdCpu["store"] = &CPU::store;
    cpu->cmdCpu["load"] = &CPU::load;
    cpu->cmdCpu["assert"] = &CPU::assert;
}

void CPU::push(Memory *memo, std::string type, std::string value)
{
    Factory fact;
    IOperand *obj;
    IOperand *holder;

    obj = fact.createOperand(this->defineEnum(type), value);
    memo->setStack(obj);
    for (int i = 0; i < memo->getAllStack().size(); i++)
        holder = memo->getStackAtIndexX(i);
}

void CPU::store(Memory *memory, std::string type, std::string value)
{
    AbstractVmException exception;
    IOperand *holder;

    exception.setErrorMessage("ERROR Store : Can not execute store on empty stack");
    if (memory->getAllStack().empty())
        throw (exception);
    holder = memory->unstackAtIndex(0);
    this->setRegistre(holder);
}

void CPU::load(Memory *memo, std::string type, std::string value)
{
    AbstractVmException exception;
    Factory fact;
    IOperand *stacked;
    std::vector<IOperand*>::iterator it = this->registre.begin();
    exception.setErrorMessage("Error : can't execute load on empty register");

    if (this->getRegistreSize() < 1)
        throw (exception);
    stacked = this->getRegistreStackAtIndex(0);
    this->registre.erase(it);
    memo->setStack(stacked);
}

void CPU::assert(Memory *memo, std::string type, std::string value)
{
    AbstractVmException exception;
    Factory fact;
    IOperand *obj;
    IOperand *topStack;

    exception.setErrorMessage("Assert: the value does not match the stack top value.");
    obj = fact.createOperand(this->defineEnum(type), value);
    topStack = memo->getAllStack().front();
    if ((obj->getType() != topStack->getType()) || (obj->getValue() != topStack->getValue()))
        throw(exception);
}

int CPU::exit()
{
    return (0);
}


// void Operand::setOperandCmd(Operand *operand)
// {
    // operand->cmdOperand["add"] = &Operand::add;
    // operand->cmdOperand["sub"] = &Operand::sub;
    // operand->cmdOperand["mul"] = &Operand::mul;
    // operand->cmdOperand["div"] = &Operand::div;
    // operand->cmdOperand["mod"] = &Operand::mod;
// }

// std::map<std::string, void (Operand::*)(Memory, CPU)> Operand::getOperandCmd()
// {
    // return (this->cmdOperand);
// }

// void Operand::add(Memory memory, CPU cpu)
// {
// }
// void Operand::sub(Memory objMemory, CPU objCPU)
// {
// }
// void Operand::mul(Memory objMemory, CPU objCPU)
// {
// }
// void Operand::div(Memory objMemory, CPU objCPU)
// {
// }
// void Operand::mod(Memory objMemory, CPU objCPU)
// {
// }