#include <iostream>
#include <cmath>
#include <cfloat>

// comparison two double
bool comparison(double x, double y)
{
    return floor(x) - floor(y) < DBL_EPSILON * fmax(fabs(x), fabs(y));
}

//belonging to the circle
bool belongOfCircle(double x, double y, double r)
{
    if (comparison(x * x + y * y, r * r)) return true;
    return false;
}

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


//the number of points with integer coordinates in the circle
//enter r = radius
void pointsInTheCircle()
{
    int count = 0;
    double r = 0;
    std::cin >> r;
    for (int i = 0; i <= (int)r; i++)
    {
        for (int j = 0; j <=(int)r; j++)
        {
            if (belongOfCircle(i, j, r)) {
                std::cout << i << " "  << j << std::endl;
                count++;
            }
        }
    }
    std::cout << 4 *(count - floor(r)) - 3;
}

int main()
{
   // sumAndProduct();
   // sumOfSin();
   // geeseAndRabbits();
   pointsInTheCircle();
   return 0;
}
