#ifndef DEVENV
#include <Arduino.h>
#else
#include <stdio.h>
#endif
#include "bsp_dio.h"
#include <stdbool.h>

static uint8_t pin_num = 0xFF;
static uint8_t pin_mode = 0xFF;
static uint8_t pin_state = 0xFF;
static uint8_t fail_read = false;

void bsp_invert_read_pin_state(void)
{
    fail_read = !fail_read;
}

void bsp_pin_mode(uint8_t pin, uint8_t mode)
{
    pin_num = pin;
    pin_mode = mode;
#ifndef DEVENV
    Serial.println("TEST: bsp_pin_mode");
    pinMode(pin, mode);
#else
    printf("TEST: bsp_pin_mode\n");
#endif
}

void bsp_dio_write(uint8_t pin, uint8_t val)
{
    pin_num = pin;
    pin_state = val;
#ifndef DEVENV
    digitalWrite(pin, val);
    Serial.println("TEST: bsp_dio_write");
#else
    printf("TEST: bsp_dio_write\n");
#endif
}

uint8_t bsp_dio_read(uint8_t pin)
{
    pin_num = pin;
#ifdef DEVENV
    printf("TEST: bsp_dio_read\n");
    return (fail_read ? !pin_state : pin_state);
#else
    Serial.println("TEST: bsp_dio_read");
    return (fail_read ? !digitalRead(pin) : digitalRead(pin));
#endif
}

uint8_t bsp_get_pin_num(void)
{
    return pin_num;
}

uint8_t bsp_get_pin_mode(void)
{
    return pin_mode;
}
