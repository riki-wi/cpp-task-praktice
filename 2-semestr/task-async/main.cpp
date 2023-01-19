#include <iostream>
#include <future>
#include <cmath>

double pi(int n)
{
    double pi;
    for (int i = 0; i < n; i++)
    {
        pi = pi + std::sqrt(12) * std::pow(-1, i) / ((2.0 * i + 1) * (std::pow(3, i)));
    }
    return pi;
}

//------------------------------------------------------------------------------------------------------


int main()
{
    std::future<double> f1 = std::async(pi, 100);
    std::cout << std::fixed;
    std::cout.precision(16);
    std::cout << "pi = " << f1.get() << std::endl;

    //---------------------------------------------



    return 0;
}