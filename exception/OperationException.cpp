/*
** EPITECH PROJECT, 2020
** OperationException.cpp
** File description:
** ...
*/

#include "abstractvm.hh"

class SyntaxException : OperationException
{
    const char *what() const throw()
    {
        return ("Operation error.");
    }
};