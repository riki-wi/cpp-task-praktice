#ifndef SIMPLE_ARR_ARRAYEXCEPTION_H
#define SIMPLE_ARR_ARRAYEXCEPTION_H

#include "iostream"

class IndexException: public std::exception
{

public:
    const char * what() const noexcept override
    {
        return "Bad Index!";
    }

};

class SizeException: public std::exception
{

public:
    const char * what() const noexcept override
    {
        return "Bad Size!";
    }
};

#endif
