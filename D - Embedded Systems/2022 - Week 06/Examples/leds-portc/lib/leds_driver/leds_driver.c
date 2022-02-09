#include <stdlib.h>
#include "leds_driver.h"

#define LED_NUM_MIN (1U)
#define LED_NUM_MAX (8U)

static uint8_t leds_value = LEDS_DRIVER_ALL_ON;
static volatile uint8_t *address = NULL;

static uint8_t update_hardware(void);
static uint8_t is_address_valid(void);
static uint8_t is_led_valid(uint8_t led_number);
static uint8_t get_led_mask(uint8_t led_number);

uint8_t leds_driver_begin(volatile uint8_t *leds_address)
{
    leds_value = LEDS_DRIVER_ALL_OFF;
    address = leds_address;
    return update_hardware();
}

uint8_t leds_driver_get_state(uint8_t led_number)
{
    uint8_t state = LEDS_DRIVER_ERROR;
    if (is_address_valid() && is_led_valid(led_number))
    {
        state = ((leds_value & get_led_mask(led_number)) ? LEDS_DRIVER_ON : LEDS_DRIVER_OFF);
    }
    return state;
}

uint8_t leds_driver_turn_on(uint8_t led_number)
{
    uint8_t status = LEDS_DRIVER_ERROR;

    if (is_address_valid())
    {
        if (is_led_valid(led_number))
        {
            leds_value |= get_led_mask(led_number);
            status = update_hardware();
        }
    }

    return status;
}

uint8_t leds_driver_turn_off(uint8_t led_number)
{
    uint8_t status = LEDS_DRIVER_ERROR;
    if (is_address_valid() && is_led_valid(led_number))
    {
        leds_value &= ~get_led_mask(led_number);
        status = update_hardware();
    }
    return status;
}

uint8_t leds_driver_turn_all_on(void)
{
    leds_value = LEDS_DRIVER_ALL_ON;
    return update_hardware();
}

uint8_t leds_driver_turn_all_off(void)
{
    leds_value = LEDS_DRIVER_ALL_OFF;
    return update_hardware();
}

void leds_driver_end(void)
{
    leds_driver_turn_all_on();
    address = NULL;
}

/******* Local Functions ******/

static uint8_t update_hardware(void)
{
    uint8_t status = LEDS_DRIVER_ERROR;
    if (is_address_valid())
    {
        *address = leds_value;
        status = LEDS_DRIVER_OK;
    }
    else
    {
        leds_value = LEDS_DRIVER_ALL_ON;
    }
    return status;
}

static uint8_t get_led_mask(uint8_t led_number)
{
    return (1U << --led_number);
}

static uint8_t is_led_valid(uint8_t led_number)
{
    return ((led_number >= LED_NUM_MIN) && (led_number <= LED_NUM_MAX));
}

static uint8_t is_address_valid(void)
{
    return (address != NULL);
}
