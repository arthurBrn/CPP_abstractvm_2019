
#ifndef _OPERATION_EXCEPTION_
#define _OPERATION_EXCEPTION_

#include "abstractvm.hh"

class OperationException : std::exception 
{
    public:
        const char* what() const throw();
};

#endif