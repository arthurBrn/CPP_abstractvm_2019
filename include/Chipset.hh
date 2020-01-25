/*
** EPITECH PROJECT, 2020
** Chipset.hh
** File description:
** ...
*/

#ifndef _CHIPSET_HH_
#define _CHIPSET_HH_

#include "abstractvm.hh"
#include "Factory.hh"
#include "Memory.hh"
#include "CPU.hh"

class Chipset
{
public:
    Chipset();
    ~Chipset();
    std::vector<std::string> getAllCommands();
    std::string getCommandAtIndex(int index);
    std::vector<std::string> deleteStackAtIndex(int index);
    void callMemoryMap(Memory *memory, std::string instruction);
    void callCpuMap(CPU *cpu, Memory *memory, std::string str);
    void setCommand(std::string);
    void showCommands();
    int execute();
    std::string getCommandInstruction(std::string cmd);
    std::string getCommandValue(std::string cmd);
    std::string getCommandType(std::string cmd);
    void cleanCommands();
private:
    std::vector<std::string> commands;
};

#endif