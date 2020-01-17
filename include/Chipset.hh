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
        void read();
        void read(std::string file);
        void parseFile(std::string file);
};

#endif