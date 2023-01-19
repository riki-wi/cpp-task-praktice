#include <iostream>

class Two
{
public:
    double a_;
    double b_;

    Two(double a, double b);

    virtual double study(double x);

    virtual void print() const;
};

class Three : public Two
{
public:
    double c_;

    Three(double a, double b, double c);

    double study(double x) override;

    void print() const override;

};
