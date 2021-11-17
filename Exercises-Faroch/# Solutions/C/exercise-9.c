/**
 * @file exercise-9.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to print all the numbers in the range of 0 and 1000 whose last digit is 7. E.g. 7, 17, 27, 127 and etc.
 * @version 0.1
 * @date 2021-02-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>

#define RANGE_MIN 0
#define RANGE_MAX 1000

int main(void)
{
    for (int i = RANGE_MIN; i <= RANGE_MAX; ++i)
    {
        if (i % 10 == 7) // i % 10 gives us the last digit of i
        {
            printf("%d\n", i);
        }
    }

    printf("\n");

    return 0;
}
