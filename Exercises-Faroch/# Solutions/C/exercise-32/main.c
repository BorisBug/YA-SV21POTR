/**
 * @file exercise-32.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief 1) Make a function to fill an array of type int with random numbers between 0 and 100.
 *        2) Make a function to print an array of type int to the output.
 *        3) Make a function to swap the value of two int variables.
 *        4) Make a function to sort an array of type int.
 *           The function shall accept a function pointer of type compare_t to compare two values
 *                        typedef bool (*compare_t)(int, int);
 *                void sort_array(int *arr, size_t length, compare_t compare);
 *
 *           a) When you sort the array, the compare function shall be used to compare the elements
 *           b) To swap the elements, the swap function of step 2 shall be used.
 *           c) Implement two functions, compare_asc and compare_desc, to sort the array ascending and descending
 *                       bool compare_asc(int a, int b); and bool compare_desc(int a, int b);
 *
 *           d) You shall be able to sort the array ascending and descending by calling sort_array with different compare functions
 *
 *        * To handle the arrays use only pointers
 * @version 0.1
 * @date 2021-03-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "array.h"

#define ARRAY_LEN 10U

static bool compare_asc(int a, int b) { return (a > b); }
static bool compare_desc(int a, int b) { return (a < b); }

int main(void)
{
    int array[ARRAY_LEN] = {0};

    fill_array(array, ARRAY_LEN);

    (void)printf("Array: ");
    print_array(array, ARRAY_LEN);

    sort_array(array, ARRAY_LEN, compare_asc);

    (void)printf("The array sorted ascending: ");
    print_array(array, ARRAY_LEN);

    sort_array(array, ARRAY_LEN, compare_desc);

    (void)printf("The array sorted descending: ");
    print_array(array, ARRAY_LEN);

    return 0;
}
