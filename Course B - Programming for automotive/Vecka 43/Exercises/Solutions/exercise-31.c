/**
 * @file exercise-31.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief 1) Make a function to fill an array of type int with random numbers between 0 and 100.
 *        2) Make a function to print an array of type int to the output.
 *        3) Make a function to print a 2D array of type int to the output.
 *         * To handle the arrays use only pointers
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
#define ARRAY_LEN 10U

static void fill_array(int *arr, size_t len);
static void print_array(const int *arr, size_t len);
static void print_2d_array(const int (*arr)[], size_t rows, size_t columns);

int main(void)
{
    int array[ARRAY_LEN] = {0};

    fill_array(array, ARRAY_LEN);

    (void)printf("Array: ");
    print_array(array, ARRAY_LEN);

    int matrix[ROWS][COLUMNS] = {{1, 2, 3}, {4, 5, 6}};

    print_2d_array(matrix, ROWS, COLUMNS);

    return 0;
}

static void print_2d_array(const int (*arr)[], size_t rows, size_t columns)
{
    int(*matrix)[columns] = (int(*)[columns])arr;

    for (int(*rptr)[columns] = matrix; (rptr - matrix) < rows; rptr++)
    {
        for (int *cptr = *rptr; (cptr - *rptr) < columns; cptr++)
        {
            (void)printf("%d\t", *cptr);
        }
        (void)printf("\n");
    }
}

static void print_array(const int *arr, size_t len)
{
    int *iptr = (int *)arr;

    (void)printf("{");
    while ((iptr - arr) < (len - 1))
    {
        (void)printf("%d, ", *iptr++);
    }
    (void)printf("%d}\n", *iptr);
}

static void fill_array(int *arr, size_t len)
{
    srand(time(NULL));

    for (int *iptr = arr; (iptr - arr) < len; iptr++)
    {
        *iptr = rand() % 100;
    }
}
