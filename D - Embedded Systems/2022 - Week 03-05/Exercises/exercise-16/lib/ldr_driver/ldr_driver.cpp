#include <Arduino.h>
#include "ldr_driver.h"

#define VOLTAGE_REFERENCE 3.3f      // The voltage reference of the ADC
#define RESISTOR_RESISTANCE (4700U) // The resistance of the resistor

static inline float map_value(float value, float from_min, float from_max, float to_min, float to_max)
{
    return ((value - from_min) * (to_max - to_min) / (from_max - from_min) + to_min);
}

static uint8_t pin_num = LDR_DRIVER_ERROR;

void ldr_driver_init(uint8_t pin)
{
    pin_num = pin;
    analogReadResolution(ADC_RESOLUTION);
}

uint8_t ldr_driver_get_intensity(void)
{
    uint8_t intensity = LDR_DRIVER_ERROR;

    if (pin_num != LDR_DRIVER_ERROR)
    {
        // Read the data from the analog pin and convert it to voltage
        float voltage = map_value(analogRead(pin_num), 0, (1 << ADC_RESOLUTION) - 1, 0, VOLTAGE_REFERENCE);

        // Calculate the resistance of the LDR
        float ldr_resistance = RESISTOR_RESISTANCE * (VOLTAGE_REFERENCE - voltage) / voltage;

        if (ldr_resistance >= LDR_RESISTANCE_MAX)
        {
            intensity = 0;
        }
        else if (ldr_resistance <= LDR_RESISTANCE_MIN)
        {
            intensity = 100;
        }
        else
        {
            intensity = map_value(ldr_resistance, LDR_RESISTANCE_MIN, LDR_RESISTANCE_MAX, 100, 0);
        }
    }

    return intensity;
}
