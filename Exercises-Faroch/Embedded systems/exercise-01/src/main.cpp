#include <Arduino.h>

#define ADC_RESOLUTION 10u
#define VOLT_OFFSET 500u
#define MILLIVOLT_PER_CELCIUS 10u
#define VOLTAGE_RESOLUTION  ((3300.0f)/(1<<ADC_RESOLUTION)) // 3.3 mV / (2 ^ resolution)

void setup()
{
    Serial.begin(9600);
    delay(2000);
    analogReadResolution(ADC_RESOLUTION);
}

void loop()
{
    int value = analogRead(A14);
    float volt = value * VOLTAGE_RESOLUTION;
    float temp = (volt - VOLT_OFFSET) / MILLIVOLT_PER_CELCIUS;
    Serial.printf("value: %d - volt: %.3f - temp: %.2f\n", value, volt, temp);
    delay(1000);
}
