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
    return (this->registre.at(index));
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
        std::cout << this->registre.at(i)->getValue() << std::endl;
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

    IOperand *obj = fact.createOperand(this->defineEnum(type), value);
    IOperand *holder;
    memo->setStack(obj);
    for (int i = 0; i < memo->getAllStack().size(); i++)
    {
        holder = memo->getStackAtIndexX(i);
        // holder->debug_obj();
    }
}

void CPU::store(Memory *memo, std::string type, std::string value)
{
    Factory fact;
    IOperand *holder = fact.createOperand(this->defineEnum(type), value);
    // store first value of stack to register
    // this->setRegistre(memo->getAllStack().front());
    // unstack first value from stack
    // memo->pop();
    // OU

    this->displayRegistre();
}

void CPU::load(Memory *memo, std::string type, std::string value)
{
    AbstractVmException exception;
    Factory fact;
    IOperand *stacked;
    exception.setErrorMessage("Can't load register. Register is empty");

    stacked = fact.createOperand(this->defineEnum(type), value);
    memo->setStack(stacked);
}

void CPU::assert(Memory *memo, std::string type, std::string value)
{
    AbstractVmException exception;
    Factory fact;

    exception.setErrorMessage("Assert: the value does not match the stack top value.");
    IOperand *obj = fact.createOperand(this->defineEnum(type), value);
    IOperand *topStack = memo->getAllStack().front();
    if ((obj->getType() != topStack->getType()) && (obj->getValue() != topStack->getValue()))
        throw(exception);
}

int CPU::exit()
{
    return (0);
}
