#pragma once

#include "gtest/gtest.h"
#include "../src/BinTree.h"

TEST(get_root, test_one)
{
    BinTree<int> tree;
    ASSERT_THROW(tree.get_root(), NullPointerException);
}

TEST(get_root, test_two)
{
    BinTree<int> tree;
    tree.add(0);
    ASSERT_EQ(tree.get_root(), 0);
}

TEST(get_root, test_three)
{
    BinTree<int> tree;
    tree.add(0);
    tree.add(-1);
    tree.add(1);
    ASSERT_EQ(tree.get_root(), 0);
}

TEST(get_root, test_four)
{
    BinTree<int> tree;
    tree.add(0);
    tree.add(-1);
    tree.add(-2);
    tree.add(-3);
    ASSERT_EQ(tree.get_root(), 0);
}

TEST(get_size, test_one)
{
    BinTree<int> tree;
    ASSERT_EQ(tree.get_size(), 0);
}

TEST(get_size, test_two)
{
    BinTree<int> tree;
    tree.add(1);
    ASSERT_EQ(tree.get_size(), 1);
}

TEST(get_size, test_three)
{
    BinTree<int> tree;
    tree.add(1);
    tree.remove(1);
    ASSERT_EQ(tree.get_size(), 0);
}

TEST(get_size, test_four)
{
    BinTree<int> tree;
    tree.add(1);
    tree.add(2);
    tree.add(3);
    ASSERT_EQ(tree.get_size(), 3);
}

TEST(find, test_one)
{
    BinTree<int> tree;
    BinTree<int>::Iterator iter_null(nullptr);
    ASSERT_TRUE(iter_null == tree.find(1));
}

TEST(find, test_two)
{
    BinTree<int> tree;
    for(int i = 0; i < 10; i++)
    {
        tree.add(i);
    }

    int i = 0;
    for(BinTree<int>::Iterator iter = tree.begin(); iter != tree.end(); ++iter)
    {
        ASSERT_EQ(i, *iter);
        ASSERT_EQ(i, *tree.find(i));
        ASSERT_EQ(iter, tree.find(i));
        i++;
    }
}