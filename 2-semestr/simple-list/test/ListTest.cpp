#include "gtest/gtest.h"
#include "../src/List.h"

class TestArr : public ::testing::Test
{
protected:
    void SetUp() override{}
    void TearDown() override{}
};

bool min(const int &a, const int &b)
{
    return a < b;
}

TEST(intersect_list_test, test_one)
{
    List<int> a;
    List<int> b;
    for(int i = 9; i >= 0; i -= 2)
    {
        a.push_front(i);
        b.push_front(i - 1);
    }
    List<int> res = intersect_list_sorted(min, a.begin(), b.begin(), a.end(), b.end());

    int i = 0;
    for(int &iterator: res)
    {
        ASSERT_EQ(iterator, i);
        i++;
    }
}

TEST(intersect_list_test, test_two)
{
    List<int> a;
    for(int i = 9; i >= 0; i--)
    {
        a.push_front(i);
    }
    List<int> res = intersect_list_sorted(min, a.begin(), a.end(), a.end(), a.end());

    int i = 0;
    for(int &iterator: res)
    {
        ASSERT_EQ(iterator, i);
        i++;
    }
}


