#ifndef SIMPLE_ARR_ARRAYEXCEPTION_H
#define SIMPLE_ARR_ARRAYEXCEPTION_H

class IndexException
{
public:
    const char * what()
    {
        return "Bad Index!";
    }
};

class SizeException
{
public:
    const char * what() 
    {
        return "Bad Size!";
    }
};
#endif
