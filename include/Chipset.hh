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

class Chipset {
    public:
        Chipset();
        ~Chipset();
        void show_commands();
        void read();
        void read(char **av);
        void parseFile(std::string file);
        void check_file(std::vector<std::string>commands);
        void get_is_file_error();
        std::vector<std::string> keywords();
        std::string test();
        void setVectorStack(std::string someStack);
        std::vector<std::string> getFullVector();
        void displayVector();
    private :
        std::vector<std::string> commands;
        int is_file_error;

};

#endif