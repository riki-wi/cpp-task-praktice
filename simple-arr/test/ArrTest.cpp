#include "gtest/gtest.h"
#include "../src/Arr.h"

class TestArr : public ::testing::Test
{
protected:
    void SetUp() override
    {
        masEmpty = Arr<int>();
        masWithSize = Arr<double>(10);
        for(int i = 0; i < masWithSize.getSize(); i++)
        {
            masWithSize[i] = (double)i;
        }
        masWithSizeInit = Arr<std::string>(5, "hello");
    }
    void TearDown() override{}

    Arr<int> masEmpty;
    Arr<double> masWithSize;
    Arr<std::string> masWithSizeInit;
};

TEST_F(TestArr, TestGetSize)
{
    ASSERT_EQ(masEmpty.getSize(), 0);
    ASSERT_EQ(masWithSizeInit.getSize(), 5);
    ASSERT_EQ(masWithSize.getSize(), 10);
}

TEST_F(TestArr, TestGetElement)
{
    ASSERT_THROW(masEmpty.getElement(0), IndexException);
    ASSERT_THROW(masEmpty.getElement(-1), IndexException);
    ASSERT_THROW(masEmpty[-1], IndexException);
    ASSERT_THROW(masEmpty[0], IndexException);

    for(int i = 0; i < masWithSize.getSize(); i++)
    {
        ASSERT_EQ(masWithSize.getElement(i), i);
    }

    ASSERT_EQ(masWithSizeInit[4], "hello");
}

TEST_F(TestArr, TestResize)
{
    ASSERT_THROW(masWithSize.resize(-1), SizeException);

    masWithSize.resize(5);
    ASSERT_EQ(masWithSize.getSize(), 5);
    for(int i = 0; i < 5; i++)
    {
        ASSERT_EQ(masWithSize.getElement(i), i);
    }
    ASSERT_THROW(masWithSize.getElement(5), IndexException);
}

TEST_F(TestArr, TestAddElement)
{
    masEmpty.addElem(1);
    masEmpty.addElem(-1);

    ASSERT_EQ(masEmpty.getSize(), 2);
    ASSERT_EQ(masEmpty.getElement(0), 1);
    ASSERT_EQ(masEmpty.getElement(1), -1);
}

TEST_F(TestArr, TestRemoveElement)
{
    for(int i = 0; i < masWithSize.getSize(); i++)
    {
        masWithSize.removeElem(i);
    }
    ASSERT_THROW(masWithSize[0], IndexException);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}