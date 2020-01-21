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
#include "Input.hh"
#include "Output.hh"
#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
    Input *in = new Input();
    Chipset *chip = new Chipset;

    in->read(av, chip);
    in->printFileError();
    std::cout << "chip show command" << std::endl;
    chip->showCommands();
    std::cout << chip->getAllCommands().size() << std::endl;
    std::cout << "main execution" << std::endl;
    chip->execution();
    // Make sur no exception are thrown after the read
    // If there is, launch an exception through output
    return 0;
}
