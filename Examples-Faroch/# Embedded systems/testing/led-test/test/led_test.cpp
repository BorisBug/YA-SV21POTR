/**
 * @file led_test.cpp
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Using unity to test the built in LED.
 * @version 0.1
 * @date 2021-05-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <unity.h>
#include <Arduino.h>

#define DELAY 500U
#define MAX_BLINKS 5U

void test_led_builtin_pin_number(void)
{
    TEST_ASSERT_EQUAL(13, LED_BUILTIN);
}

void test_led_state_high(void)
{
    digitalWrite(LED_BUILTIN, HIGH);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
}

void test_led_state_low(void)
{
    digitalWrite(LED_BUILTIN, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(LED_BUILTIN));
}

void setup()
{
    delay(2000); // Wait 2 seconds for getting the USB serial ready

    UNITY_BEGIN();

    RUN_TEST(test_led_builtin_pin_number);
    pinMode(LED_BUILTIN, OUTPUT);

    for (uint8_t i = 0; i < MAX_BLINKS; i++)
    {
        RUN_TEST(test_led_state_high);
        delay(DELAY);

        RUN_TEST(test_led_state_low);
        delay(DELAY);
    }

    UNITY_END();
}

void loop()
{
}
