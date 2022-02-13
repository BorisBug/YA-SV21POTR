#ifndef DEBOUNCER_H
#define DEBOUNCER_H

#include <stdbool.h>
#include <stdint.h>

// max amount of buttons to debounce
#define MAX_DEBOUNCE_BTNS 8

// debounced states
#define DEBOUNCER_LOW 0
#define DEBOUNCER_HIGH 1
#define DEBOUNCER_FALLING 2
#define DEBOUNCER_RISING 3

// micro controller abstraction layer
typedef struct
{
    void (*function_ptr1)(void); // change here
    uint8_t (*function_ptr2)(uint8_t); // change here
} debouncer_mcal_t;

/////////////////////
// we need initialization of the module
// option: initiualizing without buttons
uint8_t debouncer_init(debouncer_mcal_t *mcal);

/////////////////////
// we need buttons
// option: create multiple buttons
uint8_t debouncer_create_buttons(uint8_t *pin, uint8_t pin_count);

/////////////////////
// we need update function
void debouncer_update();

/////////////////////
// we need to get the state of a specific button
uint8_t debouncer_get_state(uint8_t btn);


#endif