/*
** EPITECH PROJECT, 2020
** Input.hh
** File description:
** ...
*/

#ifndef _INPUT_HH_
#define _INPUT_HH_

#include "abstractvm.hh"
#include "Chipset.hh"

class Input
{
public:
    Input();
    ~Input();
    std::string getLine();
    void setLine(std::string);
    void read(Chipset *chip);
    void read(std::string path, Chipset *chip);
    void getFileError(Chipset *chip);
    void setFileError(int value);
    void checkFile(Chipset *chip);
    void select_input(int ac, char **av, Chipset *chip);
    int syntax(std::string str);

private:
    std::string line;
    int fileError;
};

#endif