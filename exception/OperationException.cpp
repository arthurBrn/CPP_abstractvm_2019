/**
 * 
 * 
 * */

#include "abstractvm.hh"

class SyntaxException : OperationException
{
    const char *what() const throw()
    {
        return ("Operation error.");
    }
};