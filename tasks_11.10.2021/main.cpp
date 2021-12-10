#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>
#include <random>

// The comparison is equal
bool comparisonIsEqual(double x, double y)
{
    return fabs(x - y) < DBL_EPSILON * fmax(fabs(x), fabs(y));
}

// comparison two double
bool comparison(double x, double y)
{
    return fabs(x) - fabs(y) < DBL_EPSILON * fmax(fabs(x), fabs(y));
}

//belonging to the circle
bool belongOfCircle(double x, double y, double r)
{
    if (comparison(x * x + y * y, r * r)) return true;
    return false;
}

//distance to the point
void distanceToThePoint()
{
    double x1 = 0.;
    double x2 = 0.;
    double x3 = 0.;
    double y1 = 0.;
    double y2 = 0.;
    double y3 = 0.;
    std::cout << "enter the coordinates of the three points x1, y1 ... " << std::endl;
    std::cin >> x1;
    std::cin >> y1;
    std::cin >> x2;
    std::cin >> y2;
    std::cin >> x3;
    std::cin >> y3;
    double distanceOne = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    double distanceTwo = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    comparisonIsEqual(distanceOne + distanceTwo, 10.0);
}

// sum and product of digits of a number
void sumAndProduct()
{
    int n = 0;
    int sum = 0;
    int product = 1;
    std::cout << "enter a number " << std::endl;
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
    double x = 0.;
    std::cout << "enter the precision then the sine argument " << std::endl;
    std::cin >> n;
    std::cin >> x;
    double sumSin = 0.;
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
    double r = 0.;
    std::cout << "enter radius " << std::endl;
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
    std::cout << "enter numbers of paws " << std::endl;
    std::cin >> paws;
    for (int i = 0; i <= paws; i += 4)
    {
        std::cout << "rabbits: " << i / 4 << " goose: " << (int)paws / 2 - i / 2 << std::endl;
    }
}

// sin Taylor
// enter x then enter n = accuracy
void sinTaylor(){
    double x = 0.;
    int n = 0;
    int sign = -1;
    std::cout << "enter the precision then the sine argument " << std::endl;
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
    double piDec = 1.;
    int sign = -1;
    for (int i = 5; i < 100000; i += 1) // accuracy (5;100000)
    {
        for (int j = 3; j < 2 * i; j += 2)
        {
            piDec += sign * (1. / j);
            sign *= -1;
        }
        piDec *= 4;
        std::cout << std::setprecision(16) << piDec << std::endl;
        sign = -1;
        piDec = 1.0;
    }
}

// the ratio of the area of a square and a circle, the calculation of pi
// enter r = radius
void ratioArea()
{
    double r = 0.;
    std::cout << "enter radius " << std::endl;
    std::cin >> r;
    double circle = 0;
    int countOfPoints = 1000000;
    for (int i = 0; i < countOfPoints; i++)
    {
        double randomXPoints = ((double)random() / RAND_MAX) * r;
        double randomYPoints = ((double)random() / RAND_MAX) * r;
        if (belongOfCircle(randomXPoints, randomYPoints, r)) circle++;
    }
    double ratioArea = circle / countOfPoints;
    std::cout << ratioArea << std::endl;
    double pi = 4 * ratioArea;
    std::cout << pi;

}

int main()
{
   //sumAndProduct();
   //sumOfSin();
   //pointsInTheCircle();
   //gooseAndRabbit();
   //sinTaylor();
   //piDecomposition();
   //distanceToThePoint();
   //ratioArea();
   return 0;
}
