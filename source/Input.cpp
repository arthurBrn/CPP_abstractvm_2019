/*
** EPITECH PROJECT, 2020
** Input.cpp
** File description:
** ...
*/

#include "abstractvm.hh"
#include "Input.hh"
#include "Chipset.hh"
#include "AbstractVmException.hh"
#include <fstream>
#include <regex>

Input::Input()
{
    this->fileError = -1;
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

int Input::getFileError(Chipset *chip)
{
    std::string error;
    std::vector<std::string> commands = chip->getAllCommands();

    if (this->fileError > 0)
    {
        error = ", unknow : " + commands.at(fileError - 1);
        std::cout << "Error line " << fileError << error << std::endl;
    }
    return this->fileError;
}

void Input::setFileError(int newValue)
{
    this->fileError = newValue;
}

void Input::checkFile(Chipset *chip)
{
    AbstractVmException exception;
    std::vector<std::string> commands;
    commands = chip->getAllCommands();
    bool res;
    int max = commands.size() - 1;
    auto iterator = 0;

    for (int i = 0; i < commands.size(); i++)
    {
        res = syntax(commands.at(i));
        if (res == 0)
        {
            this->fileError = i + 1;
            exception.setErrorMessage("ERROR: syntax error in the file.");
            throw(exception);
        }
    }
    
    if (commands.at(max).compare("exit") != 0)
        std::cout << "finish by exit plz" << std::endl;
}

void Input::read(char **av, Chipset *chip)
{
    std::ifstream file;
    std::string command;

    file.open(av[1]);
    if (file.is_open())
        while (getline(file, command)) {
            if (!command.empty())
                chip->setCommand(command);
        }
    this->checkFile(chip);
    file.close();
}

int Input::syntax(std::string str)
{
    std::regex reg("(^pop|^dump|^clear|^dup|^swap|^add|^sub|^mul|^div|^mod|^print|^exit|^;.*|^)|((^push|^assert|^laod|^store) (int(8|16|32)\\([-]?[0-9]+\\)|(float|double|bigdecimal)\\([-]?[0-9]+[.]?[0-9]*\\)))");
    
    int res;
    if (std::regex_match(str, reg))
        return (1);
    return (0);
}

void Input::read(Chipset *chip)
{
    std::string one_line;
    int res;

    while (std::cin)
    {
        getline(std::cin, one_line);
        res = syntax(one_line);

        if (res == 1) {
            if (!one_line.empty())
                chip->setCommand(one_line);
        }
        else
            std::cout << "Syntax Error" << std::endl;
        
        if (one_line.compare("exit") == 0)
            break;
    }
}

void Input::select_input(int ac, char **av, Chipset *chip)
{
    if (ac == 2)
        this->read(av, chip);
    else if (ac == 1)
        this->read(chip);
    else
        std::cout << "wrong argument number" << std::endl;
}