
#ifndef _SYNTAX_EXCEPTION_
#define _SYNTAX_EXCEPTION_

#include "abstractvm.hh"

class SyntaxException : std::exception 
{
    public:
        const char* what() const throw();
};

#endif