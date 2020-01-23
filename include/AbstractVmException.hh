/*
** EPITECH PROJECT, 2020
** AbstractVmException.hh
** File description:
** ...
*/

#ifndef _ABSTRACT_VM_EXCEPTION_HH_
#define _ABSTRACT_VM_EXCEPTION_HH_

#include "abstractvm.hh"

class AbstractVmException : public std::exception 
{   
    public:
        AbstractVmException(std::string);
        ~AbstractVmException();
        std::string getErrorMessage();
        void setErrorMessage(std::string errorMessage);
    private:
        std::string errorMessage;
};

#endif