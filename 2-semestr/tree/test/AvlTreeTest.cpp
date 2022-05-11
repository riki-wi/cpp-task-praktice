#pragma once

#include "gtest/gtest.h"
#include "../src/AvlTree.h"

bool cmp(const int &a, const int &b)
{
    return a < b;
}

TEST(get_root_avl, test_one)
{
    AvlTree<int, &cmp> tree;
    ASSERT_THROW(tree.get_root(), NullPointerException);
}

TEST(get_root_avl, test_two)
{
    AvlTree<int, &cmp> tree;
    tree.add(0);
    ASSERT_EQ(tree.get_root(), 0);
}

TEST(get_root_avl, test_three)
{
    AvlTree<int, &cmp> tree;
    tree.add(0);
    tree.add(-1);
    tree.add(1);
    ASSERT_EQ(tree.get_root(), 0);
}

TEST(get_root_avl, test_four)
{
    AvlTree<int, &cmp> tree;
    tree.add(0);
    tree.add(-1);
    tree.add(-2);
    tree.add(-3);
    ASSERT_EQ(tree.get_root(), -1);
}

TEST(get_root_avl, test_five)
{
    AvlTree<int, &cmp> tree;
    tree.add(0);
    tree.add(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    ASSERT_EQ(tree.get_root(), 1);
}

TEST(get_root_avl, test_six)
{
    AvlTree<int, &cmp> tree;
    tree.add(0);
    tree.add(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);

    tree.remove(1);
    ASSERT_EQ(tree.get_root(), 2);
}

TEST(get_size_avl, test_one)
{
    AvlTree<int, &cmp> tree;
    ASSERT_EQ(tree.get_size(), 0);
}

TEST(get_size_avl, test_two)
{
    AvlTree<int, &cmp> tree;
    tree.add(1);
    ASSERT_EQ(tree.get_size(), 1);
}

TEST(get_size_avl, test_three)
{
    AvlTree<int, &cmp> tree;
    tree.add(1);
    tree.remove(1);
    ASSERT_EQ(tree.get_size(), 0);
}

TEST(get_size_avl, test_four)
{
    AvlTree<int, &cmp> tree;
    tree.add(1);
    tree.add(2);
    tree.add(3);
    ASSERT_EQ(tree.get_size(), 3);
}

TEST(find_avl, test_one)
{
    AvlTree<int, &cmp> tree;
    AvlTree<int, &cmp>::Iterator iter_null(nullptr);
    ASSERT_TRUE(iter_null == tree.find(1));
}

TEST(find_avl, test_two)
{
    AvlTree<int, &cmp> tree;
    for(int i = 0; i < 10; i++)
    {
        tree.add(i);
    }

    int i = 0;
    for(AvlTree<int, &cmp>::Iterator iter = tree.begin(); iter != tree.end(); ++iter)
    {
        ASSERT_EQ(i, *iter);
        ASSERT_EQ(i, *tree.find(i));
        ASSERT_EQ(iter, tree.find(i));
        i++;
    }
}
