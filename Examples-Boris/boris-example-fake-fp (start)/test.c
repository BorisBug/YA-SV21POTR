#include <unity.h>
#include <stdio.h>
#include "module.h"

void test_module()
{
    uint32_t number = 0;
    TEST_ASSERT_FALSE(module_get_uint32(NULL));
    // How can i test this?
    // I am depending on the user to write the "right" input for each test case
    // and most important, i have to wait until they actually write the input!!!
    TEST_ASSERT_TRUE(module_get_uint32(&number));
    TEST_ASSERT_FALSE(module_get_uint32(&number));
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_module);
    return UNITY_END();
}