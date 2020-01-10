/*
** EPITECH PROJECT, 2020
** StackException.cpp
** File description:
** ...
*/

#include "abstractvm.hh"

class SyntaxException : StackException
{
    const char *what() const throw()
    {
        return ("Stack error.");
    }
};