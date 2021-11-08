/**
 * @file exercise-21.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 21
 * @version 0.1
 * @date 2021-10-25
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Beskrivning
Make a program to fill a 2D array (3x3) of type int with random
numbers in the range of 0 and 99 and then print the array to the terminal.
To fill and print the array, use only pointers.
*/

#define SIZE1 4 // rows
#define SIZE2 7 // columns

int main()
{
    int arr[SIZE1][SIZE2];
    int *ptr=(int*)arr;
    
    // randomize
    srand(time(NULL));
    for(int i=0; i<SIZE1; i++)
    for(int j=0; j<SIZE2; j++)
        *(*(arr+i)+j) = rand() % 100;
        //arr[i][j] = rand() % 100;

    // print using index to TEST that the answers are correct and equivalent
    printf("\nA) Matrix: using [][] on arr\n");
    for(int i=0; i<SIZE1; i++)
    {
        for(int j=0; j<SIZE2; j++)
            printf("%4d", arr[i][j]);

        printf("\n");
    }

    printf("\nB) Matrix: using (**) on arr\n");
    for(int i=0; i<SIZE1; i++)
    {
        for(int j=0; j<SIZE2; j++)
            printf("%4d", *(*(arr+i)+j));

        printf("\n");
    }

    printf("\nC) Matrix: using (*) on ptr\n");
    for(int i=0; i<SIZE1; i++)
    {
        for(int j=0; j<SIZE2; j++)
            printf("%4d", *(ptr+i*SIZE2+j));

        printf("\n");
    }

    printf("\nD) Matrix: using [] on ptr:\n");
    for(int i=0; i<SIZE1; i++)
    {
        for(int j=0; j<SIZE2; j++)
            printf("%4d", ptr[i*SIZE2+j]);

        printf("\n");
    }

    printf("\nE) Matrix: using combination *[] on arr:\n");
    for(int i=0; i<SIZE1; i++)
    {
        for(int j=0; j<SIZE2; j++)
            printf("%4d", *(arr[i]+j));

        printf("\n");
    }

    printf("\nF) Matrix: using combination *[] on ptr:\n");
    for(int i=0; i<SIZE1; i++)
    {
        for(int j=0; j<SIZE2; j++)
            printf("%4d", *(&ptr[i*SIZE2]+j));

        printf("\n");
    }

    // In my opinion, options A & D are the only ones
    // that are worth to remember. Maybe use one minute
    // to dig into B & C. Options E & F are just way too
    // complicated to understand when we are reading the
    // flow of the code.

    return 0;
}