#include <unity.h>
#include <stdio.h>
#include <string.h>
#include "module.h"

#define MIN(a,b) ((a)<(b) ? (a) : (b))

// the fake input buffer
#define FAKE_BUFFER_SIZE 100
static char test_buffer[FAKE_BUFFER_SIZE];

// the fake user_input where we use the fake_buffer instead of the keyboard
bool user_input_for_testing(char *str, int size)
{
    strncpy(str, test_buffer, MIN(size, FAKE_BUFFER_SIZE));
    return true;
}

void test_module()
{
    uint32_t number = 0;

    // the function fails if there is no output variable
    TEST_ASSERT_FALSE(module_get_uint32(NULL));

    // try with a correct string "number"
    strcpy(test_buffer, "100");
    TEST_ASSERT_TRUE(module_get_uint32(&number));
    TEST_ASSERT_EQUAL_UINT32(100, number);

    // try a float number string (not a uint32_t)
    strcpy(test_buffer, "12.34");
    // a float number is not integer and should return false
    TEST_ASSERT_FALSE(module_get_uint32(&number));
    // and the value of number should remain untouched (previous value)
    TEST_ASSERT_EQUAL_UINT32(100, number);

    // try an empty string (not a number)
    strcpy(test_buffer, "");
    // not a number should return false
    TEST_ASSERT_FALSE(module_get_uint32(&number));
    // and the value of number should stll remain untouched (previous value)
    TEST_ASSERT_EQUAL_UINT32(100, number);

    // text (alphabetic) is not a number
    strcpy(test_buffer, "Hello");
    // should return false
    TEST_ASSERT_FALSE(module_get_uint32(&number));
    // and number should still remain untouched and hold the last valid value
    TEST_ASSERT_EQUAL_UINT32(100, number);
}

int main()
{
    module_init(user_input_for_testing);

    UNITY_BEGIN();
    RUN_TEST(test_module);
    return UNITY_END();
}