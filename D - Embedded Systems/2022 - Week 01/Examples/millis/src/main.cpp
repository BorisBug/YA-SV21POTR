/**
 * @file main.cpp
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of using millis to make the builtin LED blinking every second.
 * @version 0.1
 * @date 2022-01-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Arduino.h>

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    static uint8_t led_state = LOW;
    static uint32_t last_millis = 0;

    uint32_t now = millis();

#if 0

    static uint16_t counter = 0;

    if (last_millis > now) // When the timer gets overflowed
    {
        counter += (0xFFFFFFFFu - last_millis) + 1u + now;
    }
    else
    {
        counter += (now - last_millis);
    }

    last_millis = now;

    if (counter >= 500u)
    {
        counter = 0;
        led_state = !led_state;
        digitalWrite(LED_BUILTIN, led_state);
    }
#else
    if (now - last_millis >= 500u)
    {
        last_millis = now;
        led_state = !led_state;
        digitalWrite(LED_BUILTIN, led_state);
    }
#endif
}
