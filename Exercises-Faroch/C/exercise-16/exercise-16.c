/**
 * @file exercise-16.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 16
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <string.h>

/*
Beskrivning
Write a program in C for a 2D array of size 3x3 and print the matrix.
First ask the user to enter all the enteries [i][j] and then print the array to the output.
Print the array to the output like a table. E.g.

123  234  456
54   678  987
12   987  100
*/


int main()
{
    int r=1;
    int arr[3][3];

    printf("Enter the values for the [3][3] matrix:\n");

    for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
    {
        do{
            if(!r) printf("again..");
            printf("[%d][%d]: ", i, j);
            r = scanf("%d", &arr[i][j]);
            fflush(stdin);
        } while (r < 1);
    }

    printf("Matrix:\n");

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
            printf("%4d", arr[i][j]);

        printf("\n");
    }

    return 0;
}