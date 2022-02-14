#include <Metro.h>
#include <Arduino.h>
#include "debouncer.h"

// milliseconds between each update
#define UPDATE_TIME 10

// pin connection for each button
#define BUTTON1_PIN 33
#define BUTTON2_PIN 34
#define BUTTON3_PIN 35

// for option G1, VG1
static uint8_t btn1 = 0;
static uint8_t btn2 = 0;
static uint8_t btn3 = 0;

// for option G2, G2, VG2, VG3
#define BUTTON1 0
#define BUTTON2 1
#define BUTTON3 2

static uint8_t prev_state1 = DEBOUNCER_HIGH;
static uint8_t prev_state2 = DEBOUNCER_HIGH;
static uint8_t prev_state3 = DEBOUNCER_HIGH;
static Metro timer = Metro(UPDATE_TIME);

void setup()
{
    Serial.begin(9600);
    delay(2000);

    // in my opinion option 1 is the one that brings more clarity
    // and less chances for confusion as a programmer and for the user

    /////////////////////////////////////////
    // G

    // option G1
    debouncer_init();
    btn1 = debouncer_create_button(BUTTON1_PIN);
    btn2 = debouncer_create_button(BUTTON2_PIN);
    btn3 = debouncer_create_button(BUTTON3_PIN);

    // option G2
    uint8_t pins[] = {BUTTON1_PIN, BUTTON2_PIN, BUTTON3_PIN};
    debouncer_init();
    debouncer_create_buttons(pins, 3);

    // option G3
    uint8_t pins[] = {BUTTON1_PIN, BUTTON2_PIN, BUTTON3_PIN};
    debouncer_init(pins, 3);

    /////////////////////////////////////////
    // VG

    debouncer_mcal_t mcal;
    mcal.function_ptr1 = bsp_something;
    // initialize mcal

    // option VG1
    debouncer_init(&mcal);
    btn1 = debouncer_create_button(BUTTON1_PIN);
    btn2 = debouncer_create_button(BUTTON2_PIN);
    btn3 = debouncer_create_button(BUTTON3_PIN);

    // option VG2
    uint8_t pins[] = {BUTTON1_PIN, BUTTON2_PIN, BUTTON3_PIN};
    debouncer_init(&mcal);
    debouncer_create_buttons(pins, 3);

    // option VG3
    uint8_t pins[] = {BUTTON1_PIN, BUTTON2_PIN, BUTTON3_PIN};
    debouncer_init(&mcal, pins, 3);
}

void loop()
{
    if(timer.check())
    {
        // update the state of all the buttons in the module
        debouncer_update();

        // for G1 or VG1
        uint8_t state1 = debouncer_get_state(btn1);
        uint8_t state2 = debouncer_get_state(btn1);
        uint8_t state3 = debouncer_get_state(btn1);

        // for G2,G3 or VG2,VG3
        uint8_t state1 = debouncer_get_state(BUTTON1);
        uint8_t state2 = debouncer_get_state(BUTTON1);
        uint8_t state3 = debouncer_get_state(BUTTON1);

        if(prev_state1!=state1)
        {
            prev_state1 = state1;
            Serial.printf("BTN 1 State = %d\n", state1);
        }

        if(prev_state2!=state2)
        {
            prev_state2 = state2;
            Serial.printf("BTN 2 State = %d\n", state2);
        }

        if(prev_state3!=state3)
        {
            prev_state3 = state3;
            Serial.printf("BTN 3 State = %d\n", state3);
        }
    }
}