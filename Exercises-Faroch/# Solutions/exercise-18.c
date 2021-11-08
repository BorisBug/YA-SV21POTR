/**
 * @file exercise-18.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to read date and time in the format of YYYY-MM-DD hh:mm:ss from the input and 
 *        check if the entered date and time is entered in the correct format or not.
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

#define FORMAT "YYYY-MM-DD hh:mm:ss"

int main(void)
{
    char format[] = FORMAT;
    char string[sizeof(FORMAT) + 1] = {0};

    // Read the string from the standard input
    printf("Enter date and time in the format of %s: ", FORMAT);
    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0'; // fgets captures the newline also and we don't want to have it in the string

    int i = 0;
    bool is_correct = true;

    while (i < sizeof(FORMAT) - 1)
    {
        if (isalpha(format[i]))
        {
            if (!isdigit(string[i]))
            {
                is_correct = false;
                break;
            }
        }
        else
        {
            if (format[i] != string[i])
            {
                is_correct = false;
                break;
            }
        }
        i++;
    }

    printf("The format of the entered date and time is%s correct!\n", is_correct ? "" : " not");

    return 0;
}
