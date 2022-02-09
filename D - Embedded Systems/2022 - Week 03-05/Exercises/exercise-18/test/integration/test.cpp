#include <unity.h>
#include <string.h>
#include "terminal.h"
#include "bsp_serial.h"
#ifndef DEVENV
#include <Arduino.h>
#endif
#include "bsp_dio.h"

#define LED_PIN 13

#define DONE_MSG " => done\n"
#define FAILED_MSG " => failed\n"
#define COMMAND_MSG "Enter the command [0: Off, 1: On]: "

static char buffer[2 + (sizeof(DONE_MSG) > sizeof(FAILED_MSG) ? sizeof(DONE_MSG) : sizeof(FAILED_MSG))];

void test_terminal_without_initialization(void)
{
    terminal_run();
    TEST_ASSERT_FALSE(bsp_get_serial_init());
    TEST_ASSERT_EQUAL_STRING("", bsp_get_serial_outbuf());
    TEST_ASSERT_NOT_EQUAL(LED_PIN, bsp_get_pin_num());
    TEST_ASSERT_NOT_EQUAL(OUTPUT, bsp_get_pin_mode());
}

void test_terminal_init(void)
{
    terminal_init();
    TEST_ASSERT_TRUE(bsp_get_serial_init());
    TEST_ASSERT_EQUAL_UINT8(0, bsp_serial_available());
    TEST_ASSERT_EQUAL_STRING("", bsp_get_serial_outbuf());
    TEST_ASSERT_EQUAL_UINT8(LED_PIN, bsp_get_pin_num());
    TEST_ASSERT_EQUAL_UINT8(OUTPUT, bsp_get_pin_mode());
    TEST_ASSERT_EQUAL_UINT8(LOW, bsp_dio_read(LED_PIN));
}

void test_terminal_waiting_on_user(void)
{
    terminal_run();
    TEST_ASSERT_EQUAL_STRING(COMMAND_MSG, bsp_get_serial_outbuf());
    TEST_ASSERT_EQUAL_UINT8(0, bsp_serial_available());
    TEST_ASSERT_EQUAL_UINT8(LOW, bsp_dio_read(LED_PIN));

    terminal_run();
    TEST_ASSERT_EQUAL_STRING("", bsp_get_serial_outbuf());
    TEST_ASSERT_EQUAL_UINT8(0, bsp_serial_available());
    TEST_ASSERT_EQUAL_UINT8(LOW, bsp_dio_read(LED_PIN));

    bsp_set_serial_inbuf("\n");
    TEST_ASSERT_EQUAL_UINT8(1, bsp_serial_available());
    terminal_run();
    TEST_ASSERT_EQUAL_UINT8(LOW, bsp_dio_read(LED_PIN));
    TEST_ASSERT_EQUAL_UINT8(0, bsp_serial_available());
    TEST_ASSERT_EQUAL_STRING("\n", bsp_get_serial_outbuf());

    terminal_run();
    TEST_ASSERT_EQUAL_UINT8(LOW, bsp_dio_read(LED_PIN));
    TEST_ASSERT_EQUAL_STRING(COMMAND_MSG, bsp_get_serial_outbuf());
}

void test_terminal_led_on(void)
{
    strcpy(buffer, "1");
    bsp_set_serial_inbuf(buffer);
    TEST_ASSERT_EQUAL_UINT8(1, bsp_serial_available());
    terminal_run();
    TEST_ASSERT_EQUAL_UINT8(0, bsp_serial_available());
    TEST_ASSERT_EQUAL_STRING(strcat(buffer, DONE_MSG), bsp_get_serial_outbuf());
    TEST_ASSERT_EQUAL_UINT8(HIGH, bsp_dio_read(LED_PIN));

#ifndef DEVENV
    delay(2000);
#endif

    strcpy(buffer, "1");
    bsp_invert_read_pin_state();
    bsp_set_serial_inbuf(buffer);
    TEST_ASSERT_EQUAL_UINT8(1, bsp_serial_available());
    terminal_run();
    TEST_ASSERT_EQUAL_UINT8(0, bsp_serial_available());
    TEST_ASSERT_EQUAL_STRING(strcat(buffer, FAILED_MSG), bsp_get_serial_outbuf());
    TEST_ASSERT_EQUAL_UINT8(LOW, bsp_dio_read(LED_PIN));
    bsp_invert_read_pin_state();
}

void test_terminal_led_off(void)
{
    strcpy(buffer, "0");
    bsp_invert_read_pin_state();
    bsp_set_serial_inbuf(buffer);
    TEST_ASSERT_EQUAL_UINT8(1, bsp_serial_available());
    terminal_run();
    TEST_ASSERT_EQUAL_UINT8(0, bsp_serial_available());
    TEST_ASSERT_EQUAL_STRING(strcat(buffer, FAILED_MSG), bsp_get_serial_outbuf());
    TEST_ASSERT_EQUAL_UINT8(HIGH, bsp_dio_read(LED_PIN));
    bsp_invert_read_pin_state();

    strcpy(buffer, "0");
    bsp_set_serial_inbuf(buffer);
    TEST_ASSERT_EQUAL_UINT8(1, bsp_serial_available());
    terminal_run();
    TEST_ASSERT_EQUAL_UINT8(0, bsp_serial_available());
    TEST_ASSERT_EQUAL_STRING(strcat(buffer, DONE_MSG), bsp_get_serial_outbuf());
    TEST_ASSERT_EQUAL_UINT8(LOW, bsp_dio_read(LED_PIN));
}

void test_terminal_invalid_input(void)
{
    bsp_set_serial_inbuf("p");
    TEST_ASSERT_EQUAL_UINT8(1, bsp_serial_available());
    terminal_run();
    TEST_ASSERT_EQUAL_STRING(COMMAND_MSG, bsp_get_serial_outbuf());
    TEST_ASSERT_EQUAL_STRING("", bsp_get_serial_outbuf());
    TEST_ASSERT_EQUAL_UINT8(LOW, bsp_dio_read(LED_PIN));

    terminal_run();
    TEST_ASSERT_EQUAL_STRING("", bsp_get_serial_outbuf());
}

#ifdef DEVENV
int main(void)
{
#else
void loop()
{
}

void setup()
{
    delay(2000);
#endif
    UNITY_BEGIN();
    RUN_TEST(test_terminal_without_initialization);
    RUN_TEST(test_terminal_init);
    RUN_TEST(test_terminal_waiting_on_user);
    RUN_TEST(test_terminal_led_on);
    RUN_TEST(test_terminal_led_off);
    RUN_TEST(test_terminal_invalid_input);
#ifdef DEVENV
    return UNITY_END();
#else
    UNITY_END();
#endif
}
