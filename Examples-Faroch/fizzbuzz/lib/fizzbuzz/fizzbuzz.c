#include <stdio.h>
#include <string.h>
#include "fizzbuzz.h"

#define FIZZ "Fizz"
#define FIZZ_DIV (3U)

#define BUZZ "Buzz"
#define BUZZ_DIV (5U)

#define FIZZBUZZ "FizzBuzz"
#define FIZZBUZZ_DIV (FIZZ_DIV * BUZZ_DIV)

static char result[sizeof(FIZZBUZZ)] = {0};

char *fizz_buzz(uint8_t num)
{
    if (num == 0)
    {
        strcpy(result, "");
    }
    else if (num % FIZZBUZZ_DIV == 0)
    {
        strcpy(result, FIZZBUZZ);
    }
    else if (num % BUZZ_DIV == 0)
    {
        strcpy(result, BUZZ);
    }
    else if (num % FIZZ_DIV == 0)
    {
        strcpy(result, FIZZ);
    }
    else
    {
        sprintf(result, "%d", num);
    }

    return result;
}
