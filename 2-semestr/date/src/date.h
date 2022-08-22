#ifndef DATE_DATE_H
#define DATE_DATE_H

#include "errors.h"

class Date
{
private:
    int day_;
    int month_;
    int year_;
    bool leap_;

    bool checkLeap(int y);

public:
    Date();

    explicit Date(const char *date);

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    bool isLeap() const;
};

#endif
