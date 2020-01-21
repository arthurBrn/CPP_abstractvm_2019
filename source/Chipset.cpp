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

void Chipset::execution()
{
    // Point here would be to instantiate a CPU object
    // Then execute the commands until we've gone through the commands vector
    CPU cpu;
    int cpt = this->getAllCommands().size();

    this->showCommands();
    // for (int i = 0; i < cpt; i++) 
    // {
    //     std::string ola = this->getCommandAtIndex(i);
    //     switch() {
    //     }
    // }
}