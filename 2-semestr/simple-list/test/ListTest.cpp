#include "gtest/gtest.h"
#include "../src/List.h"

class TestList : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

    List<int> a;
    List<int> b;
    int *mas;
};

bool min(const int &a, const int &b)
{
    return a < b;
}

template<typename T>
::testing::AssertionResult eq_list(const List<T> &list, T *mas, int size)
{
    if(list.size() != size)
    {
        return ::testing::AssertionFailure() << "invalid size " << list.size();
    }
    int i = 0;
    for(typename List<T>::Iterator iter = list.begin(); iter != list.end(); ++iter)
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
::testing::AssertionResult eq_iterator(typename List<T>::Iterator &a, typename List<T>::Iterator &b)
{
    if(a == b)
    {
        return ::testing::AssertionSuccess();
    } else
    {
        return ::testing::AssertionFailure() << *a << ", " << *b;
    }
}

TEST_F(TestList, test_intersect_one)
{
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

TEST_F(TestList, test_intersect_two)
{
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

TEST_F(TestList, test_empty_one)
{
    ASSERT_EQ(a.size(), 0);
    ASSERT_TRUE(a.empty());

    a.push_front(1);
    ASSERT_EQ(a.size(), 1);
    ASSERT_FALSE(a.empty());
}

TEST_F(TestList, test_front_one)
{
    ASSERT_THROW(a.front(), NullPointerException);
    a.push_front(31);
    ASSERT_EQ(a.front(), 31);
}

TEST_F(TestList, test_push_one)
{
    mas = new int[10]{1, 3, 5, 7, -1, 2, -10, 13, 9, 18};
    a.push_front(2);
    a.push_front(3);
    a.push_front(1);

    List<int>::Iterator iter = a.begin();
    ++iter;
    a.push_after(5, iter);
    ++iter;
    a.push_after(7, iter);
    ++iter;
    a.push_after(-1, iter);
    a.push_back(-10);
    a.push_back(13);
    a.push_back(9);
    a.push_back(18);
    ASSERT_TRUE(eq_list(a, mas, 10));

    delete[] mas;
}

TEST_F(TestList, test_push_two)
{
    a.push_back(1);
    ASSERT_EQ(1, *a.begin());
}

TEST_F(TestList, test_push_three)
{
    a.push_after(2, a.begin());
    auto iter = List<int>::Iterator(nullptr);
    a.push_after(1, iter);

    mas = new int[2]{2, 1};
    ASSERT_TRUE(eq_list(a, mas, 2));

    delete[] mas;
}

TEST_F(TestList, test_reverse_one)
{
    for(int i = 1; i < 6; i++)
    {
        a.push_front(i);
    }

    a.reverse();
    mas = new int[5]{1, 2, 3, 4, 5};
    ASSERT_TRUE(eq_list(a, mas, 5));

    delete[] mas;
}

TEST_F(TestList, test_reverse_two)
{
    a.push_front(1);
    a.reverse();

    mas = new int[1]{1};
    ASSERT_TRUE(eq_list(a, mas, 1));

    delete[] mas;
}

TEST_F(TestList, test_find_one)
{
    auto iter = List<int>::Iterator(nullptr);
    auto iter_find_1 = a.find(-1);
    ASSERT_TRUE(eq_iterator<int>(iter, iter_find_1));

    for(int i = 0; i < 10; i++)
    {
        a.push_front(i);
    }

    auto iter_find_2 = a.find(-100);
    ASSERT_TRUE(eq_iterator<int>(iter, iter_find_2));

    int i = 9;
    for(iter = a.begin(); iter != a.end(); ++iter)
    {
        auto iter_find = a.find(i);
        ASSERT_TRUE(eq_iterator<int>(iter, iter_find));
        i--;
    }
}

TEST_F(TestList, test_pop)
{
    for(int i = 0; i < 5; i++)
    {
        a.push_front(i);
    }
    a.pop_front();
    a.pop_back();
    mas = new int[3]{3, 2, 1};
    ASSERT_TRUE(eq_list(a, mas, 3));

    delete[] mas;
}

TEST_F(TestList, test_sort_one)
{
    a.push_front(1);
    a.push_front(-2);
    a.push_front(-3);
    a.push_front(-4);
    a.sort(min);
    mas = new int[4]{-4, -3, -2, 1};

    ASSERT_TRUE(eq_list(a, mas, 4));

    delete[] mas;
}

TEST_F(TestList, test_sort_two)
{
    a.push_front(1);
    a.sort(min);
    mas = new int[4]{1};

    ASSERT_TRUE(eq_list(a, mas, 1));

    delete[] mas;
}

TEST_F(TestList, test_sort_three)
{
    a.sort(min);
    mas = new int[0]{};

    ASSERT_TRUE(eq_list(a, mas, 0));

    delete[] mas;
}

TEST_F(TestList, test_sort_four)
{
    a.push_front(1);
    a.push_front(2);
    a.push_front(3);
    a.sort(min);
    mas = new int[3]{1, 2, 3};

    ASSERT_TRUE(eq_list(a, mas, 3));

    delete[] mas;
}
