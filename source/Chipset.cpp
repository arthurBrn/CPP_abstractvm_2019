/*
** EPITECH PROJECT, 2020
** Chipset.cpp
** File description:
** ...
*/

#include "abstractvm.hh"

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

void Chipset::deleteStackAtIndex(int index)
{
    std::vector<std::string>::iterator it = this->commands.begin();
    std::advance(it, index);
    this->commands.erase(it);
}

std::map<std::string, int> Chipset::getFullCommandMap()
{
    return (this->cmdMap);
}

void Chipset::initCommandMap(Memory memory)
{
    // void (*fun_ptr)(void);
    // fun_ptr = memory.clear(); 

    this->cmdMap.insert({"push", 1});
    this->cmdMap.insert({"pop", 1});
    this->cmdMap.insert({"clear", 1});
    this->cmdMap.insert({"dup", 1});
    this->cmdMap.insert({"swap", 1});
    this->cmdMap.insert({"dump", 1});
    this->cmdMap.insert({"assert", 1});
    this->cmdMap.insert({"add", 1});
    this->cmdMap.insert({"sub", 1});
    this->cmdMap.insert({"mul", 1});
    this->cmdMap.insert({"div", 1});
    this->cmdMap.insert({"mod", 1});
    this->cmdMap.insert({"load", 1});
    this->cmdMap.insert({"store", 1});
    this->cmdMap.insert({"print", 1});
    this->cmdMap.insert({"exit", 1});
}

void Chipset::setCommandMap(std::string cmd, int nb)
{
    this->cmdMap.insert({cmd, nb});
}

void Chipset::execution()
{
    auto iterator = this->getAllCommands().begin();
    Memory memory;
    CPU cpu;
    // Operand operand;
    std::string str;
    std::string instruction;
    std::string value;
    std::string type;
    int escape = 0;
    int brackets = 0;
    int fstBrack = 0;
    int sndBrack = 0;
    std::map<std::string, int>::iterator itr;

    for (int i = 0; i < this->getAllCommands().size(); i++)
    {
        this->initCommandMap(memory);
        str = this->getCommandAtIndex(i);
        escape = str.find_first_of(" ");
        if (str.substr(0, escape)[0] != ';')
            instruction = str.substr(0, escape);
        if (str.size() > escape && str[0] != ';') {
            type = str.substr(escape, str.size());
            fstBrack = type.find_first_of("(");
            sndBrack = type.find_first_of(")");
            value = type.substr((fstBrack + 1), (sndBrack -1));
            type = str.substr(escape, fstBrack);
            std::cout << "type : " + type << std::endl;
            std::cout << "value : " + value << std::endl;
        }
        for (itr = this->cmdMap.begin(); itr != this->cmdMap.end(); itr++)
        {
            if (instruction == itr->first)
                std::cout << "Instruction : " + instruction + " match : " + itr->first << std::endl;
            if (instruction == "push") {
                cpu.push(memory, type, value);
            }
        }
    }
}