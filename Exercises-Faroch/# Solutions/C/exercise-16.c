/**
 * @file exercise-16.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Write a program in C for a 2D array of size 3x3 and print the matrix.
 *        First ask the user to enter all the enteries [i][j] and then print the array to the output.
 *        Print the array to the output like a table. For example:
 *                                                    123   234  456
 *                                                    54    678  987
 *                                                    12    987  100
 * @version 0.1
 * @date 2021-02-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdint.h>

#define ROWS 3
#define COLUMNS 3

int main(void)
{
    int matrix[ROWS][COLUMNS] = {0};

    // Read the elements from the standard input
    for (uint8_t row = 0; row < ROWS; ++row)
    {
        for (uint8_t column = 0; column < COLUMNS; ++column)
        {
            printf("Enter the value of matrix[%u][%u]: ", row, column);
            scanf("%i", &matrix[row][column]);
        }
    }

    // Print the array to the output
    for (uint8_t row = 0; row < ROWS; ++row)
    {
        for (uint8_t column = 0; column < COLUMNS; ++column)
        {
            printf("%d\t", matrix[row][column]);
        }
        printf("\n");
    }

    return 0;
}
