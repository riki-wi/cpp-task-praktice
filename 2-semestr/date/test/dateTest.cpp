#include "gtest/gtest.h"
#include "../src/date.h"

TEST(DateExeption, TestOne)
{
    ASSERT_THROW(Date(""), DateError);
    ASSERT_THROW(Date("hello"), DateError);
    ASSERT_THROW(Date("01"), DateError);
    ASSERT_THROW(Date("01.02"), DateError);
    ASSERT_THROW(Date("01.hello.02"), DateError);
    ASSERT_THROW(Date("hello.01.2"), DateError);
    ASSERT_THROW(Date("01.02.hello"), DateError);
    ASSERT_THROW(Date("01.02.02---"), DateError);
}

TEST(DayError, TestOne)
{
    ASSERT_THROW(Date("-01.02.2022"), DayError);
    ASSERT_THROW(Date("30.02.2022"), DayError);
    ASSERT_THROW(Date("31.09.2022"), DayError);
}

TEST(MonthError, TestOne)
{
    ASSERT_THROW(Date("01.-02.2022"), MonthError);
    ASSERT_THROW(Date("01.22.2022"), MonthError);
}

TEST(YearError, TestOne)
{
    ASSERT_THROW(Date("01.02.-2022"), YearError);
}

TEST(DateLeap, TestOne)
{
    ASSERT_THROW(Date("30.02.2000"), DayError);

    Date dateLeap("01.02.2000");
    ASSERT_TRUE(dateLeap.isLeap());

    Date dateNotLeap("01.02.2001");
    ASSERT_FALSE(dateNotLeap.isLeap());
}

TEST(Date, TestOne)
{
    Date date("11.08.2022");
    ASSERT_EQ(date.getDay(), 11);
    ASSERT_EQ(date.getMonth(), 8);
    ASSERT_EQ(date.getYear(), 2022);
    ASSERT_FALSE(date.isLeap());
}

TEST(Date, TestTwo)
{
    Date date("01.08.2022");
    ASSERT_EQ(date.getDay(), 1);
    ASSERT_EQ(date.getMonth(), 8);
    ASSERT_EQ(date.getYear(), 2022);
    ASSERT_FALSE(date.isLeap());
}

TEST(Date, TestThree)
{
    Date date("1.8.2022");
    ASSERT_EQ(date.getDay(), 1);
    ASSERT_EQ(date.getMonth(), 8);
    ASSERT_EQ(date.getYear(), 2022);
    ASSERT_FALSE(date.isLeap());
}