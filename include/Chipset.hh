/*
** EPITECH PROJECT, 2020
** Chipset.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include "IOperand.hh"

#ifndef _CHIPSET_HH_
#define _CHIPSET_HH_

class Chipset {
    public:
        Chipset(std::vector<std::string>commands);
        void show_commands();
        void read();
        void read(std::string file);
        void parseFile(std::string file);
    private :
        std::vector<std::string>commands;
};

#endif