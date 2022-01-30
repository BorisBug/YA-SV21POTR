/**
 * @file main.cpp
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of using an interval timer to make the builtin LED blinking every second.
 * @version 0.1
 * @date 2022-01-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Arduino.h>
#include <IntervalTimer.h>

static IntervalTimer timer;
static uint8_t led_state = LOW;

void blink(void)
{
  digitalWrite(LED_BUILTIN, led_state);
  led_state = !led_state;
}

void setup()
{
  Serial.begin(9600);
  delay(2000);

  pinMode(LED_BUILTIN, OUTPUT);

  timer.begin(blink, 500000); // blink is called every second
}

void loop()
{
  Serial.print(".");
  delay(1000);
}
