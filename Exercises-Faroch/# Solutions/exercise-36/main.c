/**
 * @file main.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a function to count the digits of a given integer number using recursion. E.g. 456 has 3 digits
 *        Make a function to calculate the power of any integer number using recursion. E.g. 2^3 = 8
 * @version 0.1
 * @date 2021-03-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include "module.h"

int main(void)
{
    int x, y;

    x = 1234;
    (void)printf("%d has %u digit(s)\n", x, get_digits(x));

    x = -1234;
    (void)printf("%d has %u digit(s)\n", x, get_digits(x));

    x = 2;
    y = 3;
    (void)printf("%d^%d = %g\n", x, y, power(x, y));

    x = -2;
    y = 3;
    (void)printf("%d^%d = %g\n", x, y, power(x, y));

    x = 2;
    y = -3;
    (void)printf("%d^%d = %g\n", x, y, power(x, y));

    return 0;
}
