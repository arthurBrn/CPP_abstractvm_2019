/*
** EPITECH PROJECT, 2020
** Chipset.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include "Memory.hh"

#ifndef _CHIPSET_HH_
#define _CHIPSET_HH_

class Chipset
{
public:
    Chipset();
    ~Chipset();
    std::vector<std::string> getAllCommands();
    std::string getCommandAtIndex(int index);
    std::vector<std::string> deleteStackAtIndex(int index);
    void setCommand(std::string);
    void showCommands();
    void execution();
    void initCommandMap(Memory memory);
    std::map<std::string, int> getFullCommandMap();
    void setCommandMap(std::string cmd, int nb);
private:
    std::vector<std::string> commands;
    std::map<std::string, int> cmdMap;
};

#endif