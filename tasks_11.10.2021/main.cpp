#include <iostream>

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






int main()
{
    sumAndProduct();
    return 0;
}
