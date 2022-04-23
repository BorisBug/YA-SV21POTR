# FreeRTOS Example on Teensy 3.5

To use FreeRTOS on Teensy you need to change the prototype of 2 functions(systick_isr and pendablesrvreq_isr) in kinetis.h

You need to prepend __attribute__((weak)) to the prototypes. I.e. they shall be like:

    __attribute__((weak)) extern void pendablesrvreq_isr(void);
    __attribute__((weak)) extern void systick_isr(void);
