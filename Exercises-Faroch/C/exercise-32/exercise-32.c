/**
 * @file exercise-32.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 32
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
Beskrivning
1) Use the functions you have writen in exercise 31 fill an array
of type int with random numbers and print an array of type int.

2) Make a function to swap the value of two int variables.

3) Make a function to sort an array of type int. The function shall
accept a function pointer of type compare_t to compare two values

    typedef bool (*compare_t)(int, int);
    void sort_array(int *arr, size_t length, compare_t compare);

    a) When you sort the array, the compare function shall beused to compare the elements
    b) To swap the elements, the swap function of step 2 shall be used.
    c) Implement two functions, compare_asc and compare_desc, to sort the array ascending and descending

    bool compare_asc(int a, int b);
    bool compare_desc(int a, int b);

    d) You shall be able to sort the array ascending and descending by calling sort_array with different compare functions

* To handle the arrays use only pointers
*/

#define ARR_SIZE 20

typedef bool (*compare_t)(int, int);

void rand_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

bool compare_asc(int a, int b)
{
    return a > b;
}

bool compare_desc(int a, int b)
{
    return a < b;
}

void print_arr(const int arr[], int size)
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

void sort_array(int *arr, int size, compare_t cmp)
{
    for (int i = 0; i < size; i++)
    for (int j = i+1; j < size; j++)
    if (cmp(arr[i], arr[j]))
        swap(arr+i, arr+j);
}

int main()
{
    int arr[ARR_SIZE]={0};
    srand(time(0));

    // randomize
    rand_arr(arr, ARR_SIZE);
    printf("Array:\n");
    print_arr(arr, ARR_SIZE);

    // sort ascending
    sort_array(arr, ARR_SIZE, compare_asc);
    printf("Sort ascending:\n");
    print_arr(arr, ARR_SIZE);

    // sort descending
    sort_array(arr, ARR_SIZE, compare_desc);
    printf("Sort descending:\n");
    print_arr(arr, ARR_SIZE);

    return 0;
}