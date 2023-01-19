#include<iostream>

class Integer;

class Real;

class Complex;

class Number
{
public:
    virtual ~Number() = default;

    virtual Integer operator+(const Integer &left ) = 0;

    virtual Real operator+=(const Real &) = 0;

    virtual Complex operator+=(const Complex &) = 0;

};

class Integer : public Number
{
public:

    int n{};

    ~Integer() override = default;

    void operator+=(const Number &) override;

    void operator+=(const Integer &) override;

    void operator+=(const Real &) override;

    void operator+=(const Complex &) override;
};

class Real : public Number
{
public:

    double d{};

    ~Real() override = default;

    void operator+=(const Number &) override;

    void operator+=(const Integer &) override;

    void operator+=(const Real &) override;

    void operator+=(const Complex &) override;
};

class Complex : public Number
{
public:

    double r{};

    double i{};

    ~Complex() override = default;

    void operator+=(const Number &) override;

    void operator+=(const Integer &) override;

    void operator+=(const Real &) override;

    void operator+=(const Complex &) override;
};

void Integer::operator+=(const Number & right)
{
    *this += right;
}

void Integer::operator+=(const Integer & right)
{
   n += right.n;
}

void Integer::operator+=(const Real & right)
{
    n += right.d;
}

void Integer::operator+=(const Complex & right)
{
    n += static_cast<int>(right.r);
}

void Real::operator+=(const Number & right)
{
    *this += right;
}

void Real::operator+=(const Integer & right)
{
    d += right.n;
}

void Real::operator+=(const Real & rigth)
{
    d += rigth.d;
}

void Real::operator+=(const Complex & right)
{
    d += right.r;
}

void Complex::operator+=(const Number & right)
{
    *this += right;
}

void Complex::operator+=(const Integer & rigth)
{
    r += rigth.n;
}

void Complex::operator+=(const Real & right)
{
    r += right.d;
}

void Complex::operator+=(const Complex & right)
{
    r += right.r;
    i += right.r;
}

int main()
{
    Integer x;
    x.n = 1;

    Real y;
    y.d = 3.23;

    Complex z;
    z.r = 4;
    z.i = 5.34;

    Number &p_x = x;
    Number &p_y = y;
    Number &res = x + y;

    p_y += p_x;
    p_x += p_y;
    std::cout << x.n << std::endl;
    std::cout << x.n << std::endl;
}