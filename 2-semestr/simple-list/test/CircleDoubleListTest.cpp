#include "gtest/gtest.h"
#include "../src/CirculCoubleList.h"

class Test_Circle_Double_List : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

    Circle_Double_List<int> list;
    int *mas;
};

bool min(const char &a, const char &b)
{
    return a < b;
}

template<typename T>
::testing::AssertionResult eq_list(const Circle_Double_List<T> &list, T *mas, int size)
{
    if(list.size() != size)
    {
        return ::testing::AssertionFailure() << "invalid size " << list.size();
    }
    int i = 0;
    for(typename Circle_Double_List<T>::Iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        if(mas[i] != *iter)
        {
            std::cout << mas[i];
            return ::testing::AssertionFailure() << "invalid element " << mas[i];
        }
        i++;
    }
    return ::testing::AssertionSuccess();
}

template<typename T>
::testing::AssertionResult
eq_iterator(typename Circle_Double_List<T>::Iterator &a, typename Circle_Double_List<T>::Iterator &b)
{
    if(a == b)
    {
        return ::testing::AssertionSuccess();
    } else
    {
        return ::testing::AssertionFailure() << *a << ", " << *b;
    }
}

TEST_F(Test_Circle_Double_List, test_empty_one)
{
    ASSERT_EQ(list.size(), 0);

    list.push(1);
    ASSERT_EQ(list.size(), 1);
}

TEST_F(Test_Circle_Double_List, test_push_one)
{
    mas = new int[10]{1, 3, 2};
    list.push(2);
    list.push(3);
    list.push(1);

    ASSERT_TRUE(eq_list(list, mas, 3));

    delete[] mas;
}

TEST_F(Test_Circle_Double_List, test_push_two)
{
    list.push(1);
    ASSERT_EQ(1, *list.begin());
}

TEST_F(Test_Circle_Double_List, test_pop)
{
    for(int i = 0; i < 5; i++)
    {
        list.push(i);
    }
    list.pop();
    list.pop();
    mas = new int[3]{2, 1, 0};
    ASSERT_TRUE(eq_list(list, mas, 3));

    delete[] mas;
}

TEST_F(Test_Circle_Double_List, cycle_test_one)
{
    list.push(1);
    auto iter = list.begin();
    ++iter;
    ASSERT_EQ(1, *iter);

    --iter;
    --iter;
    ASSERT_EQ(1, *iter);
}

TEST_F(Test_Circle_Double_List, cycle_test_two)
{
    list.push(1);
    list.push(2);
    list.push(3);
    auto iter = list.begin();
    ASSERT_EQ(3, *iter);
    ++iter;
    ASSERT_EQ(2, *iter);
    ++iter;
    ASSERT_EQ(1, *iter);
    ++iter;
    ASSERT_EQ(3, *iter);

    ASSERT_EQ(list.size(), 3);
}

TEST_F(Test_Circle_Double_List, cycle_test_three)
{
    list.push(1);
    list.push(2);
    list.push(3);
    auto iter = list.begin();
    ASSERT_EQ(3, *iter);
    --iter;
    ASSERT_EQ(1, *iter);
    --iter;
    ASSERT_EQ(2, *iter);
    --iter;
    ASSERT_EQ(3, *iter);

    ASSERT_EQ(list.size(), 3);
}