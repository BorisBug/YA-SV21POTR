/**
 * @file exercise-19.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to fill a 10-element int array with random numbers in the range of 0 and 99, then
 *        1. Print the array to the output.
 *        2. Sort the array ascending and then
 *        3. Print the sorted array to the output.
 *
 *        *** To fill, print and sort the array use a pointer ***
 *
 * @version 0.1
 * @date 2021-03-05
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 10U

int main(void)
{
    int *aptr = NULL;
    int array[ARRAY_LENGTH] = {0};

    srand(time(NULL)); // Seed the random number generator

    // Fill the array using random numers
    for (aptr = array; (aptr - array) < ARRAY_LENGTH; aptr++)
    {
        *aptr = rand() % 100; // Generate the random number
    }

    // Print the array to the terminal
    (void)printf("The array filled with random numbers: {");
    for (aptr = array; (aptr - array) < ARRAY_LENGTH - 1; aptr++)
    {
        (void)printf("%d, ", *aptr);
    }
    (void)printf("%d}\n", *aptr);

    // Sort the array
    for (int *iptr = array; (iptr - array) < ARRAY_LENGTH; iptr++)
    {
        for (int *jptr = iptr + 1; (jptr - array) < ARRAY_LENGTH; jptr++)
        {
            if (*iptr > *jptr)
            {
                int temp = *iptr;
                *iptr = *jptr;
                *jptr = temp;
            }
        }
    }

    // Print the sorted array to the terminal
    (void)printf("The sorted array: {");
    for (aptr = array; (aptr - array) < ARRAY_LENGTH - 1; aptr++)
    {
        (void)printf("%d, ", *aptr);
    }
    (void)printf("%d}\n", *aptr);

    return 0;
}
