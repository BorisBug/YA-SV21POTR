#ifdef RUN_ON_PC
#include <stdio.h>
#endif

#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define STATE_HIGH 'H'    // high
#define STATE_FALLING 'F' // falling
#define STATE_LOW 'L'     // low
#define STATE_RISING 'R'  // rising

#ifdef RUN_ON_PC
void functions_specific_for_this_define()
{}
#endif

// input: 1 or 0 (bool / digital / binary)
// output: H F L R
uint8_t debounce(bool val)
{
    // use 'val' as the input for the digital_read of the pin connected
    // to the button or to the values returned from the fake_digital_read 
    
    int result = STATE_HIGH;
    return result;
}

int main()
{
    printf("%c ", debounce(1)); // H
    printf("%c ", debounce(1)); // H
    printf("%c ", debounce(1)); // H
    printf("%c ", debounce(1)); // H
    printf("%c ", debounce(0)); // H
    printf("%c ", debounce(1)); // H
    printf("%c ", debounce(0)); // H
    printf("%c ", debounce(1)); // H
    printf("%c ", debounce(0)); // H
    printf("%c ", debounce(0)); // H
    printf("%c ", debounce(0)); // H
    printf("%c ", debounce(0)); // H
    printf("%c ", debounce(0)); // F
    printf("%c ", debounce(0)); // L
    printf("%c ", debounce(0)); // L
    printf("\n");
    return 0;
}