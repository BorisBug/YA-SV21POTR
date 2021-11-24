/**
 * @file exercise-29.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a function to print all prime numbers in the range of m and n to the ouput.
 *        m and n are two unsigned integers.
 * @version 0.1
 * @date 2021-03-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define FIRST_PRIME 2U

static void print_primes(uint32_t m, uint32_t n);

int main(void)
{
    print_primes(100, 1000);

    return 0;
}

static void print_primes(uint32_t m, uint32_t n)
{
    uint32_t minval = (m < n) ? m : n;
    uint32_t maxval = (m > n) ? m : n;

    while (minval <= maxval)
    {
        bool prime = true;

        if (minval < FIRST_PRIME)
        {
            prime = false;
        }
        else
        {
            if (minval > FIRST_PRIME)
            {
                uint8_t counter = FIRST_PRIME;
                uint8_t max_number = ceil(sqrt(minval));

                while (counter <= max_number)
                {
                    if (minval % counter == 0)
                    {
                        prime = false;
                        break;
                    }

                    counter++;
                }
            }
        }

        if (prime)
        {
            (void)printf("%u\t", minval);
        }

        minval++;
    }
}
