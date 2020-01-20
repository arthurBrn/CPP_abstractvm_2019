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

int main(int ac, char **av)
{
    std::ifstream file;
    Chipset *chip = new Chipset();

    file.open(av[1]);
    std::string line;
    if (file.is_open())
    {
        while (getline(file, line))
            chip->setVectorStack(line);
    }
    else
        std::cout << "no file match" << std::endl;
    file.close();
    chip->check_file(chip->getFullVector());
    chip->get_is_file_error();
    chip->displayVector();
    return 0;
}
