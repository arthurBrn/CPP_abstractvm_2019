/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** ...
*/

#include "Chipset.hh"
#include "Input.hh"
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
    for (int i = 0; i < chip->getAllCommands().size(); i++) 
        std::cout << chip->getCommandAtIndex(i) << std::endl;
    chip->execute();
    return 0;
}
