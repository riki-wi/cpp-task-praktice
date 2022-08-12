#ifndef TEST_ERRORS_H
#define TEST_ERRORS_H

class DateError
{
public:
    virtual const char *what() const
    {
        return "Wrong date format";
    }
};

class DayError : public DateError
{
public:
    const char *what() const override
    {
        return "Day value is invalid";
    }
};

class MonthError : public DateError
{
public:
    const char *what() const override
    {
        return "Month value is invalid";
    }
};

class YearError : public DateError
{
public:
    const char *what() const override
    {
        return "Year value is invalid";
    }
};

#endif
