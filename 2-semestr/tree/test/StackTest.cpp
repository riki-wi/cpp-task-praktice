#pragma once

#include "gtest/gtest.h"
#include "../src/Stack.h"

TEST(test_stack_push, test_one)
{
    Stack<int> stack;
    stack.push_stack(1);
    ASSERT_EQ(stack.top(), 1);
}

TEST(test_stack_push, test_two)
{
    Stack<int> stack;
    stack.push_stack(1);
    stack.push_stack(2);
    ASSERT_EQ(stack.top(), 2);

    stack.pop_stack();
    ASSERT_EQ(stack.top(), 1);
}

TEST(test_stack_nullptrex, test_one)
{
    Stack<char> stack;
    ASSERT_THROW(stack.top(), NullPointerException);
}