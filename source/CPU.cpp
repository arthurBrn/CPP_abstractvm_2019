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

void CPU::push(Memory *memo, std::string type, std::string value)
{
    Factory fact;

    IOperand *obj = fact.createOperand(this->defineEnum(type), value);
    IOperand *holder;
    memo->setStack(obj);
    // std::cout << "MEMORY STACK PUSH" << std::endl;
    for (int i = 0; i < memo->getAllStack().size(); i++)
    {
        // std::cout << "Iteration : " + i << std::endl;
        holder = memo->getStackAtIndexX(i);
        holder->debug_obj();
    }
}

void CPU::setCpuCmd(CPU *cpu)
{
    cpu->cmdCpu["push"] = &CPU::push;
    cpu->cmdCpu["store"] = &CPU::store;
    cpu->cmdCpu["load"] = &CPU::load;
    cpu->cmdCpu["assert"] = &CPU::assert;
}

void CPU::store(Memory *memo, std::string type, std::string value)
{
    // std::cout << "===== CPU STORE ====" << std::endl;
    // est-ce qu'on doit vkérifier si la stack est vide ou non ???
    IOperand *holder = memo->getAllStack().front();
    this->setRegistre(holder);
    this->displayRegistre();
}

void CPU::load(Memory *memo, std::string type, std::string value)
{
    AbstractVmException exception;
    if (this->registre.empty())
    {
        exception.setErrorMessage("Can't load register. Register is empty");
        throw exception;
    }
    IOperand *obj = this->getRegistreStackAtIndex(this->registre.size());
    memo->setStack(obj);
}

void CPU::assert(Memory *memo, std::string type, std::string value)
{
    // verify that v is equal to the value at the top of the stack
    // For that we'll use getType form IOperand
}

void CPU::exit()
{
    // do smthg
}

void CPU::add(Memory *memory)
{
    std::cout << "===print calcul"<< std::endl;
    IOperand *nb1 = Factory::createOperand(eOperandType::INT16, "15");
    IOperand *nb2 = Factory::createOperand(eOperandType::INT16, "10");
    nb1->debug_obj();
    nb2->debug_obj();
    IOperand *nb3 = *nb1 + *nb2;
   
}