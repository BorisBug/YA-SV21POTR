#ifndef LDR_DRIVER_H
#define LDR_DRIVER_H

#include <stdint.h>

#define ADC_RESOLUTION (12U) // The resolution of the ADC.

#define LDR_RESISTANCE_MIN (2000U)
#define LDR_RESISTANCE_MAX (50000U)

#define LDR_DRIVER_ERROR (0xFFU)

void ldr_driver_init(uint8_t pin);

uint8_t ldr_driver_get_intensity(void);

#endif /* LDR_DRIVER_H */
