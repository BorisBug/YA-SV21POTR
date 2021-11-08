/**
 * @file exercise-29.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 29
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*
Beskrivning
Make a function to print all prime numbers in the range of m and n to the ouput.
m and n are two unsigned integers.
*/

bool is_prime(long long x)
{
    // never <2
    if(x < 2)
        return false;

    // more optimization
    if(x==2 || x==3)
        return true;

    // never even nor divisible by 3
    if(x%2==0 || x%3==0)
        return false;

    // only divisible by 1 & itself
    // start from 5 after optimization
    unsigned long long max = sqrt(x);
    for(unsigned long long i=5; i<=max; i+=2)
        if(x % i == 0)
            return false;

    return true;
}

unsigned long long get_number(const char *label)
{
    int result;
    long long n;

    do
    {
        printf("%s", label);
        result = scanf("%lli", &n);
        fflush(stdin);

        if(result<=0)
            printf("..that was not a number ..try again!\n");
        else if(n<0)
            printf("..enter a positive number ..try again!\n");
    }
    while(result<=0 || n<0);
    return n;
}

int main()
{
    unsigned long long x1, x2, i=0, j=0;

    printf("Calculate all the prime numbers within a range [A-B]..\n");
    x1 = get_number("Enter A: ");
    x2 = get_number("Enter B: ");

    printf("The prime numbers between %llu and %llu are:\n", x1, x2);

    for(i=x1; i<=x2; i++)
    if(is_prime(i))
        printf("%llu %c", i, (j++ && (j%10)==0)?'\n':0);

    printf("\nTotal of prime numbers in between: %llu\n", j);

    return 0;
}