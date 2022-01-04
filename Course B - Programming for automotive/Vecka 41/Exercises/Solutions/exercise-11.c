/**
 * @file exercise-11.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to read a number in the range of 0 and 255 from the standard input using the scanf function in stdio.h
 *        and print the binary form of the number to the output. While the enetered number is not in the range,
 *        the program shall ask for a new number.
 * @version 0.1
 * @date 2021-02-21
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdint.h>

#define RANGE_MIN 0
#define RANGE_MAX 255
#define SHIFT_MAX 7

int main(void)
{
    int number = 0;

    do
    {
        printf("Enter a number in the range of %d and %d: ", RANGE_MIN, RANGE_MAX);
        scanf("%d", &number);
    } while ((number < RANGE_MIN) || (number > RANGE_MAX));

    for (int8_t i = SHIFT_MAX; i >= 0; --i)
    {
        printf("%c", (number & ((uint8_t)1 << (uint8_t)i)) ? '1' : '0');
    }

    printf("\n");

    return 0;
}
