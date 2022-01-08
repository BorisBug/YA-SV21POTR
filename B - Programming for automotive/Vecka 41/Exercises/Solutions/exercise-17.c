/**
 * @file exercise-17.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to read a string from the standard input, then split the string by spaces as the delimiter and 
 *        print them to the output. For example: 
 *                                  The input string: Hello  World
 *                                  The output:
 *                                          Hello
 *                                          World
 * @version 0.1
 * @date 2021-02-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define LENGTH 100

int main(void)
{
    char string[LENGTH] = {0};

    // Read the string from the standard input
    printf("Enter a string: ");
    fgets(string, LENGTH, stdin);
    string[strlen(string) - 1] = '\0'; // fgets captures the newline also and we don't want to have it in the string

    bool space = false;
    int i = 0, length = strlen(string);

    while (i < length)
    {
        if (isspace(string[i]))
        {
            if (!space)
            {
                space = true;
            }
        }
        else
        {
            if (space)
            {
                space = false;
                putchar('\n');
            }
            putchar(string[i]);
        }
        i++;
    }

    return 0;
}
