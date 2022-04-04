#include <iostream>
#include <string>
#include <map>
#include <cmath>

//day of the week by date
void weekDay()
{
    int day;
    int month;
    int year;

    std::cout << "Enter day \n";
    std::cin >> day;

    std::cout << "Enter month \n";
    std::cin >> month;

    std::cout << "Enter year \n";
    std::cin >> year;

    int a = (int)floor((14 - month) / 12);
    year = year - a;
    month = month + 12 * a - 2;
    int weekDay = (int)(day + floor((31 * month) / 12) + year + floor(year / 4)
                    - floor(year / 100) + floor(year / 400)) % 7;

    std::map<int, std::string> res = {{0, "Sunday"}, {1, "Monday"}, {2, "Tuesday"}, {3, "Wednesday"},
                                    {4, "Thursday"}, {5, "Friday"}, {6, "Saturday"}};
    std::cout << res[weekDay] << "\n";
}

//translation into the Roman numeral system
void trIntoRoman(long long x)
{
    std::string res;
    std::map<int, std::string> roman = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},{10, "X"},
                                        {40, "LX"}, {50, "L"}, {90, "XC"}, {100, "X"},
                                        {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
    for (auto it = roman.rbegin(); it != roman.rend(); it++)
    {
        while(x >= it->first)
        {
            res += it->second;
            x -= it->first;
        }
        if (x == 0) break;
    }
    std::cout << res << std::endl;
}


int main() {

    //weekDay();
    for (int i = 1; i < 1000; i++)
    {
        std::cout << i << " = ";
        trIntoRoman(i);
    }
    return 0;
}


