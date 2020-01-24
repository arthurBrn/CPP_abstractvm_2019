/*
** EPITECH PROJECT, 2020
** AbstractVmException.cpp
** File description:
** ...
*/

#include "AbstractVmException.hh"

AbstractVmException::AbstractVmException(std::string value)
{
    this->errorMessage = value;
}

AbstractVmException::~AbstractVmException()
{
    
}

std::string AbstractVmException::getErrorMessage(){
    return (errorMessage);
}

void AbstractVmException::setErrorMessage(std::string msg)
{  
    this->errorMessage = msg;
}

