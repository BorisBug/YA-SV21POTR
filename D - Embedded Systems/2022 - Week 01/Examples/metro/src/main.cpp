/**
 * @file main.cpp
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of using Metro to make the builtin LED blinking every second.
 * @version 0.1
 * @date 2022-01-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Metro.h>
#include <Arduino.h>

static uint8_t led_state = LOW;
static Metro metro = Metro(500);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  if (1 == metro.check())
  {
    digitalWrite(LED_BUILTIN, led_state);
    led_state = !led_state;
  }
}
