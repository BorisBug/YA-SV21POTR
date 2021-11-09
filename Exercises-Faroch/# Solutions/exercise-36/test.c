#include <unity.h>
#include "module.h"

void setUp(void) {}

void tearDown(void) {}

void test_get_digits(void)
{
    TEST_ASSERT_EQUAL_UINT8(1, get_digits(0));
    TEST_ASSERT_EQUAL_UINT8(3, get_digits(406));
    TEST_ASSERT_EQUAL_UINT8(3, get_digits(-406));
}

void test_power(void)
{
    TEST_ASSERT_EQUAL_FLOAT(8, power(2, 3));
    TEST_ASSERT_EQUAL_FLOAT(-8, power(-2, 3));
    TEST_ASSERT_EQUAL_FLOAT(0.125, power(2, -3));
    TEST_ASSERT_EQUAL_FLOAT(512, power(8, 3));
    TEST_ASSERT_EQUAL_FLOAT(0.00032, power(5, -5));
    TEST_ASSERT_FLOAT_WITHIN(0.000001, 0.000059, power(7, -5));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_get_digits);
    RUN_TEST(test_power);

    return UNITY_END();
}
