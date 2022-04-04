#include "bmpWork.h"

std::string checkNumberForTranslation(int x)
{
    switch (abs(x))
    {
        case 0: return "0";
        case 10: return "A";
        case 11: return "B";
        case 12: return "C";
        case 13: return "D";
        case 14: return "E";
        case 15: return "F";
        default: return std::to_string(abs(x));
    }
}

std::string translation(unsigned  long long x)
{
    std::string res;
    if(!x)
    {
        return "00";
    }
    while (x >= 1)
    {
        res += checkNumberForTranslation((int)x % 16);
        x = x >> 4;
    }
    std::reverse(res.begin(), res.end());
    return res;
}
