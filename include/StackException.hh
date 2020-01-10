
#ifndef _STACK_EXCEPTION_
#define _STACK_EXCEPTION_

#include "abstractvm.hh"

class StackException : std::exception 
{
    public:
        const char* what() const throw();
};

#endif