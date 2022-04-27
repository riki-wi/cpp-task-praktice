#pragma once

#include "BinTreeTest.cpp"
#include "StackTest.cpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
