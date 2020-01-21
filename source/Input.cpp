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
#include <regex>

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
    std::string error;

    if (this->fileError > 0) {
        error = ", unknow : " + this->commands.at(fileError - 1);
        std::cout << "Error line " <<  fileError << error << std::endl;
    }
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
    std::vector<std::string>commands;
    commands = chip->getAllCommands();
    int res;
    std::regex reg("(^pop|^dump|^clear|^dup|^swap|^add|^sub|^mul|^div|^mod|^print|^exit|^;.*)|((^push|^assert|^laod|^store) (int(8|16|32)\\([-]?[0-9]+\\)|(float|double|bigdecimal)\\([-]?[0-9]+[.]?[0-9]*\\)))");

    for (int i = 0; i < commands.size(); i++) {
        res = std::regex_match(commands.at(i), reg);
        if (!res)
            this->fileError = i + 1;
    }
    this->commands = commands;
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