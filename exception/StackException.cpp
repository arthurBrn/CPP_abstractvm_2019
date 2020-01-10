/**
 * 
 * 
 * */

#include "abstractvm.hh"

class SyntaxException : StackException
{
    const char *what() const throw()
    {
        return ("Stack error.");
    }
};