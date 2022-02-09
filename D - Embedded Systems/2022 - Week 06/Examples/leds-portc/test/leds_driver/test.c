#include <unity.h>
#include "leds_driver.h"

#ifndef DEVENV
#include "ioport.h"
#include <Arduino.h>
#endif

static volatile uint8_t *leds_address = NULL;

void setUp(void)
{
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OK, leds_driver_begin(leds_address));
}

void tearDown(void)
{
    leds_driver_end();
}

void test_invalid_address(void)
{
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ERROR, leds_driver_begin(NULL));
}

void test_leds_off_after_start(void)
{
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ALL_OFF, *leds_address);
}

void test_valid_led_number(void)
{
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OFF, leds_driver_get_state(1));
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OFF, leds_driver_get_state(8));

    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OK, leds_driver_turn_on(1));
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ON, leds_driver_get_state(1));

    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OK, leds_driver_turn_on(8));
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ON, leds_driver_get_state(8));

    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OK, leds_driver_turn_off(1));
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OFF, leds_driver_get_state(1));

    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OK, leds_driver_turn_off(8));
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OFF, leds_driver_get_state(8));

    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OK, leds_driver_turn_off(5));
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OFF, leds_driver_get_state(5));

    leds_driver_end();
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ERROR, leds_driver_turn_on(5));
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ERROR, leds_driver_turn_off(5));
}

void test_invalid_led_number(void)
{
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ERROR, leds_driver_turn_on(0));
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ERROR, leds_driver_get_state(0));

    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ERROR, leds_driver_turn_on(10));
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ERROR, leds_driver_get_state(10));

    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ERROR, leds_driver_turn_off(10));
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ERROR, leds_driver_get_state(10));
}

void test_turn_all_on(void)
{
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OK, leds_driver_turn_all_on());
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ALL_ON, *leds_address);
}

void test_turn_all_off(void)
{
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OK, leds_driver_turn_all_off());
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ALL_OFF, *leds_address);
}

void test_uninitialized_driver(void)
{
    leds_driver_end();

    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ERROR, leds_driver_turn_all_off());
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ERROR, leds_driver_turn_all_on());

    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ERROR, leds_driver_turn_off(5));
    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_ERROR, leds_driver_get_state(5));

    TEST_ASSERT_EQUAL_UINT8(LEDS_DRIVER_OK, leds_driver_begin(leds_address));
}

#ifdef DEVENV
int main(void)
{
    volatile uint8_t virtual_leds = LEDS_DRIVER_ALL_ON;
    leds_address = &virtual_leds;
#else
void loop()
{
}

void setup()
{
    delay(3000U);
    ioport_init();
    leds_address = ioport_address();
#endif

    UNITY_BEGIN();
    RUN_TEST(test_invalid_address);
    RUN_TEST(test_leds_off_after_start);
    RUN_TEST(test_valid_led_number);
    RUN_TEST(test_invalid_led_number);
    RUN_TEST(test_turn_all_on);
    RUN_TEST(test_turn_all_off);
    RUN_TEST(test_uninitialized_driver);

#ifdef DEVENV
    return UNITY_END();
#else
    UNITY_END();
#endif
}
