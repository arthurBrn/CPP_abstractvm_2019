/**
 * 
 * 
 * */

#include "SyntaxException.hh"

class SyntaxException : SyntaxException
{
    const char *what() const throw()
    {
        return ("Syntax error.");
    }
};