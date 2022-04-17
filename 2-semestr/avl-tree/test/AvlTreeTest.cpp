#include "gtest/gtest.h"
#include "../src/AvlTree.h"

TEST(one, one)
{
    AvlTree<int> tree;
    for(int i = 0; i < 10; i++)
    {
        tree.insert(i);
    }
}