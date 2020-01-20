/*
** EPITECH PROJECT, 2020
** Chipset.cpp
** File description:
** ...
*/

#include "abstractvm.hh"
#include "Chipset.hh"
#include <fstream>
#include "AbstractVmException.hh"

Chipset::Chipset()
{
    this->is_file_error = 0;
}

Chipset::~Chipset()
{
}

void Chipset::show_commands()
{
    for (int i = 0; i < this->commands.size(); i++)
        std::cout << commands.at(i) << std::endl;
}

void Chipset::check_file(std::vector<std::string> commands)
{
    std::vector<std::string> keyword = keywords();
    int len;
    int find = 0;
    int i;
    bool comment = false;

    for (int j = 0; j < commands.size(); j++)
    {
        for (i = 0; i < keyword.size(); i++)
        {
            len = keyword.at(i).size();
            if (commands.at(j).compare(0, len, keyword.at(i)) == 0)
            {
                std::cout << "match : " << keyword.at(i) << std::endl;
                find = 1;
            }
        }
        if (find == 0 && commands.at(j)[0] != ';')
            this->is_file_error = j + 1;
        find = 0;
        comment = false;
    }
}

void Chipset::get_is_file_error()
{
    if (this->is_file_error > 0)
        std::cout << "File error line " << is_file_error << std::endl;
    else
        std::cout << "all is good" << std::endl;
}

std::vector<std::string> Chipset::keywords()
{
    std::vector<std::string> keyword;
    keyword.push_back("comments");
    keyword.push_back("push");
    keyword.push_back("pop");
    keyword.push_back("clear");
    keyword.push_back("dup");
    keyword.push_back("swap");
    keyword.push_back("dump");
    keyword.push_back("assert");
    keyword.push_back("add");
    keyword.push_back("sub");
    keyword.push_back("mul");
    keyword.push_back("div");
    keyword.push_back("mod");
    keyword.push_back("load");
    keyword.push_back("store");
    keyword.push_back("print");
    keyword.push_back("exit");
    return keyword;
}

void Chipset::setVectorStack(std::string someStack)
{
    commands.push_back(someStack);
}

std::vector<std::string> Chipset::getFullVector()
{
    return this->commands;
}

void Chipset::displayVector()
{
    for (int i = 0; i < commands.size(); i++)
        std::cout << commands.at(i) << std::endl;
}

void Chipset::read(char **av)
{
    std::ifstream file;
    std::string line;

    if (av[1]) {
        file.open(av[1]);
        if (file.is_open())
            while (getline(file, line))
                this->setVectorStack(line);
    } else 
        this->read();
    file.close();
}

void Chipset::read()
{
    std::cout << "We're in the read with no file input." << std::endl;
}