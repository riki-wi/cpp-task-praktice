#include "gtest/gtest.h"
#include "../src/simple-str.h"

TEST(lengthTest, TestOne)
{
    ASSERT_EQ(length_string(""), 0);
}

TEST(lengthTest, TestTwo)
{
    ASSERT_EQ(length_string("hello"), 5);
}

TEST(lengthTest, TestThree)
{
    ASSERT_EQ(length_string("hello word!"), 11);
}

TEST(countTest, TestOne)
{
    ASSERT_EQ(count_symbol("", ' '), 0);
}

TEST(countTest, TestTwo)
{
    ASSERT_EQ(count_symbol("hello", 'l'), 2);
}

TEST(countTest, TestThree)
{
    ASSERT_EQ(count_symbol("hello word!", 'p'), 0);
}

TEST(myAtoi, TestOne)
{
    ASSERT_EQ(my_atoi("0"), 0);
}

TEST(myAtoi, TestTwo)
{
    ASSERT_EQ(my_atoi("12034"), 12034);
}

TEST(myAtoi, TestThree)
{
    ASSERT_EQ(my_atoi("-12034"), -12034);
}

TEST(myAtoi, TestFour)
{
    ASSERT_EQ(my_atoi("-10034"), -10034);
}

TEST(myAtoi, TestFive)
{
    ASSERT_EQ(my_atoi("-10030"), -10030);
}

TEST(myAtoi, TestSix)
{
    ASSERT_EQ(my_atoi("-10000"), -10000);
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
    ASSERT_TRUE(string_eq("", ""));
}

TEST(stringEQ, TestTwo)
{
    ASSERT_TRUE(string_eq("hello word", "hello word"));
}

TEST(stringEQ, TestThree)
{
    ASSERT_FALSE(string_eq("hello", "hello word"));
}

TEST(stringEmpty, TestOne)
{
    ASSERT_TRUE(string_empty(""));
}

TEST(stringEmpty, TestTwo)
{
    ASSERT_FALSE(string_empty("h"));
}

TEST(polinom_hash, TestOne)
{
    ASSERT_EQ(1, polynomial_hash("a"));
}

TEST(remove_zero_end, TestOne)
{
    ASSERT_STREQ(remove_zero_end("000hello000"), "000hello");
}

TEST(remove_zero_end, TestTwo)
{
    ASSERT_STREQ(remove_zero_end("hello"), "hello");
}

TEST(remove_zero_end, TestThree)
{
    ASSERT_STREQ(remove_zero_end("000"), "");
}

TEST(remove_zero_end, TestFour)
{
    ASSERT_STREQ(remove_zero_end("0h0e0l0lo0"), "0h0e0l0lo");
}

TEST(remove_zero_begin, TestOne)
{
    ASSERT_STREQ(remove_zero_begin("000hello000"), "hello000");
}

TEST(remove_zero_begin, TestTwo)
{
    ASSERT_STREQ(remove_zero_begin("hello"), "hello");
}

TEST(remove_zero_begin, TestThree)
{
    ASSERT_STREQ(remove_zero_begin("000"), "");
}

TEST(remove_zero_begin, TestFour)
{
    ASSERT_STREQ(remove_zero_begin("0h0e0l0lo0"), "h0e0l0lo0");
}