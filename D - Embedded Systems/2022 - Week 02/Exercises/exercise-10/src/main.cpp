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

#define ADC_RESOLUTION 10 // The ADC Resolution

// Map value from [min_from, max_from] range to [min_to, max_to] range
static int map_value(int value, int min_from, int max_from, int min_to, int max_to)
{
    return (min_to + (max_to - min_to) * (value - min_from) / (max_from - min_from));
}

void setup()
{
    // Set the ADC resolution
    analogReadResolution(ADC_RESOLUTION);
}

void loop()
{
    // Read analog value in the range of [0, (1 << ADC_RESOLUTION) - 1]
    int value = analogRead(A7);

    // Convert value in the range of [0, (1 << ADC_RESOLUTION) - 1] to a pwm value in the range of [0, 255]
    int brightness = map_value(value, 0, (1 << ADC_RESOLUTION) - 1, 0, 255);

    // Write brightness to the PWM pin
    analogWrite(A8, brightness);
}
