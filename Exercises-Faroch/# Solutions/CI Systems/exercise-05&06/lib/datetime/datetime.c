#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "datetime.h"

static bool check_format(const char *format, const char *str);
static bool check_time(const char *time);
static bool check_date(const char *time);

bool validate_datetime(const char *dtstr)
{
    bool status = false;

    if (dtstr != NULL)
    {
        switch (strlen(dtstr))
        {
        case (sizeof(TIME_FORMAT) - 1):
            status = check_format(TIME_FORMAT, dtstr) && check_time(dtstr);
            break;

        case (sizeof(DATE_FORMAT) - 1):
            status = check_format(DATE_FORMAT, dtstr) && check_date(dtstr);
            break;

        case (sizeof(DATETIME_FORMAT) - 1):
            status = check_format(DATETIME_FORMAT, dtstr) && check_date(dtstr) && check_time(dtstr + sizeof(DATE_FORMAT));
            break;

        default:
            break;
        }
    }

    return status;
}

static bool check_date(const char *time)
{
    bool status = false;
    uint32_t year = 0, month = 0, day = 0;

    if (3 == sscanf(time, "%04u-%02u-%02u", &year, &month, &day))
    {
        if ((month > 0) && (month < 13) && (day > 0) && (day < 32))
        {
            status = true;
            uint8_t days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if (day > days[month - 1])
            {
                status = false;

                if (month == 2)
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

    return status;
}

static bool check_time(const char *time)
{
    bool status = false;
    uint32_t hour = 0, minute = 0, second = 0;

    if (3 == sscanf(time, "%2u:%2u:%2u", &hour, &minute, &second))
    {
        if ((hour < 24) && (minute < 60) && (second < 60))
        {
            status = true;
        }
    }

    return status;
}

static bool check_format(const char *format, const char *str)
{
    size_t i = 0;
    bool status = true;
    size_t flen = strlen(format);
    while (i < flen)
    {
        if (isalpha(format[i])) // If the character in format[i] is a letter, the character in str[i] shall be a digit
        {
            if (!isdigit(str[i]))
            {
                status = false;
                break;
            }
        }
        else
        {
            if (format[i] != str[i]) // If the character in format[i] is not a letter, we should have the same character in str[i]
            {
                status = false;
                break;
            }
        }
        i++;
    }

    return status;
}
