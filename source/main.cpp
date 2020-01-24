/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** ...
*/

#include "Chipset.hh"
#include "Input.hh"
#include "AbstractVmException.hh"

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
    chip->execute();
    return 0;
}
