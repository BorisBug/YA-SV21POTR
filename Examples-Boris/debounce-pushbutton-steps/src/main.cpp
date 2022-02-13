#include <Arduino.h>

#define BUTTON_PIN 33
#define REPS_FOR_STABLE_VALUE 5

void setup()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(9600);
    delay(2000);
}

void loop_proof_of_bouncing()
{
    static uint8_t counter = 0;
    static uint8_t prev = HIGH;
    uint8_t cur_state = digitalRead(BUTTON_PIN);

    // proof of bouncing
    if(cur_state != prev)
    {
        counter++;
        prev = cur_state;

        if(cur_state==HIGH)
            Serial.printf("%d HIGH\n", counter);
        else
            Serial.printf("%d LOW\n", counter);
    }
}

void loop_debounce_hl()
{
    static uint8_t counter = 0;
    static uint8_t debounce_state = HIGH;
    uint8_t cur_state = digitalRead(BUTTON_PIN);

    if(cur_state == debounce_state)
    {
        if(counter !=0)
        {
            Serial.printf(". ."); // bounce
            counter = 0;
        }
    }
    else//(cur_state != debounce_state)
    {
        counter++;
        Serial.printf(".%d.", counter);
        if(counter>=REPS_FOR_STABLE_VALUE)
        {
            counter = 0;
            debounce_state = cur_state;
        }
    }

    // just for debug
    static int print_count = 0;
    static int print_prev = HIGH;
    if(print_prev != debounce_state)
    {
        print_prev = debounce_state;
        print_count++;

        if(print_prev==HIGH)
            Serial.printf(". HIGH -> %d\n", print_count);
        else
            Serial.printf(". LOW  -> %d\n", print_count);
    }
}

void loop_debounce_hflr()
{
    static uint8_t counter = 0;
    static uint8_t debounce_state = HIGH;
    uint8_t cur_state = digitalRead(BUTTON_PIN);

    #define DEBOUNCE_HIGH 1
    #define DEBOUNCE_FALLING 2
    #define DEBOUNCE_LOW 3
    #define DEBOUNCE_RISING 4

    if(debounce_state==DEBOUNCE_RISING)
        debounce_state = DEBOUNCE_HIGH;
    else if(debounce_state==DEBOUNCE_FALLING)
        debounce_state = DEBOUNCE_LOW;

    if((cur_state==LOW && (debounce_state==DEBOUNCE_LOW || debounce_state==DEBOUNCE_FALLING)) ||
       (cur_state==HIGH && (debounce_state==DEBOUNCE_HIGH || debounce_state==DEBOUNCE_RISING)))
    {
        if(counter !=0)
        {
            Serial.printf(". ."); // bounce
            counter = 0;
        }
    }
    else//(cur_state != prev)
    {
        counter++;
        Serial.printf(".%d.", counter);
        if(counter>=REPS_FOR_STABLE_VALUE)
        {
            counter = 0;
            debounce_state = cur_state==HIGH ? DEBOUNCE_RISING : DEBOUNCE_FALLING;
        }
    }

    // just for debug
    static int print_count = 0;
    static int print_prev = DEBOUNCE_HIGH;
    if(print_prev != debounce_state)
    {
        print_prev = debounce_state;

        const char *txt=NULL;
        switch(print_prev)
        {
            default:
            case DEBOUNCE_HIGH:    txt = "HIGH"; break;
            case DEBOUNCE_FALLING: txt = "FALLING"; print_count++; break;
            case DEBOUNCE_LOW:     txt = "LOW"; break;
            case DEBOUNCE_RISING:  txt = "RISING"; break;
        }

        Serial.printf(". %s -> %d\n", txt, print_count);
    }
}


void loop()
{
    //loop_proof_of_bouncing();
    //loop_debounce_hl();
    loop_debounce_hflr();
}
