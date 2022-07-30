#include "gtest/gtest.h"
#include "../src/SimpleMap.h"

TEST(map_test, test_one)
{
    Simple_Map<int, char> simple_map;
    simple_map.add(1, 'a');

    ASSERT_TRUE(simple_map.find_by_key(1));
    ASSERT_EQ(simple_map.get_by_key(1), 'a');
}

TEST(map_test, test_two)
{
    Simple_Map<int, char> simple_map;
    simple_map.add(1, 'a');
    simple_map.add(2, 'b');
    simple_map.add(3, 'c');

    ASSERT_TRUE(simple_map.find_by_key(1));
    ASSERT_EQ(simple_map.get_by_key(1), 'a');
    simple_map.change_by_key(1, 'b');
    ASSERT_EQ(simple_map.get_by_key(1), 'b');
}