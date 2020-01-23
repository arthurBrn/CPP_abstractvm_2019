/*
** EPITECH PROJECT, 2020
** read_file.cpp
** File description:
** store commands in a vector
*/

#include "abstractvm.hh"

int check_file_error_name(char **av)
{
    int len = strlen(av[1]);

    if (strcmp(&av[1][len - 4], ".avm") == 0)
        std::cout << "good extension" << std::endl;
    else 
        std::cout << "bad extension, choose another file" << std::endl;
}

int read_file(int ac, char **av)
{
    std::vector<std::string>commands;
    std::ifstream file;
    file.open(av[1]);
    std::string line;
    if (file.is_open()) {
        while (getline(file, line))
        commands.push_back(line);
    } else
        std::cout << "no file match" << std::endl;
    file.close();
    check_file_error_name(av);
    return 0;
}
