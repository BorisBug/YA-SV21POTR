/**
 * @file exercise-12.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to read the full name of the user character by character from the standard input.
 *        The program shall filter, capitalize and then print it out to the standard output (terminal).
 *         The filtered name can only contain one space between parts of the name and uppercase/lowercase letters (a-z).
 * @version 0.1
 * @date 2021-02-21
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SPACE ' '

int main(void)
{
    char chr = '\0';
    bool first = false;
    bool space = false;

    printf("Enter your full name: ");

    do
    {
        chr = getchar();
        if (isspace(chr) || isalpha(chr))
        {
            if (isspace(chr))
            {
                if (!space && first)
                {
                    first = false;
                    space = true;
                    putchar(SPACE);
                }
            }
            else
            {
                space = false;
                if (!first)
                {
                    putchar(toupper(chr));
                    first = true;
                }
                else
                {
                    putchar(tolower(chr));
                }
            }
        }
    } while ((chr != EOF) && (chr != '\n'));

    printf("\n");

    return 0;
}
