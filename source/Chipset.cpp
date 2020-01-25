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

int Chipset::execute()
{
    auto iterator = this->getAllCommands().begin();
    std::map<std::string, int>::iterator itr;
    // Operand *operand = new Operand();
    Memory *memory = new Memory();
    CPU *cpu = new CPU();
    std::string instruction;
    std::string value = "no";
    std::string type = "no";
    std::string str;
    int escape = 0;
    std::map<std::string, void (Memory::*)()>::iterator memoryIt;
    std::map<std::string, void (CPU::*)(Memory *, std::string, std::string)>::iterator cpuIt;
    // std::map<std::string, void (Operand::*)(Memory, CPU)> cmdOperand;

    this->cleanCommands();
    memory->setMemoryCmd(memory);
    cpu->setCpuCmd(cpu);
    for (int i = 0; i < this->getAllCommands().size(); i++)
    {
        str = this->getCommandAtIndex(i);
        escape = str.find_first_of(" ");
        if (str[0] != ';')
        {
            instruction = this->getCommandInstruction(str);
            if (instruction.compare("exit") == 0)
                cpu->exit();
            for (memoryIt = memory->memoryCmd.begin(); memoryIt != memory->memoryCmd.end(); memoryIt++)
            {
                if (instruction.compare(memoryIt->first) == 0)
                {
                    void (Memory::*ptr)() = memory->memoryCmd[instruction];
                    (memory->*ptr)();
                }
            }
        }
        if (str.size() > escape && str[0] != ';')
        {
            value = this->getCommandValue(str);
            type = this->getCommandType(str);
            for (cpuIt = cpu->cmdCpu.begin(); cpuIt != cpu->cmdCpu.end(); cpuIt++)
            {
                if (instruction.compare(cpuIt->first) == 0)
                {
                    void (CPU::*cpuPtr)(Memory *, std::string, std::string) = cpu->cmdCpu[instruction];
                    (cpu->*cpuPtr)(memory, type, value);
                }
            }
        }
    }
    return (0);
}