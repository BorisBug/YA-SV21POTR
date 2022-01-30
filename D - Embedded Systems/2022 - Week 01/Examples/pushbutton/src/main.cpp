/**
 * @file main.cpp
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief This example shows boucing of a pushbutton connected to Teensy. For the connection look at circuit.png
 * @version 0.1
 * @date 2022-01-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Metro.h>
#include <Arduino.h>

#define DURATION 100
#define BUTTON_PIN 33

static uint32_t count = 0;
static uint32_t previous_count = 0;
static uint8_t previous_state = HIGH;
static Metro timer = Metro(DURATION);

void setup()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(9600);
    delay(2000);
}

void loop()
{
    uint8_t current_state = digitalRead(BUTTON_PIN);

    if (current_state != previous_state)
    {
        if (current_state == LOW)
        {
            count++;
        }
        previous_state = current_state;
    }

    if ((count != previous_count) && timer.check())
    {
        Serial.printf("count: %d\n", count);
        previous_count = count;
    }
}
