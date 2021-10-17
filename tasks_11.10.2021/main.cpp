#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>

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

// goose and rabbit
// enter paws = number of paws
void gooseAndRabbit() {
    int paws = 0;
    std::cin >> paws;
    for (int i = 0; i <= paws; i += 4)
    {
        std::cout << "rabbits: " << i / 4 << " goose: " << (int)paws / 2 - i / 2 << std::endl;
    }
}


// sin Taylor
// enter x then enter n = accuracy
void sinTaylor(){
    double x = 0;
    int n = 0;
    int sign = -1;
    std::cin >> x;
    std::cin >> n;
    double sinTaylor = x;
    x *= x;
    for(int i = 2; i <= 2 * n; i += 2)
    {
        sinTaylor += sign * sinTaylor * x / i / (i + 1);
        sign *= -1;
    }
    std::cout << sinTaylor;
}


// pi decomposition of Leibniz
void piDecomposition()
{
    double piDec = 1.0;
    int sign = -1;
    for (int i = 5; i < 100000; i += 1) // accuracy (5;100000)
    {
        for (int j = 3; j < 2 * i; j += 2)
        {
            piDec += sign * (1.0 / j);
            sign *= -1;
        }
        piDec *= 4;
        std::cout << std::setprecision(16) << piDec << std::endl;
        sign = -1;
        piDec = 1.0;
    }
}

int main()
{
   //sumAndProduct();
   //sumOfSin();
   //pointsInTheCircle();
   //gooseAndRabbit();
   sinTaylor();
   //piDecomposition();
   return 0;
}
