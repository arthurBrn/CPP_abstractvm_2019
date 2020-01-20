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

    if (av[1])
        chip->read(av);
    chip->check_file(chip->getFullVector());
    chip->get_is_file_error();
    chip->displayVector();
    return 0;
}
