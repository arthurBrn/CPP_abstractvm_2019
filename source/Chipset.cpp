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
    std::cout << "SIZE : ";
    std::cout << this->getAllCommands().size() << std::endl;
    for (int i = 0; i < this->getAllCommands().size(); i++)
    {
        if (this->getAllCommands().at(i)[0] == ';')
        {
            std::cout << "match ; " << std::endl;
            std::cout << "Command : " + this->getAllCommands().at(i) << std::endl;
            this->deleteStackAtIndex(i);
            i = 0;
        }
    }
    std::cout << "SIZE : ";
    std::cout << this->getAllCommands().size() << std::endl;
}

int Chipset::execute()
{
    auto iterator = this->getAllCommands().begin();
    std::map<std::string, int>::iterator itr;
    Memory *memory = new Memory();
    CPU *cpu = new CPU();
    std::string instruction;
    std::string value = "no";
    std::string type = "no";
    std::string str;
    int escape = 0;
    std::map<std::string, void (Memory::*)()>::iterator memoryIt;
    std::map<std::string, void (CPU::*)(Memory *, std::string, std::string)>::iterator cpuIt;

    this->cleanCommands();
    // this->showCommands();
    memory->setMemoryCmd(memory);
    cpu->setCpuCmd(cpu);
    std::cout << "SIZE : " << std::endl;
    std::cout << this->getAllCommands().size() << std::endl;
    for (int i = 0; i < this->getAllCommands().size(); i++)
    {
        str = this->getCommandAtIndex(i);
        escape = str.find_first_of(" ");
        if (str[0] != ';')
        {
            instruction = this->getCommandInstruction(str);
            if (instruction.compare("exit") == 0)
                return (0);
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
                    // Factory fac;    
                    // IOperand *nb = fac.createOperand(cpu->defineEnum(type), value);
                }
            }
        }

        std::cout << "Command : " + instruction + " type : " + type + " value : " + value << std::endl;
        // str = "";
        // instruction = "";
        // value = "";
        // type = "";
    }
    return (0);
}