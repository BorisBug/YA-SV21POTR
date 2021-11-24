/**
 * @file exercise-21.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to fill a 2D array (3x3) of type int with random numbers in
 *        the range of 0 and 99 and then print the array to the terminal.
 *
 *        **** To fill and print the array, use only pointers ****
 *
 * @version 0.1
 * @date 2021-03-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define ROWS 2U
#define COLUMNS 3U

int main(void)
{
    srand(time(NULL)); // Seed the random number generator

    int matrix[ROWS][COLUMNS] = {0};

    // Fill the array using random numbers
    for (int(*rptr)[COLUMNS] = matrix; (rptr - matrix) < ROWS; rptr++)
    {
        for (int *cptr = *rptr; (cptr - *rptr) < COLUMNS; cptr++)
        {
            *cptr = rand() % 100;
        }
    }

    // Print the array to the terminal
    for (int(*rptr)[COLUMNS] = matrix; (rptr - matrix) < ROWS; rptr++)
    {
        for (int *cptr = *rptr; (cptr - *rptr) < COLUMNS; cptr++)
        {
            (void)printf("%d\t", *cptr);
        }
        (void)printf("\n");
    }

    return 0;
}
