/*
** EPITECH PROJECT, 2020
** SynthaxException.cpp
** File description:
** ...
*/

#include "abstractvm.hh"

class SyntaxException : SyntaxException
{
    const char *what() const throw()
    {
        return ("Syntax error.");
    }
};