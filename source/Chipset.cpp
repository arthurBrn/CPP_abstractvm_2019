/*
** EPITECH PROJECT, 2020
** Chipset.cpp
** File description:
** ...
*/

#include "abstractvm.hh"
#include "Chipset.hh"
#include <fstream>
#include "AbstractVmException.hh"
#include "CPU.hh"

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
    this->getAllCommands().at(index).erase();
}

void Chipset::execution()
{
    Memory memo;
    CPU cpu;
    // for (int i = 0; i < this->getAllCommands().size(); i++) {}
    
    
}