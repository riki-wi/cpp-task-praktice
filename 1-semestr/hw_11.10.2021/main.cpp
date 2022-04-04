#include <iostream>

// the Collatz hypothesis
bool hypothesisCollatz(unsigned long long n)
{
    while(n > 1)
    {
        if (n == 4) return true;
        if (n & 1) n = n * 3 + 1;
        else n = n / 2;
    }
    return false;
}

int main()
{
    std::cout << hypothesisCollatz(10) << std::endl;

    for (int i = 5; i < 10000000; i++)
    {
        if (!hypothesisCollatz(i)) std::cout << "ERROR";
    }
    std::cout << "OK";

    return 0;
}
