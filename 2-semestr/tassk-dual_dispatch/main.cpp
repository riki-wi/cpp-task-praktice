#include<iostream>


#define SUM(TYPE, VAR, VAR_SUM)        \
TYPE res;                              \
res.VAR = 0;                           \
res.VAR = VAR + right.VAR_SUM;         \
*this = res;                           \
return *this;

#define SUM_COMPLEX(VAR_SUM) \
Complex res;                 \
res.r = 0;                   \
res.i = 0;                   \
res.r = r + right.VAR_SUM;   \
res.i = i;                   \
*this = res;                 \
return *this;

class Integer;

class Real;

class Complex;

class Integer;

class Real;

class Complex;

class Number
{
public:
    virtual ~Number() = default;

    virtual std::ostream &operator<<(std::ostream &os) = 0;

    virtual Number &operator+(Number &) = 0;

    virtual Number &operator+(Integer &) = 0;

    virtual Number &operator+(Real &) = 0;

    virtual Number &operator+(Complex &) = 0;
};

class Integer : public Number
{
public:

    int n{};

    ~Integer() override = default;

    std::ostream &operator<<(std::ostream &os) override;

    Number &operator+(Number &) override;

    Number &operator+(Integer &) override;

    Number &operator+(Real &) override;

    Number &operator+(Complex &) override;
};

class Real : public Number
{
public:

    double d{};

    std::ostream &operator<<(std::ostream &os) override;

    ~Real() override = default;

    Number &operator+(Number &) override;

    Number &operator+(Integer &) override;

    Number &operator+(Real &) override;

    Number &operator+(Complex &) override;
};

class Complex : public Number
{
public:
    double r{};

    double i{};

    ~Complex() override = default;

    std::ostream &operator<<(std::ostream &os) override;

    Number &operator+(Number &) override;

    Number &operator+(Integer &) override;

    Number &operator+(Real &) override;

    Number &operator+(Complex &) override;
};

std::ostream &Integer::operator<<(std::ostream &os)
{
    return os << n;
}

Number &Integer::operator+(Number &right)
{
    return right + *this;
}

Number &Integer::operator+(Integer &right)
{
    SUM(Integer, n, n)
}

Number &Integer::operator+(Real &right)
{
    SUM(Integer, n, d)
}

Number &Integer::operator+(Complex &right)
{
    SUM(Integer, n, r)
}

std::ostream &Real::operator<<(std::ostream &os)
{
    return os << d;
}

Number &Real::operator+(Number &right)
{
    return right + *this;
}

Number &Real::operator+(Integer &right)
{
    SUM(Real, d, n)
}

Number &Real::operator+(Real &right)
{
    SUM(Real, d, d)
}

Number &Real::operator+(Complex &right)
{
    SUM(Real, d, r)
}

std::ostream &Complex::operator<<(std::ostream &os)
{
    return os << r << " + " << i << "i";
}

Number &Complex::operator+(Number &right)
{
    return right + *this;
}

Number &Complex::operator+(Integer &right)
{
    SUM_COMPLEX(n)
}

Number &Complex::operator+(Real &right)
{
    SUM_COMPLEX(d)
}

Number &Complex::operator+(Complex &right)
{
    Complex res;
    res.r = 0;
    res.i = 0;
    res.r = r + right.r;
    res.i = i + right.i;
    *this = res;
    return *this;
}

int main()
{
    Integer x;
    Real y;
    x.n = 4;
    y.d = 5.32;

    Number &p_x = x;
    Number &p_y = y;

    Number &res = p_x + p_y;
    res.operator<<(std::cout);
    std::cout << std::endl;

    Complex z;
    z.r = 5.67;
    z.i = 54.3;

    Number &p_z = z;
    Number &res2 = res + p_z;

    res2.operator<<(std::cout);
    std::cout << std::endl;
}