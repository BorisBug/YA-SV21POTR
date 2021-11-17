/**
 * @file main.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a function to find the greatest common divisor (gcd) of two unsigned integers. E.g the gcd of 8 and 12 is 4.
 *        Make a function to find the least common multiple(lcm) of two unsigned integers. E.g. the lcm of 4 and 6 is 12.
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
    uint32_t x = 8, y = 12;

    (void)printf("The GCD of %u and %u is %u\n", x, y, get_gcd(x, y));

    x = 4, y = 6;

    (void)printf("The LCM of %u and %u is %u\n", x, y, get_lcm(x, y));

    return 0;
}
