
#ifndef _INPUT_EXCEPTION_
#define _INPUT_EXCEPTION_

#include "abstractvm.hh"

class InputException : std::exception 
{
    public:
        const char* what() const throw();
};

#endif