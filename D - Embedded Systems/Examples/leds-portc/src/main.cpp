#include "ioport.h"
#include <Arduino.h>
#include "leds_driver.h"

void setup()
{
    ioport_init();

    leds_driver_begin(ioport_address());
}

void loop(void)
{
    leds_driver_turn_on(6);
    delay(300);

    leds_driver_turn_off(6);
    delay(300);
}
