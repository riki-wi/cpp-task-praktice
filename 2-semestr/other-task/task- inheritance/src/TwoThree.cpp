#include "TwoThree.h"

Two::Two(double a, double b)
{
    if(a > b)
    {
        a_ = a;
        b_ = b;
    } else
    {
        b_ = a;
        a_ = b;
    }
}

double Two::study(double x)
{
    if(x > a_)
    {
        double temp = b_;
        b_ = a_;
        a_ = x;
        return temp;
    }
    if(x < a_ && x > b_)
    {
        double temp = b_;
        b_ = x;
        return temp;
    } else
    {
        return x;
    }
}

void Two::print() const
{
    std::cout << "a = " << a_ << " b = " << b_ << std::endl;
}

Three::Three(double a, double b, double c) : Two(a, b)
{
    c_ = Two::study(c);
}

double Three::study(double x)
{
    double temp = c_;
    c_ = Two::study(x);

    if(temp < c_)
    {
        return temp;
    } else
    {
        c_ = temp;
        return Two::study(x);
    }
}

void Three::print() const
{
    std::cout << "a = " << Two::a_ << " b = " << Two::b_ << " c = " << c_ <<std::endl;
}
