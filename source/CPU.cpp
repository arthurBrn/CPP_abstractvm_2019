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

// std::map<std::string, void (CPU::*)(Memory, std::string, std::string)> CPU::getCpuCmd()
// {
//     return (this->cmdCpu);
// }

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
    
void CPU::push(Memory *memo, std::string type, std::string value)
{   
    eOperandType typeChosen = defineEnum(type);
    Factory fact;

    std::cout << "PUSH FUNCTION " << std::endl;

    IOperand *obj = fact.createOperand(typeChosen, value);
    // memo->setStack(obj);
    // std::cout << "PUSH : " + type + " | " + value << std::endl;
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
    IOperand *holder = memo->getAllStack().front();
    this->setRegistre(holder);
}

void CPU::load(Memory *memo, std::string type, std::string value)
{
    AbstractVmException exception;
    if (this->registre.size() < 1) {
        exception.setErrorMessage("Can't load register. Register is empty");
        throw exception;
    }
    IOperand* obj = this->getRegistreStackAtIndex(this->registre.size());
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
