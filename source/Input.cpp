/*
** EPITECH PROJECT, 2020
** Input.cpp
** File description:
** ...
*/

#include "abstractvm.hh"
#include "Input.hh"
#include "Chipset.hh"
#include <fstream>

Input::Input()
{
    this->fileError = 0;
}
Input::~Input()
{
}

std::string Input::getLine()
{
    return (this->line);
}

void Input::setLine(std::string someLine)
{
    this->line = someLine;
}

int Input::getFileError()
{
    return this->fileError;
}

void Input::setFileError(int newValue)
{
    this->fileError = newValue;
}

void Input::printFileError()
{
    if (this->getFileError() > 0)
        std::cout << "File error line " << this->getFileError() << std::endl;
    else
        std::cout << "all is good" << std::endl;
}

void Input::checkFile(Chipset *chip)
{
    int len;
    int find = 0;
    int i;
    int flag = 0;
    bool comment = false;

    this->setKeywords();
    for (int j = 0; j < chip->getAllCommands().size(); j++)
    {
        for (i = 0; i < this->getKeywords().size(); i++)
        {
            len = this->getKeywords().at(i).size();
            if (chip->getAllCommands().at(j).compare(0, len, this->getKeywords().at(i)) == 0)
            {
                std::cout << "match : " << this->getKeywords().at(i) << std::endl;
                find = 1;
            }
            if (chip->getAllCommands().at(j) == "exit")
                flag = 1;
        }
        if (find == 0 && chip->getAllCommands().at(j)[0] != ';')
            this->setFileError(j + 1);
        find = 0;
        comment = false;
    }
    if (flag == 0)
        std::cout << "FILE ERROR. NO EXIT COMMAND" << std::endl;
}

void Input::setKeywords()
{
    this->keywords.push_back("comments");
    this->keywords.push_back("push");
    this->keywords.push_back("pop");
    this->keywords.push_back("clear");
    this->keywords.push_back("dup");
    this->keywords.push_back("swap");
    this->keywords.push_back("dump");
    this->keywords.push_back("assert");
    this->keywords.push_back("add");
    this->keywords.push_back("sub");
    this->keywords.push_back("mul");
    this->keywords.push_back("div");
    this->keywords.push_back("mod");
    this->keywords.push_back("load");
    this->keywords.push_back("store");
    this->keywords.push_back("print");
    this->keywords.push_back("exit");
}

std::vector<std::string> Input::getKeywords()
{
    return this->keywords;
}

void Input::read(char **av, Chipset *chip)
{
    std::ifstream file;
    std::string command;

    if (av[1]) {
        file.open(av[1]);
        if (file.is_open())
            while (getline(file, command))
                chip->setCommand(command);
        this->checkFile(chip);
    }
    else
        this->read(chip);
    file.close();
}

void Input::read(Chipset *chip)
{
    std::cout << "We're in the read with no file input." << std::endl;
}