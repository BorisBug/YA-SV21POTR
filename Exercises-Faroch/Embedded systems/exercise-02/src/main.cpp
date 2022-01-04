#include <Arduino.h>

#define BLINKING_LED_PIN 30

uint8_t led_state = LOW;
uint32_t last_millis = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(BLINKING_LED_PIN, OUTPUT);
}

void loop()
{
    uint32_t now = millis();

    if(now - last_millis > 500u)
    {
        last_millis = now;
        led_state = !led_state;
        Serial.print(led_state ? "on " : "off ");
        digitalWrite(BLINKING_LED_PIN, led_state);
    }
}
