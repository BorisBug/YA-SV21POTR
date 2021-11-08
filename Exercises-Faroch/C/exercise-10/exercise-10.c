/**
 * @file exercise-10.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 10
 * @version 0.1
 * @date 2021-10-25
 */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*
Beskrivning
Make a program to read an integer number in the range of 2 and 10000 from
the terminal usign the scanf function in stdio.h and check if the number is
a prime number or not. Until the entered number is not in the range, the program
shall ask for a new number.

A prime number is a number which is divisible only by 1 and itself. E.g. 2, 7, 17, 23 and etc.
*/

#define MIN_VAL 2
#define MAX_VAL 10000

bool is_prime(int x)
{
    // never <2
    if (x < 2)
        return false;

    // only divisible by 1 & itself
    unsigned max = sqrt(x);
    for (unsigned i = 2; i <= max; i++)
        if (x % i == 0)
            return false;

    return true;
}

int main()
{
    int x = 0, r = 0;

    do
    {
        printf("enter a number [%d-%d]: ", MIN_VAL, MAX_VAL);
        r = scanf("%d", &x);
        fflush(stdin);

        if(r<=0)
            printf("that was not a number.. try again!\n");
        else if (x < MIN_VAL || x > MAX_VAL)
            printf("number not in range.. try again!\n");
    }
    while (r==0 || x<MIN_VAL || x>MAX_VAL);

    printf("%d is a %sprime number\n", x, (!is_prime(x)?"NOT ":""));
    return 0;
}