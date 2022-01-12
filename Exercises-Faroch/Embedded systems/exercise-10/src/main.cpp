/**
 * @file main.cpp
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Exercise 10. Look at circuit.jpg.
 *        Control brightness of the LED using the potentiometer.
 *        The LED circuit is connected to an output PWM pin and the potentiometer is connected to an input analog pin.
 *        To learn how a potentiometer works, look at https://arduinogetstarted.com/tutorials/arduino-potentiometer
 * @version 0.1
 * @date 2022-01-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Arduino.h>

#define ADC_RESOLUTION 10

static int map_value(int value, int minfrom, int maxfrom, int minto, int maxto)
{
    return minto + (maxto-minto) * (value-minfrom) / (maxfrom-minfrom);
}

void setup()
{
    analogReadResolution(ADC_RESOLUTION);
}

void loop()
{
    int value = analogRead(A7);
    int brightness = map_value(value, 0, (1 << ADC_RESOLUTION) - 1, 0, 255);
    analogWrite(A8, brightness);
}
