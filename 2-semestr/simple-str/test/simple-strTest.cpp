#include "gtest/gtest.h"
#include "../src/simple-str.h"

TEST(lengthTest, TestOne)
{
    ASSERT_EQ(lengthString(""), 0);
}

TEST(lengthTest, TestTwo)
{
    ASSERT_EQ(lengthString("hello"), 5);
}

TEST(lengthTest, TestThree)
{
    ASSERT_EQ(lengthString("hello word!"), 11);
}

TEST(countTest, TestOne)
{
    ASSERT_EQ(countSymbol("", ' '), 0);
}

TEST(countTest, TestTwo)
{
    ASSERT_EQ(countSymbol("hello", 'l'), 2);
}

TEST(countTest, TestThree)
{
    ASSERT_EQ(countSymbol("hello word!", 'p'), 0);
}

TEST(myAtoi, TestOne)
{
    ASSERT_EQ(myAtoi("0"), 0);
}

TEST(myAtoi, TestTwo)
{
    ASSERT_EQ(myAtoi("12034"), 12034);
}

TEST(myAtoi, TestThree)
{
    ASSERT_EQ(myAtoi("-12034"), -12034);
}

TEST(myAtoi, TestFour)
{
    ASSERT_EQ(myAtoi("-10034"), -10034);
}

TEST(myAtoi, TestFive)
{
    ASSERT_EQ(myAtoi("-10030"), -10030);
}

TEST(myAtoi, TestSix)
{
    ASSERT_EQ(myAtoi("-10000"), -10000);
}

TEST(concat, TestOne)
{
    ASSERT_STREQ(concat("", ""), "");
}

TEST(concat, TestTwo)
{
    ASSERT_STRCASEEQ(concat("hello", " word"), "hello word");
}

TEST(concat, TestThree)
{
    ASSERT_STREQ(concat("hello", ""), "hello");
}

TEST(stringEQ, TestOne)
{
    ASSERT_TRUE(stringEQ("", ""));
}

TEST(stringEQ, TestTwo)
{
    ASSERT_TRUE(stringEQ("hello word", "hello word"));
}

TEST(stringEQ, TestThree)
{
    ASSERT_FALSE(stringEQ("hello", "hello word"));
}

TEST(stringEmpty, TestOne)
{
    ASSERT_TRUE(stringEmpty(""));
}

TEST(stringEmpty, TestTwo)
{
    ASSERT_FALSE(stringEmpty("h"));
}

TEST(strCmp, TestOne)
{
    ASSERT_EQ(0, myStrcmp("", ""));
}

TEST(strCmp, TestTwo)
{
    ASSERT_EQ(1, myStrcmp("", "a"));
}

TEST(strCmp, TestThree)
{
    ASSERT_EQ(0, myStrcmp("f", "f"));
}

TEST(strCmp, TestFour)
{
    ASSERT_EQ(0, myStrcmp("hello", "hello"));
}