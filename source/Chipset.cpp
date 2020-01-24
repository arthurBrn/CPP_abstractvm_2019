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
    std::string str;

    escape = cmd.find_first_of(" ");
    str = cmd.substr(0, escape);
    return (str);
}

std::string Chipset::getCommandType(std::string cmd)
{
    std::string type;
    int escape = 0;
    int fstBracket = 0;

    escape = cmd.find_first_of(" ");
    fstBracket = cmd.find_first_of(")");
    type = cmd.substr(escape, fstBracket);
    return (type);
}

std::string Chipset::getCommandValue(std::string cmd)
{
    std::string value;
    int fstBracket = 0;
    int sndBracket = 0;

    fstBracket = cmd.find_first_of("(");
    sndBracket = cmd.find_first_of(")");
    value = cmd.substr(fstBracket, fstBracket);
    return (value);
}

void Chipset::execute()
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
    std::map<std::string, void (Memory::*)()>::iterator it;

    memory->setMemoryCmd(memory);
    for (int i = 0; i < this->getAllCommands().size(); i++)
    {
        str = this->getCommandAtIndex(i);
        escape = str.find_first_of(" ");
        if (str[0] != ';')
        {
            instruction = this->getCommandInstruction(this->getCommandAtIndex(i));
            std::cout << "Instruction : " + instruction << std::endl;
        }
        if (str.size() > escape && str[0] != ';')
        {
            value = this->getCommandValue(this->getCommandAtIndex(i));
            type = this->getCommandType(this->getCommandAtIndex(i));
            std::cout << "Value : " + value << std::endl;
            std::cout << "Type : " + type << std::endl;
        }
        for (it = memory->memoryCmd.begin(); it != memory->memoryCmd.end(); it++)
        {
            if (instruction.compare(it->first) == 0)
            {
                std::cout << "match : " + it->first << std::endl;
                void (Memory::* ptr)() = memory->memoryCmd[instruction];
                (memory->*ptr)();
            }
        }
    }
}