/*
** EPITECH PROJECT, 2020
** Input.cpp
** File description:
** ...
*/

#include "Input.hh"
#include "AbstractVmException.hh"
#include "abstractvm.hh"

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

void Input::getFileError(Chipset *chip)
{
    AbstractVmException exception;

    std::string error;
    std::vector<std::string> commands = chip->getAllCommands();

    if (this->fileError > 0) {
        exception.setErrorMessage("Syntax error line " + std::to_string(fileError + 1));
        throw exception;
    }
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
            throw exception;
        }
    }
    if (commands.at(max).compare("exit") != 0) {
        exception.setErrorMessage("The file must finish by \"exit\"");
        throw exception;
    }
}

void Input::read(std::string path, Chipset *chip)
{
    std::string file_name = path;
    std::ifstream file;
    std::string command;
    AbstractVmException exception;

    if (file_name.compare((file_name.size() - 4), 4, ".avm") != 0) {
        exception.setErrorMessage("The file must finish by .avm extension");
        throw exception;
    }
    file.open(path);
    if (file.is_open())
        while (getline(file, command))
        {
            if (!command.empty())
                chip->setCommand(command);
        }
    this->checkFile(chip);
    file.close();
}

int Input::syntax(std::string str)
{
    std::regex reg("(^pop|^dump|^clear|^dup|^swap|^add|^sub|^mul|^div|^mod|^print|^exit|^;.*|^)|((^push|^assert|^load|^store) (int(8|16|32)\\([-]?[0-9]+\\)|(float|double|bigdecimal)\\([-]?[0-9]+[.]?[0-9]*\\)))");

    int res;
    if (std::regex_match(str, reg))
        return (1);
    return (0);
}

void Input::read(Chipset *chip)
{
    AbstractVmException exception;
    std::string one_line;
    int res;

    while (std::cin)
    {
        getline(std::cin, one_line);
        res = syntax(one_line);
        if (res == 1) {
            if (!one_line.empty())
                chip->setCommand(one_line);
            } else {
                exception.setErrorMessage("empty line");
                throw exception;
            }
        if (one_line.compare("exit") == 0)
        {
            getline(std::cin, one_line);
            if (one_line.compare(";;") == 0)
                break;
            else {
                exception.setErrorMessage("Syntax error");
                throw exception;
            }            
        }
    }
}

void Input::select_input(int ac, char **av, Chipset *chip)
{
    AbstractVmException exception;

    if (ac == 2)
        this->read(av[1], chip);
    else if (ac == 1)
        this->read(chip);
    else {
        exception.setErrorMessage("Wrong arguments number");
        throw exception;
    }
}
