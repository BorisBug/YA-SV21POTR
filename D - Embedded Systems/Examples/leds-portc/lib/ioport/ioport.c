#include "ioport.h"
#include <core_pins.h>

#define ALL_HIGH ((uint32_t)0xFF)
#define ALL_OUTPUT ((uint32_t)0xFF)
#define PIN_MUX_GPIO ((uint32_t)1 << 8U)

/**
 * Configure 8 pins of PORTC as GPIO outputs
 */
void ioport_init(void)
{
    // Set the pins as GPIO
    PORTC_PCR0 = PIN_MUX_GPIO; // Pin 15; CORE_PIN15_CONFIG
    PORTC_PCR1 = PIN_MUX_GPIO; // Pin 22
    PORTC_PCR2 = PIN_MUX_GPIO; // Pin 23
    PORTC_PCR3 = PIN_MUX_GPIO; // Pin 9
    PORTC_PCR4 = PIN_MUX_GPIO; // Pin 10
    PORTC_PCR5 = PIN_MUX_GPIO; // Pin 13
    PORTC_PCR6 = PIN_MUX_GPIO; // Pin 11
    PORTC_PCR7 = PIN_MUX_GPIO; // Pin 12

    // Set the pins as outputs
    GPIOC_PDDR = ALL_OUTPUT;

    // Set the pins to HIGH
    GPIOC_PDOR = ALL_HIGH;
}

volatile uint8_t *ioport_address(void)
{
    return (volatile uint8_t *)(&GPIOC_PDOR);
}
