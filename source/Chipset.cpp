/*
** EPITECH PROJECT, 2020
** Chipset.cpp
** File description:
** ...
*/

#include "AbstractVmException.hh"
#include "abstractvm.hh"
#include "Chipset.hh"
#include <fstream>
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

std::vector<std::string> Chipset::deleteStackAtIndex(int index)
{
    std::vector<std::string>::iterator it = this->commands.begin();
    std::advance(it, index);
    this->commands.erase(it);
    return this->commands;
}

void Chipset::execution()
{
    Memory memo;
    CPU cpu;
    // for (int i = 0; i < this->getAllCommands().size(); i++) {}
}