#include <Metro.h>
#include <Bounce.h>
#include <Arduino.h>

#define DURATION 50
#define BUTTON_PIN 32

uint32_t count = 0;
Bounce button = Bounce(BUTTON_PIN, DURATION);


void setup()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    delay(1000);
}

void loop()
{
    if(button.update())
    {
        if(button.fallingEdge())
        {
            Serial.printf("push %d\n", count++);
            digitalWrite(LED_BUILTIN, HIGH);
        }
        else
        {
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
}
