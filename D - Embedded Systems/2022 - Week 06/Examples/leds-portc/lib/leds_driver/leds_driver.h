#ifndef LEDS_DRIVER_H
#define LEDS_DRIVER_H

#include <stdint.h>

#define LEDS_DRIVER_ON ((uint8_t)0x01)
#define LEDS_DRIVER_OFF ((uint8_t)0x00)

#define LEDS_DRIVER_ALL_ON ((uint8_t)0xFF)
#define LEDS_DRIVER_ALL_OFF ((uint8_t)0x00)

#define LEDS_DRIVER_OK ((uint8_t)0xF0)
#define LEDS_DRIVER_ERROR ((uint8_t)0x0F)

#ifdef __cplusplus
extern "C"
{
#endif

    uint8_t leds_driver_begin(volatile uint8_t *leds_ptr);
    uint8_t leds_driver_get_state(uint8_t led_number);
    uint8_t leds_driver_turn_off(uint8_t led_number);
    uint8_t leds_driver_turn_on(uint8_t led_number);
    uint8_t leds_driver_turn_all_on(void);
    uint8_t leds_driver_turn_all_off(void);
    void leds_driver_end(void);

#ifdef __cplusplus
}
#endif

#endif /* LEDS_DRIVER_H */
