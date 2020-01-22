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

void Chipset::deleteStackAtIndex(int index)
{
    std::vector<std::string>::iterator it = this->commands.begin();
    std::advance(it, index);
    this->commands.erase(it);
}

void Chipset::execution()
{
    auto iterator = this->getAllCommands().begin();
    Memory memo;
    CPU cpu;
    std::string str;
    std::string instruction;
    std::string value;
    int escape = 0;
    int brackets = 0;

    for (int i = 0; i < this->getAllCommands().size(); i++)
    {
        str = this->getCommandAtIndex(i);
        std::cout << str << std::endl;
        escape = str.find_first_of(" ");
        instruction = str.substr(0, escape);

        // if (instruction.compare(";") != 0) {
            // std::cout << instruction << std::endl;
        // }
        if (str.size() > escape) {
            value = str.substr(escape, str.size());
            std::cout << value << std::endl;
        }
        // Parcour le tableau et les matchs avec tableau de pointeur sur fonction ?
    }
}