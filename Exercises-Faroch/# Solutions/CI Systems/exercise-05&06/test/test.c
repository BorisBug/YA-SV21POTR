#include "unity.h"
#include "datetime.h"

void setUp() {}
void tearDown() {}

void test_datetime_length(void)
{
    TEST_ASSERT_FALSE(validate_datetime(""));
    TEST_ASSERT_FALSE(validate_datetime(NULL));
    TEST_ASSERT_TRUE(validate_datetime("20:20:17"));
    TEST_ASSERT_TRUE(validate_datetime("2021-04-17"));
    TEST_ASSERT_TRUE(validate_datetime("2021-04-17 20:20:17"));
}

void test_validate_time(void)
{
    TEST_ASSERT_FALSE(validate_datetime("20 20:17"));
    TEST_ASSERT_FALSE(validate_datetime("25:20:1a"));
    TEST_ASSERT_TRUE(validate_datetime("09:20:00"));
}

void test_validate_date(void)
{
    TEST_ASSERT_FALSE(validate_datetime("2021 04-17"));
    TEST_ASSERT_FALSE(validate_datetime("2021-14-17"));
    TEST_ASSERT_FALSE(validate_datetime("2021-04-31"));
    TEST_ASSERT_TRUE(validate_datetime("2020-02-29"));
}

void test_validate_datetime(void)
{
    TEST_ASSERT_FALSE(validate_datetime("2021-04-17 25:20:17"));
    TEST_ASSERT_FALSE(validate_datetime("2021-04-32 00:20:17"));
    TEST_ASSERT_TRUE(validate_datetime("2021-04-12 10:20:17"));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_datetime_length);
    RUN_TEST(test_validate_time);
    RUN_TEST(test_validate_date);
    RUN_TEST(test_validate_datetime);

    return UNITY_END();
}
