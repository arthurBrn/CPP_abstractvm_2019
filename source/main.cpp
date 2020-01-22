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


    try {
        in->select_input(ac, av, chip);
        in->getFileError(chip);
    } catch(AbstractVmException error) {
        std::cout << error.getErrorMessage() << std::endl;
    }

    return 0;
}
