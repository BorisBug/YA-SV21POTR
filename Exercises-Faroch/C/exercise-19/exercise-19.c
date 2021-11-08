/**
 * @file exercise-19.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 19
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Beskrivning
Make a program to fill a 10-element int array with random numbers in the range of 0 and 99, then

print the array to the output.
sort the array ascending and then
Print the sorted array to the output.
To fill, print and sort the array use a pointer.
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
    srand(time(NULL));
    for (int i=0; i<size; i++)
        *(arr+i) = rand() % 100;
}

void sort_arr(int *arr, int size)
{
    for (int i=0; i<size; i++)
    for (int j=i+1; j<size; j++)
    if (*(arr+i) > *(arr+j))
        swap(arr+i, arr+j);
}

void print_arr(const int *arr, int size)
{
    printf("{");
    for (int i=0; i<size; i++)
    {
        printf("%d", *(arr+i));
        if (i<size - 1)
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