/*
** EPITECH PROJECT, 2020
** Chipset.cpp
** File description:
** ...
*/

#include "abstractvm.hh"
#include "Chipset.hh"

Chipset::Chipset(std::vector<std::string>commands)
{
    this->commands = commands;
}

void Chipset::show_commands()
{
    for (int i = 0; i < this->commands.size(); i++)
        std::cout << commands.at(i) << std::endl;
}