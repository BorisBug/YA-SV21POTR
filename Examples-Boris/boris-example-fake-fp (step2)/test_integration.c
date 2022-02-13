#include <unity.h>
#include <stdio.h>
#include <string.h>
#include "get_uint32.h"
#include "play.h"

// the fake input buffer
#define FAKE_BUFFER_SIZE 100
static char test_buffer[FAKE_BUFFER_SIZE];

// the fake user_input where we use the fake_buffer instead of the keyboard
bool user_input_for_testing(char *str, int size)
{
    strncpy(str, test_buffer, MIN(size, FAKE_BUFFER_SIZE));
    return true;
}

void test_integration()
{
    strcpy(test_buffer, "0");
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
    get_uint32_init(user_input_for_testing);

    UNITY_BEGIN();
    RUN_TEST(test_integration);
    return UNITY_END();
}