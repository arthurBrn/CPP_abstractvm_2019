/*
** EPITECH PROJECT, 2020
** InputException.cpp
** File description:
** ...
*/

#include "abstractvm.hh"

class SyntaxException : InputException
{
    const char *what() const throw()
    {
        return ("Syntax error.");
    }
};