#include<iostream>

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
    Number& res = *this + right;
    return res;
}

Number &Integer::operator+(Real &right)
{
    n += static_cast<int>(right.d);
    return *this;
}

Number &Integer::operator+(Complex &right)
{
    n += static_cast<int>(right.r);
    return *this;
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
    d += right.n;
    return *this;
}

Number &Real::operator+(Real &right)
{
    d += right.d;
    return *this;
}

Number &Real::operator+(Complex &right)
{
    d += right.r;
    return *this;
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
    r += right.n;
    return *this;
}

Number &Complex::operator+(Real &right)
{
    r += right.d;
    return *this;
}

Number &Complex::operator+(Complex &right)
{
    r += right.r;
    i += right.i;
    return *this;
}

int main()
{
}