#include <unity.h>
#include "module.h"

#define STRLEN 19U

void setUp(void) {}

void tearDown(void) {}

void test_sort_string(void)
{
    char string[STRLEN + 1] = {0};

    sort_string(string, strlen(string));
    TEST_ASSERT_EQUAL_STRING("", string);

    strncpy(string, "xAYqeMca", STRLEN);
    sort_string(string, strlen(string));
    TEST_ASSERT_EQUAL_STRING("AaceMqxY", string);

    strncpy(string, "XayQEmCA", STRLEN);
    sort_string(string, strlen(string));
    TEST_ASSERT_EQUAL_STRING("AaCEmQXy", string);

    strncpy(string, "jsaNSHosAlPWnSJq", STRLEN);
    sort_string(string, strlen(string));
    TEST_ASSERT_EQUAL_STRING("AaHJjlNnoPqSSssW", string);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_sort_string);

    return UNITY_END();
}
