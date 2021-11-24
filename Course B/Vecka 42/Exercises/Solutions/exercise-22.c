/**
 * @file exercise-22.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to read date time in the format of YYYY-MM-DD HH:mm:ss from the input and validate it.
 *        A leap year is exactly divisible by 4 except for century years (years ending with 00).
 *        The century year is a leap year only if it is perfectly divisible by 400.
 *        If the year is a leap year, then February 29, is the leap day.
 * @version 0.1
 * @date 2021-02-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>

#define FORMAT "YYYY-MM-DD HH:mm:ss"
#define YEAR_MIN 2000U
#define YEAR_MAX 9999U
#define MONTH_MIN 1U
#define MONTH_MAX 12U
#define DAY_MIN 1U
#define HOUR_MAX 59U
#define MINUTE_MAX 59U
#define SECOND_MAX 59U
#define FEBRUARY 2U

int main(void)
{
    char format[] = FORMAT;
    char string[sizeof(FORMAT)] = {0};

    printf("Enter date and time in the format of %s: ", format);

    // Read date and time from the terminal
    uint8_t i = 0;
    while (i < sizeof(FORMAT) - 1)
    {
        char chr = getchar();
        if ((chr == '\n') || (chr == EOF))
        {
            break;
        }
        string[i++] = chr;
    }

    bool status = true; // We assume that the format of entered date and time is OK

    i = 0;
    while (i < sizeof(FORMAT) - 1)
    {
        if (isalpha(format[i])) // If the character in format[i] is a letter, the character in string[i] shall be a digit
        {
            if (!isdigit(string[i]))
            {
                status = false;
                break;
            }
        }
        else
        {
            if (format[i] != string[i]) // If the character in format[i] is not a letter, we should have the same character in string[i]
            {
                status = false;
                break;
            }
        }
        i++;
    }

    if (status)
    {
        unsigned int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;

        // Extract year, month, day, hour, minute and second from the entered date and time
        if (6 != sscanf(string, "%04u-%02u-%02u %02u:%02u:%02u", &year, &month, &day, &hour, &minute, &second))
        {
            status = false;
        }
        else if ((year < YEAR_MIN) || (year > YEAR_MAX) ||
                 (month < MONTH_MIN) || (month > MONTH_MAX) || (day < DAY_MIN) ||
                 (hour > HOUR_MAX) || (minute > MINUTE_MAX) || (second > SECOND_MAX))
        {
            status = false;
        }
        else
        {
            uint8_t days[MONTH_MAX] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if (day > days[month - 1])
            {
                status = false;

                if (month == FEBRUARY)
                {
                    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) // If the year is a leap year
                    {
                        if (day == days[month - 1] + 1) // In february we can have 29 days
                        {
                            status = true;
                        }
                    }
                }
            }
        }
    }

    printf("The entered date and time is%s valid!\n", status ? "" : " not");

    return 0;
}
