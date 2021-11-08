/**
 * @file exercise-27.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 27
 * @version 0.1
 * @date 2021-10-25
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

/*
Beskrivning
Make a function to find the largest value in an array of type int
and a function to get the average of values in the array.

Make another function to find a specific value in an array of type int.
If the value exists in the array, the index of the value in the array shall
be returned; otherwise -1.
*/


#define ARR_SIZE 15

int find_value(int *arr, unsigned size, int value)
{
    for (int i = 0; i < size; i++)
        if(value == arr[i])
            return i;

    return -1;
}

int calc_largest(int *arr, unsigned size)
{
    int max = INT32_MIN;
    for (unsigned i = 0; i < size; i++)
        if(max < arr[i])
            max = arr[i];

    return max;
}

double calc_average(int *arr, unsigned size)
{
    double avg = 0.;
    for (unsigned i = 0; i < size; i++)
        avg += arr[i];

    return size > 0 ? avg / size : 0;
}

void rand_unique_arr(int *arr, unsigned size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
        do {
            arr[i] = rand() % 1000;
        } while (i>0 && find_value(arr, i-1, arr[i]) >= 0);
}

void print_arr(const int *arr, unsigned size)
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
    int val;

    // randomize and print
    rand_unique_arr(arr, ARR_SIZE);
    printf("Array with unique values:\n");
    print_arr(arr, ARR_SIZE);

    // calc largest
    printf("Largest value: %d\n", calc_largest(arr, ARR_SIZE));

    // calc average
    printf("Average value: %f\n", calc_average(arr, ARR_SIZE));

    // find value
    val = 0; // true or false ?
    printf("Find value: %d at index %d\n", val, find_value(arr, ARR_SIZE, val));

    val = 30; // true or false ?
    printf("Find value: %d at index %d\n", val, find_value(arr, ARR_SIZE, val));

    val = arr[rand()%ARR_SIZE]; // true!!
    printf("Find value: %d at index %d\n", val, find_value(arr, ARR_SIZE, val));

    return 0;
}