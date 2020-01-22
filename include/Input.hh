/*
** EPITECH PROJECT, 2020
** Input.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include "Chipset.hh"

#ifndef _INPUT_HH_
#define _INPUT_HH_

class Input
{
public:
    Input();
    ~Input();
    std::string getLine();
    void setLine(std::string);
    void read(Chipset *chip);
    void read(char **av, Chipset *chip);
    int getFileError(Chipset *chip);
    void setFileError(int value);
    void checkFile(Chipset *chip);
    void select_input(int ac, char **av, Chipset *chip);
    int syntax(std::string str);

private:
    std::string line;
    int fileError;
};

#endif