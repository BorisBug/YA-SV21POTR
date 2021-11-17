/**
 * @file exercise-10.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to read an integer number in the range of 2 and 10000 from the terminal usign the scanf function in stdio.h
 *        and check if the number is a prime number or not. Until the entered number is not in the range, the program shall ask for
 *        a new number. A prime number is a number which is divisible only by 1 and itself. E.g. 2, 7, 17, 23 and etc.
 * @version 0.1
 * @date 2021-02-21
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define FIRST_PRIME 2
#define RANGE_MIN 2
#define RANGE_MAX 10000

int main(void)
{
    int number = 0;

    do
    {
        printf("Enter a number between %d and %d: ", RANGE_MIN, RANGE_MAX);
        scanf("%d", &number);
    } while ((number < RANGE_MIN) || (number > RANGE_MAX));

    bool is_prime = true;

    if (number > FIRST_PRIME)
    {
        // It is enough to check if the number is divisible by numbers int the range of 2 and the square root of the number.
        uint8_t counter = FIRST_PRIME;
        uint8_t max_number = ceil(sqrt(number));

        while (counter <= max_number)
        {
            if (number % counter == 0)
            {
                is_prime = false;
                break;
            }

            counter++;
        }
    }

    printf("%d is %sa prime number\n", number, is_prime ? "" : "not ");

    return 0;
}
