/**
 * @file exercise-25.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a function to fill an array of type int with unique random numbers between 0 and 100.
 *        Make another function to print an array of type int to the output.
 *        Example: An array filled with random numbers: {9, 3, 8, 0, 5, 2, 6, 7, 1, 4}
 * @version 0.1
 * @date 2021-03-05
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_LENGTH 10U

static void fill_array(int arr[], size_t len);
static void print_array(const int arr[], size_t len);
static bool in_array(int value, int arr[], size_t len);

int main(void)
{
    int array[ARRAY_LENGTH] = {0};

    fill_array(array, ARRAY_LENGTH);

    print_array(array, ARRAY_LENGTH);

    return 0;
}

static bool in_array(int value, int arr[], size_t len)
{
    bool found = false;
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] == value)
        {
            found = true;
            break;
        }
    }

    return found;
}

static void fill_array(int arr[], size_t len)
{
    srand(time(NULL)); // Seed the random number generator

    for (size_t i = 0; i < len; i++)
    {
        int temp;
        do
        {
            temp = 1 + rand() % 99;
        } while (in_array(temp, arr, len));

        arr[i] = temp;
    }
}

static void print_array(const int arr[], size_t len)
{
    (void)printf("The array filled with random numbers: {");
    for (size_t i = 0; i < len - 1; ++i)
    {
        (void)printf("%d, ", arr[i]);
    }
    (void)printf("%d}\n", arr[len - 1]);
}
