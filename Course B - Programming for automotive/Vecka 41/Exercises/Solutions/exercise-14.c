/**
 * @file exercise-14.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to fill a 10 elements int array with random numbers, then print the array to the output,
 *        sort the array ascending and in the end print the sorted array to the output. To generate random numbers,
 *        you can use srand and rand functions in stdlib.h and the time function in time.h.
 *        For example:
 *           The array filled with random numbers: {9, 3, 8, 0, 5, 2, 6, 7, 1, 4}
 *           The sorted array: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
 * @version 0.1
 * @date 2021-02-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ARRAY_LENGTH 10
#define RAND_RANGE_MAX 10

int main(void)
{
    int array[ARRAY_LENGTH] = {0};

    srand(time(0)); // Seed the random function using current time

    // Fill the array with random numbers in the range of 0 and 9 using the rand function
    for (uint8_t i = 0; i < ARRAY_LENGTH; ++i)
    {
        array[i] = rand() % 10;
    }

    // Print the array to the output
    printf("The array filled with random numbers: {");
    for (uint8_t i = 0; i < ARRAY_LENGTH - 1; ++i)
    {
        printf("%d, ", array[i]);
    }
    printf("%d}\n", array[ARRAY_LENGTH - 1]);

    // Sort the array ascending
    for (uint8_t i = 0; i < ARRAY_LENGTH; ++i)
    {
        for (uint8_t j = i + 1; j < ARRAY_LENGTH; ++j)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // Print the sorted array to the output
    printf("The sorted array: {");
    for (uint8_t i = 0; i < ARRAY_LENGTH - 1; ++i)
    {
        printf("%d, ", array[i]);
    }
    printf("%d}\n", array[ARRAY_LENGTH - 1]);

    return 0;
}
