/*
** EPITECH PROJECT, 2020
** Input.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include <fstream>
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
    void printFileError();
    int getFileError();
    void setFileError(int value);
    void checkFile(Chipset *chip);

private:
    std::vector<std::string> keywords;
    std::vector<std::string> commands;
    std::string line;
    int fileError;
};

#endif