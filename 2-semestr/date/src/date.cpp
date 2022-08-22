#include "date.h"
#include "simple-str.h"

Date::Date(const char *date)
{
    char **splitDate;
    int numDivision = split_string(date, '.', &splitDate);

    if(numDivision != 3)
    {
        throw DateError();
    }

    try
    {
        day_ = (int) my_atoi(remove_zero_begin(splitDate[0]));
        month_ = (int) my_atoi(remove_zero_begin(splitDate[1]));
        year_ = (int) my_atoi(remove_zero_begin(splitDate[2]));
    } catch(ArgumentException &e)
    {
        throw DateError();
    }

    if(year_ <= 0)
    {
        throw YearError();
    }

    leap_ = checkLeap(year_);

    if(month_ <= 0 || 12 < month_)
    {
        throw MonthError();
    }

    if(day_ <= 0 || (leap_ && (month_ == 2 && day_ > 29)) || (!leap_ && (month_ == 2 && day_ > 28)) ||
       ((month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12) &&
        day_ > 31) ||
       ((month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) && day_ > 30))
    {
        throw DayError();
    }

    for(int i = 0; i < numDivision; i++)
    {
        delete[] splitDate[i];
    }
    delete[] splitDate;
}

Date::Date() : day_(0), month_(0), year_(0), leap_(false)
{
}

int Date::getDay() const
{
    return day_;
}

int Date::getMonth() const
{
    return month_;
}

int Date::getYear() const
{
    return year_;
}

bool Date::isLeap() const
{
    return leap_;
}

bool Date::checkLeap(int y)
{
    if(!(y % 400))
    {
        return true;
    }
    if(!(y % 4))
    {
        if(!(y % 100))
        {
            return false;
        } else
        {
            return true;
        }
    }
    return false;
}
