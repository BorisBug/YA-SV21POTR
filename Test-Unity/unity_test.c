#include "unity.h"


void setUp() {}

void tearDown() {}

void test_do_i_work()
{
	TEST_ASSERT_TRUE(1);
}
int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_do_i_work);
	return UNITY_END();
}