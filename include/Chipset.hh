/*
** EPITECH PROJECT, 2020
** Chipset.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include "IOperand.hh"
#include <stdbool.h>

#ifndef _CHIPSET_HH_
#define _CHIPSET_HH_

class Chipset
{
public:
    Chipset();
    ~Chipset();
    std::vector<std::string> getAllCommands();
    std::string getCommandAtIndex(int index);
    void deleteStackAtIndex(int index);
    void setCommand(std::string);
    void showCommands();
    void execution();
private:
    std::vector<std::string> commands;
};

#endif