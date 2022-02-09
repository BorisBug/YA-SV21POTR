#include <unity.h>
#include <stdio.h>
#include <string.h>
#include "play.h"

void test_play()
{
    // even numbers
    TEST_ASSERT_TRUE(play(0));          // lower boundary
    TEST_ASSERT_TRUE(play(0x7FFFFFFE)); // middle range
    TEST_ASSERT_TRUE(play(0xFFFFFFFE)); // near higher boundary 

    // uneven numbers
    TEST_ASSERT_FALSE(play(1));          // near lower boundary
    TEST_ASSERT_FALSE(play(0x7FFFFFFF)); // middle range
    TEST_ASSERT_FALSE(play(0xFFFFFFFF)); // higher boundary 
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_play);
    return UNITY_END();
}