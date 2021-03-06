#include <unity.h>
#include "Arduino.h"
#include "ldr_driver.h"

void setUp(void) {}

void tearDown(void) {}

void test_ldr_driver(void)
{
    TEST_ASSERT_EQUAL_UINT8(LDR_DRIVER_ERROR, ldr_driver_get_intensity());

    uint8_t ldr_pin = 33;
    ldr_driver_init(ldr_pin);
    TEST_ASSERT_EQUAL_UINT8(ADC_RESOLUTION, arduino_get_resolutuin());

    arduino_set_pin_value(100);
    TEST_ASSERT_EQUAL_UINT8(0, ldr_driver_get_intensity());
    TEST_ASSERT_EQUAL_UINT8(ldr_pin, arduino_get_pin_num());

    arduino_set_pin_value(1000);
    TEST_ASSERT_EQUAL_UINT8(73, ldr_driver_get_intensity());
    TEST_ASSERT_EQUAL_UINT8(ldr_pin, arduino_get_pin_num());

    arduino_set_pin_value(3000);
    TEST_ASSERT_EQUAL_UINT8(100, ldr_driver_get_intensity());
    TEST_ASSERT_EQUAL_UINT8(ldr_pin, arduino_get_pin_num());
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_ldr_driver);

    return UNITY_END();
}
