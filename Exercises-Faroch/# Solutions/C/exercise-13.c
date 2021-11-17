/**
 * @file exercise-13.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to read a positive integer number from the standard input, 
 *        then sum all the even numbers from 0 to the entered number and print it to the output.
 * @version 0.1
 * @date 2021-02-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int number = 0;

    do
    {
        printf("Enter a number greater than 0: ");
        scanf("%d", &number);
    } while (number <= 0);

    int sum = 0;
    for (int i = 0; i <= number; i += 2)
    {
        sum += i;
    }

    printf("Sum of the even numbers is: %d\n", sum);

    return 0;
}
