/**
 * @file exercise-22-v2.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 22 - use "strtol" standard function
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

/*
Beskrivning
Make a program to read date time in the format of YYYY-MM-DD HH:mm:ss from the input and validate it.
A leap year is exactly divisible by 4 except for century years (years ending with 00).
The century year is a leap year only if it is perfectly divisible by 400. 
If the year is a leap year, then February 29, is the leap day.
*/

/*
Same logic as exercise-18 but now modified to act on a string 
*/

#define SHOW_LOG 1

#define STR_YY "year"
#define STR_MM "month"
#define STR_DD "day"
#define STR_HH "hour"
#define STR_mm "minutes"
#define STR_ss "seconds"

typedef struct
{
    unsigned int  year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char min;
    unsigned char sec;
} datetime_t;

bool verify_range_n(const char *name, unsigned number, unsigned n1, unsigned n2)
{
    if(number>=n1 && number<=n2)
        return true;

    #if SHOW_LOG
    printf("..error -> %s: expected range %d-%d for number %d\n", name, n1, n2, number);
    #endif
    
    return false;
}

// Calculate the amount of days in a month
int get_month_days(unsigned short year, unsigned char month)
{
    switch (month)
    {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        return 31; 
    case 4:case 6:case 9:case 11:
        return 30;
    case 2:
        if(year%400==0 || (year%4==0 && year%100!=0))	
			return 29;
        return 28;
    }

    assert(0);
    return 0;
}

// Simple verification
// issue: is it OK to have date only (without time) ?
// issue: is it OK to have time only (without date) ?
// issue: is it OK to have time without seconds ?
// --> for the sake of simplicity we validate TRUE only with a complete FULL FORMAT

void print_error_delim(const char *err, const char *delim, const char *name)
{
    printf("..%s: expecting delimiter '%s' after %s\n", err, delim, name);
}

bool parse_dt(datetime_t *dt, const char* str)
{
    assert(str);
    char *next = "";

    printf("Testing: %s\n", str);

    // year ///////////////
    dt->year = strtol(str, &next, 10);
    if(!verify_range_n(STR_YY, dt->year, 0, 9999))
        return false;

    if(next[0]!='-')
    {   
        print_error_delim("error", "-", STR_YY);
        return false;
    }

    // month ///////////////
    dt->month = strtol(++next, &next, 10);
    if(!verify_range_n(STR_MM, dt->month, 1, 12))
        return false;

    if(next[0]!='-')
    {   
        print_error_delim("error", "-", STR_MM);
        return false;
    }

    // day ///////////////
    dt->day = strtol(++next, &next, 10);
    if(!verify_range_n(STR_DD, dt->day, 1, get_month_days(dt->year, dt->month)))
        return false;

    if(next[0]!=' ')
    {
        // truncated (only DATE info)
        if(next[0]==0)
        {
            print_error_delim("warning", " ", STR_DD);
            return true;
        }

        print_error_delim("error", " ", STR_DD);
        return false;
    }

    // hour ///////////////
    dt->hour = strtol(++next, &next, 10);
    if(!verify_range_n(STR_HH, dt->hour, 0, 23))
        return false;

    if(next[0]!=':')
    {
        print_error_delim("error", ":", STR_HH);
        return false;
    }

    // minutes ///////////////
    dt->min = strtol(++next, &next, 10);
    if(!verify_range_n(STR_mm, dt->min, 0, 59))
        return false;

    if(next[0]!=':')
    {
        // truncated (missing ss info)
        if(next[0]==0)
        {
            print_error_delim("warning", ":", STR_mm);
            return true;
        }

        print_error_delim("error", ":", STR_mm);
        return false;
    }

    // seconds ///////////////
    dt->sec = strtol(++next, &next, 10);
    if(!verify_range_n(STR_ss, dt->sec, 0, 59))
        return false;

    if(next[0]!='\0')
    {
        print_error_delim("error", "end of string", STR_ss);
        return false;
    }

    return true;
}

void test_dt(const char *str)
{
    datetime_t dt = {0};

    if(parse_dt(&dt,str))
    {
        printf("The format is valid!\n");
        printf("Result after parsing: %u-%02u-%02u %02d:%02d:%02d\n\n",
                dt.year, dt.month, dt.day, dt.hour, dt.min, dt.sec);
    }
    else
        printf("Format not valid\n\n");
}

void test()
{
    printf("\n\n\n\n\n");
    test_dt("1975-02-12 10:15:35"); // ok
    test_dt("1975-02-12 10:15"); // ok truncated
    test_dt("1975-02-12"); // ok truncated
    test_dt("1975-02-121"); // error: day digit
    test_dt("1975-02-29"); // error: day range (february)
    test_dt("1975-02-12 23"); // error: expecting delimiter
    test_dt("1975-02-12 23:61"); // error: minutes range
    test_dt("1975-02-12 23:49:"); // ok (assume 0 seconds)
    test_dt("1975-02-12 23:59:61"); // error: seconds range
    test_dt("75-2-7 1:15:5"); // ok
}

int main()
{
    test();
    /*
    datetime_t dt = {0};
    printf("Enter date and time [YYYY-MM-DD HH:mm:ss]:\n");

    char str[200];
    fgets(str, 200, stdin);
    str[strlen(str)-1] = 0;

    test_dt(str);
    */
    return 0;
}