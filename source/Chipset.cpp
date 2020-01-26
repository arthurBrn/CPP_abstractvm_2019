/*
** EPITECH PROJECT, 2020
** Chipset.cpp
** File description:
** ...
*/

#include "Chipset.hh"

Chipset::Chipset()
{
}

Chipset::~Chipset()
{
}

void Chipset::showCommands()
{
    for (int i = 0; i < this->commands.size(); i++)
        std::cout << this->commands.at(i) << std::endl;
}

std::vector<std::string> Chipset::getAllCommands()
{
    return (this->commands);
}

std::string Chipset::getCommandAtIndex(int index)
{
    return (this->commands.at(index));
}

void Chipset::setCommand(std::string command)
{
    this->commands.push_back(command);
}

std::vector<std::string> Chipset::deleteStackAtIndex(int index)
{
    std::vector<std::string>::iterator it = this->commands.begin();
    std::advance(it, index);
    this->commands.erase(it);
    return this->commands;
}

std::string Chipset::getCommandInstruction(std::string cmd)
{
    int escape = 0;
    std::string instruction;

    escape = cmd.find_first_of(" ");
    instruction = cmd.substr(0, escape);
    return (instruction);
}

std::string Chipset::getCommandType(std::string cmd)
{
    std::string type;
    int escape = 0;
    int fstBracket = 0;
    fstBracket = cmd.find("(");
    type = cmd.substr(0, cmd.find("("));
    return (type.substr(type.find(" ") + 1, type.size()));
}

std::string Chipset::getCommandValue(std::string cmd)
{
    std::string value;
    std::string delimiter = ")";
    std::string delimiter_two = "(";
    value = cmd.substr(0, cmd.find(delimiter));
    value = value.substr((value.find(delimiter_two) + 1), value.size());
    return (value);
}

void Chipset::cleanCommands()
{
    for (int i = 0; i < this->getAllCommands().size(); i++)
    {
        if (this->getAllCommands().at(i)[0] == ';')
        {
            this->deleteStackAtIndex(i);
            i = 0;
        }
    }
}

void Chipset::callMemoryMap(Memory *memory, std::string instruction)
{
    std::map<std::string, void (Memory::*)()>::iterator memoryIt;

    for (memoryIt = memory->memoryCmd.begin(); memoryIt != memory->memoryCmd.end(); memoryIt++)
    {
        if (instruction.compare(memoryIt->first) == 0)
        {
            void (Memory::*ptr)() = memory->memoryCmd[instruction];
            (memory->*ptr)();
        }
    }
}

void Chipset::callCpuMap(CPU *cpu, Memory *memory, std::string str)
{
    std::string instruction = this->getCommandInstruction(str);
    std::string type = this->getCommandType(str);
    std::string value = this->getCommandValue(str);
    AbstractVmException exception;

    exception.setErrorMessage("Calcul Error");
    std::map<std::string, void (CPU::*)(Memory *, std::string, std::string)>::iterator cpuIt;

    for (cpuIt = cpu->cpuRegularMap.begin(); cpuIt != cpu->cpuRegularMap.end(); cpuIt++)
    {
        if (instruction.compare(cpuIt->first) == 0)
        {
            void (CPU::*cpuPtr)(Memory *, std::string, std::string) = cpu->cpuRegularMap[instruction];
            (cpu->*cpuPtr)(memory, type, value);
            // cpu->div(memory);
        }
    }
}

void Chipset::callCpuOperator(Memory *memory, CPU *cpu, std::string cmds)
{
    std::string instruction = this->getCommandInstruction(cmds);
    std::map<std::string, void (CPU::*)(Memory *)>::iterator operatorIt;

    AbstractVmException exception;
    exception.setErrorMessage("ERROR : Can't add on stack with less than two values.");
    for (operatorIt = cpu->cpuOperatorMap.begin(); operatorIt != cpu->cpuOperatorMap.end(); operatorIt++)
    {
        if (instruction.compare(operatorIt->first) == 0)
        {
            if (memory->getStackSize() < 2)
                throw(exception);   
            void (CPU::*opPtr)(Memory *) = cpu->cpuOperatorMap[instruction];
            (cpu->*opPtr)(memory);
        }
    }
}

int Chipset::execute()
{
    std::vector<std::string>::iterator cmdsIt;
    Memory *memory = new Memory();
    CPU *cpu = new CPU();
    std::string instruction;
    std::string str;
    int escape = 0;
    auto iterator = this->getAllCommands().begin();
    std::map<std::string, int>::iterator itr;

    this->cleanCommands();
    memory->setMemoryCmd(memory);
    cpu->setCpuRegularCmd(cpu);
    cpu->setCpuOperatorCmd(cpu);
    Factory fac;
    IOperand *nb = fac.createOperand(eOperandType::INT32, "34");
    for (int i = 0; i < this->getAllCommands().size(); i++)
    {
        str = this->getCommandAtIndex(i);
        escape = str.find_first_of(" ");
        if (str[0] != ';')
        {
            instruction = this->getCommandInstruction(str);
            if (instruction.compare("exit") == 0)
                cpu->exit();
            this->callMemoryMap(memory, instruction);
            this->callCpuOperator(memory, cpu, str);
        }
        if (str.size() > escape && str[0] != ';')
            this->callCpuMap(cpu, memory, str);
    }
    return (0);
}