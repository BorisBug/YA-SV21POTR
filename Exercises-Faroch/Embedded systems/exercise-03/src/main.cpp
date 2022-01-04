#include <Metro.h>
#include <Arduino.h>

#define BLINKING_LED_PIN 30

#define FADE_TIME 2000 // 2 seconds
#define FADE_STEPS 20 // 20 steps in FADE_TIME

float led_state = 0;
float fade_inc = 255.0/FADE_STEPS;
Metro flip = Metro(FADE_TIME);
Metro step = Metro(FADE_TIME/FADE_STEPS);

void setup()
{
    Serial.begin(9600);
    pinMode(BLINKING_LED_PIN, OUTPUT);
}

void update()
{
    analogWrite(BLINKING_LED_PIN, led_state);
    Serial.printf("%d%% ", int(led_state*100/255));
}

void loop()
{
    if(flip.check())
    {
        Serial.println("\nflip!");
        step.reset();
        // change fade direction
        fade_inc = -fade_inc;
        // ensure a clean start
        led_state = fade_inc>0 ? 0 : 255;
        // update LED state
        update();
    }

    if(step.check())
    {
        led_state += fade_inc;
        update();
    }
}
