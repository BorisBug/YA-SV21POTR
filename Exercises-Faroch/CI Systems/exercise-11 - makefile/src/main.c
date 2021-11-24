/**
 * @file main.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program that prints the numbers from one to an entered number between 1 and 255 by the user.
 *             If a number is a multiple of three, print “Fizz” instead
 *             If a number is a multiple of five, print “Buzz” instead
 *             If a number is a multiple of both three and five, print “FizzBuzz” instead
 * 
 *             For example; The sequence from one to twenty looks like this:
 *                 1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz
 *             
 *             You should follow the TDD technique to develop the program.
 * 
 *             Source: https://en.wikipedia.org/wiki/Fizz_buzz
 * 
 * @version 0.1
 * @date 2021-04-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "fizzbuzz.h"

#define ERROR_MESSAGE "Enter a number in the range of [1, 255] as an argument!\n"

static int *strtoint(const char *str, int *ptr)
{
    int *result = ptr;

    *ptr = 0;

    for (char *d = (char *)str; *d != '\0'; d++)
    {
        if ((*d < '0') || (*d > '9'))
        {
            result = NULL;
            break;
        }

        *ptr *= 10;
        *ptr += (*d - '0');
    }

    return result;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        (void)printf(ERROR_MESSAGE);
        exit(1);
    }

    int number = 0;

    if (NULL == strtoint(argv[1], &number))
    {
        (void)printf(ERROR_MESSAGE);
        exit(1);
    }

    if ((number < 1) || (number > 255))
    {
        (void)printf(ERROR_MESSAGE);
        exit(1);
    }

    for (int i = 1; i <= number; i++)
    {
        (void)printf("%s\t", fizz_buzz(i));
    }

    (void)printf("\n");

    return 0;
}
