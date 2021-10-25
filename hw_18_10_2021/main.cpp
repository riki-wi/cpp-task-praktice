#include <iostream>
#include <string>
#include <map>
#include <math.h>

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



int main() {

    weekDay();
    return 0;
}
