#include <iostream>
#include <string>


// helper function translation
std::string checkNumberForTranslation(int x)
{
    switch (x)
    {
        case 10: return "A";
        case 11: return "B";
        case 12: return "C";
        case 13: return "D";
        case 14: return "E";
        case 15: return "F";
        default: return std::to_string(x);
    }
}

// translation into the 16 number system
void translation()
{
    unsigned long long x = 0;
    std::string res;
    std::cout << "Введите целое положительное число: " << std::endl;
    std::cin >> x;
    while (x >= 1)
    {
        res += checkNumberForTranslation((int)x % 16);
        x = x >> 4;
    }
    std::reverse(res.begin(), res.end());
    std::cout << res << std::endl;
}

// leap year
bool leapYear(int year)
{
    if (!(year % 400)) return true;
    if (!(year % 4))
    {
        if(!(year % 100)) return false;
        else return true;
    }
    else return false;
}

// difference in days
long long differenceInDays(int dayFirst, int monthFirst, int yearFirst, int daySecond, int monthSecond, int yearSecond)
{
    long long res = 0;

    for (int i = yearFirst + 1; i < yearSecond; i++)
    {
        if (leapYear(i)) res += 366;
        else res += 365;
    }

    if (leapYear(yearFirst) && monthFirst <= 2) res += 1;
    if (leapYear(yearSecond) && monthSecond > 2) res += 1;

    for (int i = monthFirst; i <= 12; i ++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) res += 31;
        else if (i == 2) res += 28;
        else res += 30;
    }
    res -= dayFirst;

    for (int i = 1; i < monthSecond; i ++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) res += 31;
        else if (i == 2) res += 28;
        else res += 30;
    }
    res += daySecond;
    if (yearFirst == yearSecond)
    {
        if (leapYear(yearSecond)) return abs(365 - res) - 1;
        return abs(365 - res);
    }
    return res;
}

//my age in days
void myAgeInDay()
{
    std::cout << differenceInDays(14, 4, 2000, 25, 10, 2021) << std::endl;
}

//the difference in hours minutes and seconds
void differenceInHoursMinutesSeconds(int dayFirst, int monthFirst, int yearFirst, int daySecond, int monthSecond, int yearSecond)
{
    long long day = differenceInDays(dayFirst, monthFirst, yearFirst, daySecond, monthSecond, yearSecond);
    std::cout << "hours: " << day * 24 << std::endl;
    std::cout << "minutes: " << day * 24 * 60 << std::endl;
    std::cout << "seconds: " << day * 24 * 60 * 60 << std::endl;
}

int main()
{
   // differenceInHoursMinutesSeconds(14, 4, 2000, 25, 10, 2021);
   // myAgeInDay();
   //translation();
    return 0;
}
