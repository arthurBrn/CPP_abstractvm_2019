/*
** EPITECH PROJECT, 2020
** AbstractVmException.cpp
** File description:
** ...
*/

#include "abstractvm.hh"



std::string AbstractVmException::getErrorMessage(){
    return (errorMessage);
}

void AbstractVmException::setErrorMessage(std::string msg)
{  
    this->errorMessage = msg;
}

