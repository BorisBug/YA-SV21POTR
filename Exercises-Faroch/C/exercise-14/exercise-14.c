/**
 * @file exercise-14.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 14
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Beskrivning
Make a program to fill a 10 elements int array with random numbers,
then print the array to the output, sort the array ascending and in
the end print the sorted array to the output. To generate random numbers,
you can use srand and rand functions in stdlib.h and the time function in time.h.

For example:
The array filled with random numbers: {9, 3, 8, 0, 5, 2, 6, 7, 1, 4}
The sorted array: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} 
*/

#define ARR_SIZE 10

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void rand_arr(int *arr, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 10000; // caped for easy reading test
}

void sort_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    for (int j = i+1; j < size; j++)
    if (arr[i] > arr[j])
        swap(arr+i, arr+j);
}

void print_arr(const int *arr, int size)
{
    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("}\n");
}

int main()
{
    int arr[ARR_SIZE];

    // randomize and print
    rand_arr(arr, ARR_SIZE);
    printf("Array:\n");
    print_arr(arr, ARR_SIZE);

    // sort and print
    sort_arr(arr, ARR_SIZE);
    printf("Sorted:\n");
    print_arr(arr, ARR_SIZE);

    return 0;
}