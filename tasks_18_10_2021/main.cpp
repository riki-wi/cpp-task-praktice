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


int main()
{
   // translation();
    return 0;
}
