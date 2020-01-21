/*
** EPITECH PROJECT, 2020
** Output.hh
** File description:
** ...
*/

#include "abstractvm.hh"
#include <fstream>

#ifndef _OUTPUT_HH_
#define _OUTPUT_HH_

class Output
{
    public:
        Output();
        ~Output();
        void print(std::string output);
};

#endif