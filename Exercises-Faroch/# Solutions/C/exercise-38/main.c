/**
 * @file exercise-25.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a function to read a string of max. length N from the standard input using the getchar function.
 *        Make another function to sort the string in alphabetical order.
 * @version 0.1
 * @date 2021-03-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include "module.h"

#define MAX_LENGTH 19U

int main(int argc, char *argv[])
{
    char string[MAX_LENGTH + 1] = {0};

    size_t length = 0;

    while (length == 0)
    {
        (void)printf("Enter a string consisting of %u letters: ", MAX_LENGTH);
        get_string(string, MAX_LENGTH);
        length = strlen(string);
    }

    sort_string(string, length);

    (void)printf("The sorted string: %s\n", string);

    return 0;
}
