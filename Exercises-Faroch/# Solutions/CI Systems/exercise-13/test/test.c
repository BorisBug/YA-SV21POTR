#include "unity.h"
#include "roman.h"

void setUp() {}
void tearDown() {}

void test_roman_numeral(void)
{
    TEST_ASSERT_EQUAL_INT(0, roman2decimal(""));
    TEST_ASSERT_EQUAL_INT(0, roman2decimal(NULL));
    TEST_ASSERT_EQUAL_INT(96, roman2decimal("XCVI"));
    TEST_ASSERT_EQUAL_INT(0, roman2decimal("VCXVI"));
    TEST_ASSERT_EQUAL_INT(521, roman2decimal("DXXI"));
    TEST_ASSERT_EQUAL_INT(346, roman2decimal("CCCXLVI"));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_roman_numeral);
    return UNITY_END();
}
