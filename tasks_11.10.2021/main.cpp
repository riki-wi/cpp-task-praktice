#include <iostream>
#include <cmath>

// sum and product of digits of a number
void sumAndProduct()
{
    int n = 0;
    int sum = 0;
    int product = 1;

    std::cin >> n;
    for (int i = abs(n) ; i % 10 >= 1; i /= 10)
    {
        sum += i % 10;
        product *= i % 10;
    }
    std::cout << sum << std::endl;
    std::cout << product << std::endl;
}

// sum of sinuses sin(x) + sin(sin(x)) + ... + sin(sin...(sin(sin(x)))
// input n then x
void sumOfSin()
{
    int n = 0;
    double x = 0;
    std::cin >> n;
    std::cin >> x;
    double sumSin = 0;
    double helper = x;
    for (int i = 1; i <= n; i++)
    {
        helper = sin(helper);
        sumSin += helper;
    }
    std::cout << sumSin;
}





int main()
{
    //sumAndProduct();
    sumOfSin();
    return 0;
}
