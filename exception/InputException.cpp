/**
 * 
 * 
 * */

#include "abstractvm.hh"

class SyntaxException : InputException
{
    const char *what() const throw()
    {
        return ("Syntax error.");
    }
};