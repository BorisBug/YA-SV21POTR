/**
 * @file exercise-33.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to find how many years it takes to move 64 disks from a peg to another one if each move takes 1 second.
 * @version 0.1
 * @date 2021-03-05
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdint.h>

#define DISKS 64U
#define SECONDS_IN_YEAR (365 * 24 * 60 * 60)

static float hanoi(uint8_t n);

int main(void)
{
    float years = hanoi(DISKS) / SECONDS_IN_YEAR;

    (void)printf("It takes approx. %g years to move %d disks.\n", years, DISKS);

    return 0;
}

// This is equivalent to 2^n -1 = ((1 << n) - 1)
static float hanoi(uint8_t n)
{
    return (n == 1) ? 1.0f : (2 * hanoi(n - 1) + 1.0f);
}
