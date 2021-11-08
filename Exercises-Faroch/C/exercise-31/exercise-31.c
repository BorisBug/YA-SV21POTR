/**
 * @file exercise-31.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 31
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Beskrivning
1) Make a function to fill an array of type int with random numbers between 0 and 100.
2) Make a function to print an array of type int to the output.
3) Make a function to print a 2D array of type int to the output.
* To handle the arrays use only pointers
*/

#define ARR_SIZE 20

#define ARR2D_SIZE1 3
#define ARR2D_SIZE2 5

#define ARR3D_SIZE1 2
#define ARR3D_SIZE2 3
#define ARR3D_SIZE3 5


// 1) Make a function to fill an array of type int with random numbers between 0 and 100.
void rand_arr(int *arr, int size)
{
    for(int i = 0; i < size; i++)
        arr[i] = rand() % 101;
}

// 2) Make a function to print an array of type int to the output.
void print_arr(const int arr[], int size)
{
    printf("{");
    for(int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("}");
}

// 3) Make a function to print a 2D array of type int to the output.
void print_arr2D(const int *arr2D, int size1, int size2)
{
    printf("{");
    for(int i=0; i<size1; i++)
    {
        print_arr(arr2D + i * size1, size2);
         if (i < size1 - 1)
            printf(",\n ");
    }
    printf("}");
}

// just for fun ;)
void print_arr3D(const int *arr3D, int size1, int size2, int size3)
{
    printf("{");
    for(int i=0; i<size1; i++)
    {
        print_arr2D(arr3D + i * size1, size2, size3);
         if (i < size1 - 1)
            printf(",\n");
    }
    printf("}");
}


int main()
{
    int arr[ARR_SIZE]={0};
    int arr2D[ARR2D_SIZE1][ARR2D_SIZE2]={0};
    int arr3D[ARR3D_SIZE1][ARR3D_SIZE2][ARR3D_SIZE3] = {0};
    srand(time(0));

    // randomize and print
    rand_arr(arr, ARR_SIZE);
    printf("Array:\n");
    print_arr(arr, ARR_SIZE);
    printf("\n");

    for(int i = 0; i < ARR2D_SIZE1; i++)
    for(int j = 0; j < ARR2D_SIZE2; j++)
        arr2D[i][j] = rand() % 9000 + 1000; // 1000-9999 

    printf("Array 2D:\n");
    print_arr2D((int*)arr2D, ARR2D_SIZE1, ARR2D_SIZE2);
    printf("\n");

    // just for fun

    for(int i = 0; i < ARR3D_SIZE1; i++)
    for(int j = 0; j < ARR3D_SIZE2; j++)
    for(int k = 0; k < ARR3D_SIZE3; k++)
        arr3D[i][j][k] = rand() % 900 + 100; // 100-999

    printf("Array 3D:\n");
    print_arr3D((int*)arr3D, ARR3D_SIZE1, ARR3D_SIZE2, ARR3D_SIZE3);
    printf("\n");

    return 0;
}