#include "test.h"

TEST(test1)
{
    ASSERT_EQ(int(1),int(2));
}

TEST(test2)
{
    unsigned int x = 5;
    ASSERT_EQ(x, int(5));
}

TEST(test3)
{
    ASSERT_EQ("wq", "two");
}

TEST(test4)
{
    ASSERT_EQ("one", "one");
}

TEST(test5)
{
    ASSERT_EQ(7.89, 87.9);
}

TEST(test6)
{
    ASSERT_EQ('s', 'd');
}

TEST(test7)
{
    int mas1[] = {1,2,3,4,5};
    int mas2[] = {1,2,3,4,5};
    ASSERT_EQ_ARRAY(mas1, mas2, sizeof(mas1) / sizeof (int), sizeof(mas2) / sizeof (int));
}

TEST(test8)
{
    double mas1[] = {1.4, 2.3, 3.4, 4.5, 5.6};
    double mas2[] = {1.4 ,2.3 ,3.4 ,4.5 ,5.9};
    ASSERT_EQ_ARRAY(mas1, mas2, sizeof(mas1) / sizeof (double), sizeof(mas2) / sizeof (double));
}


int main()
{
    return 0;
}
