#ifndef DEBOUNCER_H
#define DEBOUNCER_H

#include <stdbool.h>
#include <stdint.h>

/*
#define DEBOUNCER_LOW 0
#define DEBOUNCER_HIGH 1
#define DEBOUNCER_FALLING 2
#define DEBOUNCER_RISING 3
*/
typedef enum
{
    DEBOUNCER_LOW,
    DEBOUNCER_HIGH,
    DEBOUNCER_FALLING,
    DEBOUNCER_RISING,
} debouncer_state_t;

typedef struct
{
    ;
}debouncer_mcal_t;

/////////////////////
// we need initialization of the module
bool debouncer_init();
//void debouncer_init();
uint8_t debouncer_init(uint8_t *pin, uint8_t pin_count);

/////////////////////
// we need buttons
// option: create a single button
uint8_t debouncer_create_button(uint8_t pin);
// option: create multiple buttons
uint8_t debouncer_create_buttons(uint8_t *pin, uint8_t pin_count);

/////////////////////
// we need update function
void debouncer_update();

/////////////////////
// we need to get the state of a specific button
uint8_t debouncer_get_state(uint8_t btn);


#endif