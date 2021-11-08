/**
 * @file exercise-9.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 9
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>

/*
Beskrivning
Make a program to print all the numbers in the range of 0 and 1000 whose last digit is 7.
E.g. 7, 17, 27, 127 and etc.
*/

int main()
{
    for (int i = 0, j = 0; i < 1000; i++)
        if (i % 10 == 7)
            printf("%3d %c", i, ((++j && (j % 15) == 0) ? '\n' : 0));

    printf("\n");
    return 0;
}