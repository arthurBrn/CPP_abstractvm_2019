
#ifndef _INPUT_EXCEPTION_
#define _INPUT_EXCEPTION_

#include "abstractvm.hh"

class AbstractVmException : std::exception 
{
    public:
        std::string getErrorMessage(std::string errorMessage) throw();
};

#endif