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

void CPU::setCpuRegularCmd(CPU *cpu)
{
    cpu->cpuRegularMap["push"] = &CPU::push;
    cpu->cpuRegularMap["store"] = &CPU::store;
    cpu->cpuRegularMap["load"] = &CPU::load;
    cpu->cpuRegularMap["assert"] = &CPU::assert;
}

void CPU::setCpuOperatorCmd(CPU *cpu)
{
    cpu->cpuOperatorMap["add"] = &CPU::add;
    cpu->cpuOperatorMap["sub"] = &CPU::sub;
    cpu->cpuOperatorMap["mul"] = &CPU::mul;
    // cpu->cpuOperatorMap["div"] = &CPU::div;
    // cpu->cpuOperatorMap["mod"] = &CPU::mod;
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
        throw(exception);
    holder = memory->unstackAtIndex(0);
    this->setRegistre(holder);
}

void CPU::load(Memory *memo, std::string type, std::string value)
{
    AbstractVmException exception;
    Factory fact;
    IOperand *stacked;
    std::vector<IOperand *>::iterator it = this->registre.begin();
    exception.setErrorMessage("Error : can't execute load on empty register");

    if (this->getRegistreSize() < 1)
        throw(exception);
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

void CPU::add(Memory *memory)
{
    std::cout << "===addtion =====" << std::endl;
    IOperand *nb1 = memory->getAllStack().at(0);
    IOperand *nb2 = memory->getAllStack().at(1);
    IOperand *nb3 = *nb1 + *nb2;
    memory->pop();
    memory->pop();
    memory->setStack(nb3);
}

void CPU::sub(Memory *memory)
{
    std::cout << "===substraction====" << std::endl;
    IOperand *nb1 = memory->getAllStack().at(0);
    IOperand *nb2 = memory->getAllStack().at(1);
    IOperand *nb3 = *nb1 - *nb2;
    memory->pop();
    memory->pop();
    memory->setStack(nb3);
}

void CPU::mul(Memory *memory)
{
    std::cout << "===multiplication====" << std::endl;
    IOperand *nb1 = memory->getAllStack().at(0);
    IOperand *nb2 = memory->getAllStack().at(1);
    IOperand *nb3 = *nb1 * *nb2;
    memory->pop();
    memory->pop();
    memory->setStack(nb3);
}

// void CPU::div(Memory *memory)
// {
//     AbstractVmException exception;

//     exception.setErrorMessage("division by zero");

//     std::cout << "===division===="<< std::endl;
//     IOperand *nb1 = Factory::createOperand(eOperandType::DOUBLE, "15");
//     IOperand *nb2 = Factory::createOperand(eOperandType::INT16, "3");
//     nb1->debug_obj();
//     nb2->debug_obj();
//     try
//     {
//         IOperand *nb3 = *nb1 / *nb2;
//         nb3->debug_obj();
//     }
//     catch(const std::exception& e)
//     {
//         throw exception;
//     }
// }
