#ifdef RUN_ON_PC
#include <stdio.h>
#endif

#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <unity.h>

#define STATE_HIGH 'H'    // high
#define STATE_FALLING 'F' // falling
#define STATE_LOW 'L'     // low
#define STATE_RISING 'R'  // rising

#ifdef RUN_ON_PC
void functions_specific_for_this_define()
{}
#endif

// fake value used insetad of the real 'digitalRead'
// with this we fake the user interaction
uint8_t fake_val = 0;

uint8_t bsp_digital_read(uint8_t pin)
{
    //return digialRead(pin);
    return fake_val;
}

// input: pin number
// output: H F L R
uint8_t debounce(uint8_t val)
{
    // use 'val' as the input for the digital_read of the pin connected
    // to the button or to the values returned from the fake_digital_read 
    int result = STATE_HIGH;
    return result;
}

#define STEP 2 // 0,1,2

void test()
{
#if STEP==0

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

#elif STEP==1

    TEST_ASSERT_EQUAL_UINT8(STATE_HIGH, debounce(1)); // H
    TEST_ASSERT_EQUAL_UINT8(STATE_HIGH, debounce(1)); // H
    TEST_ASSERT_EQUAL_UINT8(STATE_HIGH, debounce(1)); // H
    TEST_ASSERT_EQUAL_UINT8(STATE_HIGH, debounce(1)); // H
    TEST_ASSERT_EQUAL_UINT8(STATE_HIGH, debounce(0)); // H
    TEST_ASSERT_EQUAL_UINT8(STATE_HIGH, debounce(1)); // H
    TEST_ASSERT_EQUAL_UINT8(STATE_HIGH, debounce(0)); // H
    TEST_ASSERT_EQUAL_UINT8(STATE_HIGH, debounce(1)); // H
    TEST_ASSERT_EQUAL_UINT8(STATE_HIGH, debounce(0)); // H
    TEST_ASSERT_EQUAL_UINT8(STATE_HIGH, debounce(0)); // H
    TEST_ASSERT_EQUAL_UINT8(STATE_HIGH, debounce(0)); // H
    TEST_ASSERT_EQUAL_UINT8(STATE_HIGH, debounce(0)); // H
    TEST_ASSERT_EQUAL_UINT8(STATE_FALLING, debounce(0)); // F
    TEST_ASSERT_EQUAL_UINT8(STATE_LOW, debounce(0)); // L
    TEST_ASSERT_EQUAL_UINT8(STATE_LOW, debounce(0)); // L

#elif STEP==2

    char fake_i[]="1111010100000000";
    char fake_o[]="HHHHHHHHHHHHFLLL";
    
    // input and output should be the same length
    TEST_ASSERT_EQUAL_UINT32(strlen(fake_o), strlen(fake_i));

    int len = strlen(fake_i);

    for(int i=0; i<len; i++)
    {
        // control the value for the digital read
        fake_val = fake_i[i]-'0';
        // test if the input generates the expected output
        TEST_ASSERT_EQUAL_UINT8(fake_o[i], debounce(33));
    }
#else
#error The macro STEP has to be defined (0,1,2) 
#endif
}


#if STEP==0
int main()
{   
    test();
    return 0;
}
#else
int main()
{   
    UNITY_BEGIN();
    RUN_TEST(test);
    return UNITY_END();
}
#endif
