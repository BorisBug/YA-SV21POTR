#ifndef BSP_H
#define BSP_H

#include <stdint.h>

void bsp_pin_mode(uint8_t pin, uint8_t mode);
uint8_t bsp_digital_read(uint8_t pin);

// helpers
void bsp_sate_fake_value(uint8_t pin, uint8_t val);


#endif