#include <cmath>
#include <iostream>

double g(double x)
{
    return sin(x) * sin(x);
}

double integral(double a, double b, double (*f)(double))
{
    int n = 100;
    double sum = 0;
    for (int i = 1; i <= n; i++)
        sum += f(a + (i - 0.5) * (b - a) / n);

    return sum * (b - a) / n;
}

double integralLambda(double a, double b )
{
    int n = 100;
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += [](double x)
        { return sin(x) * sin(x); }(a + (i - 0.5) * (b - a) / n);
    }
    return sum * (b - a) / n;
}

int main()
{
    std::cout << integral(0, 1, g) << std::endl;
    std::cout << integralLambda(0, 1) << std::endl;
    return 0;
}