/**
 * @file exercise-13.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 13
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>

/*
Beskrivning
Make a program to read a positive integer number from the standard input,
then sum all the even numbers from 0 to the entered number and print it to the output.
*/

int main()
{
    int r;
    unsigned n, sum = 0;

    // enter a number
    do
    {
        printf("Enter a number: ");
        r = scanf("%u", &n);
        fflush(stdin);

        if(r<=0)
            printf("That was not a number.. try again!\n");
    } while (r <= 0);

    // calculate the sum of all the even numbers
    for (unsigned i = 0; i <= n; i++)
        if(i%2==0)
            sum += i;

    // a faster version
    // for (unsigned i = 2; i <= n; i+=2)
    //    sum += i;

    printf("Sum of all even numbers between 0 and %u is %u\n", n, sum);
    return 0;
}