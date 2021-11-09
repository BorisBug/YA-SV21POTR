#include <unity.h>
#include "module.h"

void setUp(void) {}

void tearDown(void) {}

void test_get_lcm(void)
{
    TEST_ASSERT_EQUAL_UINT32(0, get_lcm(0, 0));
    TEST_ASSERT_EQUAL_UINT32(0, get_lcm(10, 0));
    TEST_ASSERT_EQUAL_UINT32(0, get_lcm(0, 10));

    TEST_ASSERT_EQUAL_UINT32(12, get_lcm(4, 6));
    TEST_ASSERT_EQUAL_UINT32(24, get_lcm(12, 8));
    TEST_ASSERT_EQUAL_UINT32(144, get_lcm(48, 18));
}

void test_get_gcd(void)
{
    TEST_ASSERT_EQUAL_UINT32(0, get_gcd(0, 0));
    TEST_ASSERT_EQUAL_UINT32(0, get_gcd(10, 0));
    TEST_ASSERT_EQUAL_UINT32(0, get_gcd(0, 10));

    TEST_ASSERT_EQUAL_UINT32(2, get_gcd(4, 6));
    TEST_ASSERT_EQUAL_UINT32(4, get_gcd(12, 8));
    TEST_ASSERT_EQUAL_UINT32(6, get_gcd(48, 18));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_get_lcm);
    RUN_TEST(test_get_gcd);

    return UNITY_END();
}
