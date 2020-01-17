/*
** EPITECH PROJECT, 2020
** AbstractVmException.hh
** File description:
** ...
*/

#ifndef _ABSTRACT_VM_EXCEPTION_HH_
#define _ABSTRACT_VM_EXCEPTION_HH_

#include "abstractvm.hh"

class AbstractVmException : std::exception 
{
    public:
        std::string getErrorMessage(std::string errorMessage) throw();
};

#endif