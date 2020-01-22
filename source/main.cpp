/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** ...
*/

#include "abstractvm.hh"

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
    chip->execution();
    return 0;
}
