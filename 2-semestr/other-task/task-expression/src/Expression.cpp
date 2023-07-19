#include "Expression.h"

Const::Const(double constanta) : constanta_(constanta)
{
}

void Const::print() const
{
    std::cout << constanta_;
}

double Const::eval(double) const
{
    return constanta_;
}

Expr *Const::der() const
{
    return new Const(0);
}

Expr *Const::clone() const
{
    return new Const(constanta_);
}

void Var::print() const
{
    std::cout << "x";
}

double Var::eval(double x) const
{
    return x;
}

Expr *Var::der() const
{
    return new Const(1);
}

Expr *Var::clone() const
{
    return new Var;
}

Sum::Sum(Expr *left, Expr *right) : left_(left), right_(right)
{
}

Sum::~Sum()
{
    delete left_;
    delete right_;
}

void Sum::print() const
{
    std::cout << "(";
    left_->print();
    std::cout << "+";
    right_->print();
    std::cout << ")";
}

double Sum::eval(double x) const
{
    return left_->eval(x) + right_->eval(x);
}

Expr *Sum::der() const
{
    return new Sum(left_->der(), right_->der());
}

Expr *Sum::clone() const
{
    return new Sum(left_->clone(), right_->clone());
}


Multiplication::Multiplication(Expr *left, Expr *right) : left_(left), right_(right)
{
}

Multiplication::~Multiplication()
{
    delete left_;
    delete right_;
}

void Multiplication::print() const
{
    std::cout << "(";
    left_->print();
    std::cout << "*";
    right_->print();
    std::cout << ")";
}

double Multiplication::eval(double x) const
{
    return left_->eval(x) * right_->eval(x);
}

Expr *Multiplication::der() const
{
    return new Sum(new Multiplication(left_->der(), right_->clone()),
                   new Multiplication(right_->der(), left_->clone()));
}

Expr *Multiplication::clone() const
{
    return new Multiplication(left_->clone(), right_->clone());
}


Sin::Sin(Expr *expr) : expr_(expr)
{
}

Sin::~Sin()
{
    delete expr_;
}

void Sin::print() const
{
    std::cout << "(";
    std::cout << "sin(";
    expr_->print();
    std::cout << "))";
}

double Sin::eval(double x) const
{
    return std::sin(expr_->eval(x));
}

Expr *Sin::der() const
{
    return new Multiplication(new Cos(expr_), expr_->clone()->der());
}

Expr *Sin::clone() const
{
    return new Sin(expr_);
}


Cos::Cos(Expr *expr) : expr_(expr)
{
}

Cos::~Cos()
{
    delete expr_;
}

void Cos::print() const
{
    std::cout << "(";
    std::cout << "cos(";
    expr_->print();
    std::cout << "))";
}

double Cos::eval(double x) const
{
    return std::cos(expr_->eval(x));
}

Expr *Cos::der() const
{
    return new Multiplication(new Multiplication(new Const(-1), new Sin(expr_)), expr_->clone()->der());
}

Expr *Cos::clone() const
{
    return new Cos(expr_);
}