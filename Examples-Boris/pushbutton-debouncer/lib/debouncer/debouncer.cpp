#include "debouncer.h"

// based on the file:
// debouncer_G1-init_no_buttons_create_single.h
// ..and..
// debouncer_G2-init_no_buttons_create_multiple.h

typedef struct 
{
    uint8_t var1;
    uint8_t var2;
    uint8_t var3;
} button_t;

uint8_t btn_count = 0;
button_t array_buttons[] = {0};

uint8_t debouncer_init()
{
    // something with btn_count
}

// G1
uint8_t debouncer_create_button(uint8_t pin)
{
    // if initialized
    // if(pin>57)
    //      error;
    // something with array_buttons[]
    // use_pin_mode_here( xxx );
    // btn_count++;
}

// G2
uint8_t debouncer_create_buttons(uint8_t *pin, uint8_t pin_count)
{
    /*
    if initialized

    if(pin_count > MAX_DEBOUNCE_PIN)
        error;

    for( ; pin_count ; )
    {
        // the code here inside of the loop would be the same as
        // in the function for a single button -> debouncer_create_button
        if(pin>57)
            error;

        // initialize button
        array_buttons[xx].var1 = ??;
        array_buttons[xx].var2 = ??;
        array_buttons[xx].var3 = ??;
        use_pin_mode_here( xxx );
    }

    if not error
        count = pin_count
    */
    return result;
}

void debouncer_update()
{
    // if initialized

    for each button in array_buttons
    {
        pin = ??

        // no abstraction (do not use)
        digitalRead();

        // abstraction - linking
        bsp_digital_read();

        // abstraction - function pointers
        // just in case you want to go from 'G' to 'VG'
        mcal.digital_read();
    }
}

uint8_t debouncer_get_state(uint8_t btn)
{
    // if initialized

    // if valid btn
    {
        // something with array_buttons[btn];
        // state = ??;
    }

    return state;
}