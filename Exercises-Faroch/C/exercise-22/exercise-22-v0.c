/**
 * @file exercise-22-v0.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 22 - use "scanf" standard function
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

/*
Beskrivning
Make a program to read date time in the format of YYYY-MM-DD HH:mm:ss from the input and validate it.
A leap year is exactly divisible by 4 except for century years (years ending with 00).
The century year is a leap year only if it is perfectly divisible by 400. 
If the year is a leap year, then February 29, is the leap day.
*/

#define SHOW_LOG 1

typedef struct DATETIME
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int min;
    unsigned int sec;
} datetime_t;

// Calculate the amount of days in a month
int get_month_days(unsigned short year, unsigned char month)
{
    switch (month)
    {
    //case 1:case 3:case 5:case 7:case 8:case 10:case 12:
    default:
        return 31; 
    case 4:case 6:case 9:case 11:
        return 30;
    case 2:
        if(year%400==0 || (year%4==0 && year%100!=0))
            return 29;
        return 28;
    }

    return 0;
}

bool verify_range_n(const char *name, unsigned number, unsigned n1, unsigned n2)
{
    if (number >= n1 && number <= n2)
        return true;

    #if SHOW_LOG
    printf("..error -> %s: expected range %d-%d for number %d\n", name, n1, n2, number);
    #endif
    
    return false;
}

// Simple range verification
bool verify_ranges(const datetime_t *dt)
{
    bool error = false;
    printf("Validating: %u-%02u-%02u %02d:%02d:%02d\n",
                dt->year, dt->month, dt->day, dt->hour, dt->min, dt->sec);

    error |= !verify_range_n("year", dt->year, 0, 9999);
    error |= !verify_range_n("month", dt->month, 1, 12);
    error |= !verify_range_n("day", dt->day, 1, get_month_days(dt->year, dt->month));
    error |= !verify_range_n("hour", dt->hour, 0, 59);
    error |= !verify_range_n("minutes", dt->min, 0, 59);
    error |= !verify_range_n("seconds", dt->sec, 0, 59);
    return !error;
}


int main()
{
    datetime_t dt = {0};
    int res;

    printf("Enter date and time [YYYY-MM-DD HH:mm:ss]:\n");
    res = scanf("%4d-%2d-%2d %2d:%2d:%2d", &dt.year, &dt.month, &dt.day, &dt.hour, &dt.min, &dt.sec);

    if (res==6 && verify_ranges(&dt))
        printf("The format is valid\n");
    else
        printf("Format not valid\n");

    return 0;
}