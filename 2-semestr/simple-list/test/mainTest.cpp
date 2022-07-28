#include "ListTest.cpp"
#include "CircleDoubleListTest.cpp"

#pragma once

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
