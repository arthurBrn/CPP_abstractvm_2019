/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** ...
*/

#include "abstractvm.hh"
#include "Factory.hh"
#include "IOperand.hh"
#include "AbstractVmException.hh"
#include "Chipset.hh"
#include <fstream>
#include <iostream>

int main (int ac, char **av)
{
    std::vector<std::string>commands;
    std::ifstream file;
    file.open(av[1]);
    std::string line;
    if (file.is_open()) {
        while (getline(file, line))
        commands.push_back(line);
    } else
        std::cout << "no file match" << std::endl;
    file.close();
    Chipset mychip(commands);
    mychip.check_file(commands);
    mychip.get_is_file_error();
    return 0;
}
