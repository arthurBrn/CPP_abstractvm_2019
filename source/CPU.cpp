/*
** EPITECH PROJECT, 2020
** CPU.cpp
** File description:
** ...
*/

#include "abstractvm.hh"
// #include "Factory.hh"

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

std::vector<IOperand*> CPU::getFullRegistre()
{
    return (this->registre);
}

IOperand* CPU::getRegistreStackAtIndex(int index)
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

eOperandType CPU::defineEnum(std::string type)
{
    eOperandType value;
    if (type.compare("int8") == 0)
        value = eOperandType::INT8;
    if (type.compare("int16") == 0)
        value = eOperandType::INT16;
    if (type.compare("int32") == 0)
        value = eOperandType::INT32;
    if (type.compare("float") == 0)
        value = eOperandType::FLOAT;
    if (type.compare("double") == 0)
        value = eOperandType::DOUBLE;
    if (type.compare("bigdecimal") == 0)
        value = eOperandType::BIGDECIMAL;
    return (value);
}

void CPU::push(Memory memo, std::string type, std::string value)
{   
    eOperandType typeChosen = this->defineEnum(type);
    Factory fact;

    IOperand *obj = fact.createOperand(typeChosen, value);
    memo.setStack(obj);
}

void CPU::store(Memory memo, Chipset chip, std::string value)
{
    IOperand *holder = memo.getStackTopPile();
    this->setRegistre(holder);
}

void CPU::load(Memory memo, Chipset chip, std::string value)
{
    if (this->registre.size() < 1)
        throw new AbstractVmException("Can't load register. Register is empty");
    IOperand* obj = this->getRegistreStackAtIndex(this->registre.size());
    memo.setStack(obj);
}

void CPU::assert(Memory memo, Chipset chip, std::string value)
{
    // verify that v is equal to the value at the top of the stack

    // For that we'll use getType form IOperand
}

void CPU::exit()
{
    // do smthg
}
