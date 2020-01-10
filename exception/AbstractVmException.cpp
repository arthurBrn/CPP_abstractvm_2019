/*
** EPITECH PROJECT, 2020
** OperationException.cpp
** File description:
** ...
*/

#include "abstractvm.hh"

class SyntaxException : AbstractVmException
{
    std::string getErrorMessage(std::string errorMessage) throw()
    {
        return (errorMessage);
    }
};