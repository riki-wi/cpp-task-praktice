#include <iostream>
#include <cmath>

class Expr
{
public:
    virtual ~Expr() = default;

    virtual void print() const = 0;

    virtual double eval(double) const = 0;

    virtual Expr *der() const = 0;

    virtual Expr *clone() const = 0;
};

//------------------------------------------------------

struct Const : public Expr
{
public:
    double constanta_;

    explicit Const(double constanta);

    ~Const() override = default;

    void print() const override;

    double eval(double) const override;

    Expr *der() const override;

    Expr *clone() const override;
};

//------------------------------------------------------

class Var : public Expr
{
public:
    explicit Var() = default;

    ~Var() override = default;

    void print() const override;

    double eval(double x) const override;

    Expr *der() const override;

    Expr *clone() const override;
};

//------------------------------------------------------

class Sum : public Expr
{
public:
    Expr *left_;
    Expr *right_;

    explicit Sum(Expr *left, Expr *right);

    ~Sum() override;

    void print() const override;

    double eval(double x) const override;

    Expr *der() const override;

    Expr *clone() const override;
};

//------------------------------------------------------

class Multiplication : public Expr
{
public:
    Expr *left_;
    Expr *right_;

    explicit Multiplication(Expr *left, Expr *right);

    ~Multiplication() override;

    void print() const override;

    double eval(double x) const override;

    Expr *der() const override;

    Expr *clone() const override;
};

//------------------------------------------------------

class Sin : public Expr
{
public:
    Expr *expr_;

    explicit Sin(Expr *expr);

    ~Sin() override;

    void print() const override;

    double eval(double x) const override;

    Expr *der() const override;

    Expr *clone() const override;
};

//------------------------------------------------------

class Cos : public Expr
{
public:
    Expr *expr_;

    explicit Cos(Expr *expr);

    ~Cos() override;

    void print() const override;

    double eval(double x) const override;

    Expr *der() const override;

    Expr *clone() const override;
};