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
  pinMode(LED_BUILTIN, OUTPUT);
  timer.begin(blink, 500000); // blink is called every half second
}

void loop()
{
  static int x=0;
  x=!x;
  
  if(x)
    Serial.print(".");
  else
    Serial.print("*");

  delay(500);
}
