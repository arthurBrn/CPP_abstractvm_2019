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
    AbstractVmException exception;

    try {
        try
        {
            in->select_input(ac, av, chip);
            in->getFileError(chip);
        }
        catch(AbstractVmException error)
        {
            exception.setErrorMessage("syntax error");
            throw exception;
        }
        
        if (chip->execute() == 0)
            return (0);
    } catch(AbstractVmException exception) {
        std::cerr << exception.getErrorMessage() << std::endl;
    }
    return 0;
}
