#pragma once
#include "gtest/gtest.h"
#include "../src/Stack.h"

TEST(test_stack, test_one)
{
    Stack<int> stack;
    stack.push_stack(1);
    ASSERT_EQ(stack.top(), 1);
}