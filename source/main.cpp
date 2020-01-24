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
        // for (int i = 0; i < chip->getAllCommands().size(); i++)
            // std::cout << chip->getCommandAtIndex(i) << std::endl;
    } catch(AbstractVmException error) {
        std::cout << error.getErrorMessage() << std::endl;
    }
    chip->execute();
    return 0;
}
