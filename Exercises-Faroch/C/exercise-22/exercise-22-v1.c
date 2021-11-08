/**
 * @file exercise-22-v1.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 22 - parse and build data
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

/*
Same logic as exercise-18 but now modified to act on a string 
*/

#define SHOW_LOG 1

typedef struct DATETIME
{
    unsigned int  year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char min;
    unsigned char sec;
} datetime_t;

// Levels for the parser
typedef enum LEVEL
{
    L_YYYY = 0,
    L_MM,
    L_DD,
    L_HH,
    L_mm,
    L_ss,
    L_OK,
} level_t;

const char *LVL_NAME[] = {
    "year",
    "month",
    "day",
    "hour",
    "minutes",
    "seconds",
    "ok",
};

bool verify_digits_n(level_t level, unsigned number, unsigned digits, unsigned amount)
{
    // here we dceide if we want EXACT amount of digits or between [1 - amount]
    if(digits>=1 && digits<=amount)
    //if(digits==amount)
        return true;

    #if SHOW_LOG
    char fmt[10], num[10];
    sprintf(fmt, "%c%0dd", '%',amount);
    sprintf(num, fmt, number);
    printf("..level %d error -> %s: expected %d digits (inserted %d digits on number %s)\n", level, LVL_NAME[level], amount, digits, num);
    #endif

    return false;
}

// Simple digits verification
bool verify_digits(level_t level, unsigned number, unsigned digits)
{
    switch(level)
    {
    case L_YYYY:
        return verify_digits_n(level, number, digits, 4);

    case L_MM: case L_DD: 
    case L_HH: case L_mm: case L_ss:
        return verify_digits_n(level, number, digits, 2);

    case L_OK:
        return true;
    }

    return false;
}

bool verify_range_n(level_t level, unsigned number, unsigned n1, unsigned n2)
{
    if(number>=n1 && number<=n2)
        return true;

    #if SHOW_LOG
    printf("..level %d error -> %s: expected range %d-%d for number %d\n", level, LVL_NAME[level], n1, n2, number);
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

// Simple range verification
bool verify_range(level_t level, unsigned number, const datetime_t *dt)
{
    switch (level)
    {
    case L_YYYY:
        return verify_range_n(level, number, 0, 9999);

    case L_MM: // 1-12
        return verify_range_n(level, number, 1, 12);

    case L_DD: // 1-31 (or 30,29,28)
        return verify_range_n(level, number, 1, get_month_days(dt->year, dt->month));

    case L_HH: // 0-23
        return verify_range_n(level, number, 0, 23);

    case L_mm: // 0-59
    case L_ss:
        return verify_range_n(level, number, 0, 59);

    case L_OK:
        return true;
    }

    return false;
}

bool verify_delimiter_n(level_t level, char c, char *valid, unsigned number)
{
    // we take the NULL as a valid delimiter for DD && mm
    // if so, the result should be a warning (truncated parsing)
    if(c==0 && (level==L_DD || level==L_mm))
        return true;

    // the other cases should fit in the format
    if(strchr(valid, c))
        return true;

    #if SHOW_LOG
    printf("..error: expected %s delimiter '%s' after number %d\n", LVL_NAME[level], valid, number);
    #endif

    return false;
}

// Simple verification
// issue: it is ok to use '/' or '.' as delimiter in between of year-month-day ?
bool verify_delim(level_t level, char delim, unsigned number)
{
    switch (level)
    {
    case L_YYYY:
    case L_MM:
        return verify_delimiter_n(level, delim, "-", number);

    case L_DD:
        return verify_delimiter_n(level, delim, " ", number);

    case L_HH:
        return verify_delimiter_n(level, delim, ":", number);

    case L_mm:
        return verify_delimiter_n(level, delim, ": ", number); // space is valid

    case L_ss:
        return verify_delimiter_n(level, delim, " ", number);

    case L_OK:
        return true;
    }

    return false;
}

bool set_datetime_value(level_t level, datetime_t *dt, unsigned number)
{
    assert(verify_range(level, number, dt));

    switch (level)
    {
    case L_YYYY: dt->year = number; return true;
    case L_MM: dt->month = number; return true;
    case L_DD: dt->day = number; return true;
    case L_HH: dt->hour = number; return true;
    case L_mm: dt->min = number; return true;
    case L_ss: dt->sec = number; return true;
    case L_OK: return true;
    }

    return false;
}

// Simple verification
// issue: is it OK to have date only (without time) ?
// issue: is it OK to have time only (without date) ?
// issue: is it OK to have time without seconds ?
// --> for the sake of simplicity we validate TRUE only with a complete FULL FORMAT

bool parse_dt(datetime_t *dt, const char* str)
{
    assert(str);

    bool error = false;
    unsigned c, number=0, digits=0;
    level_t level = L_YYYY;
    int len = strlen(str);

    // trim right
    while(str[len-1]==' ')
        len--;

    // trim left
    while(*str==' ')
        str++, len--;

    #if SHOW_LOG
    char tmp[50];
    strcpy(tmp, str);
    tmp[len] = 0;
    printf("Parsing: %s\n", tmp);
    #endif

    // note the i<=len (i use the null as a delimiter)
    for(int i=0; level!=L_OK && i<=len; i++)
    {
        c = i==len ? ' ' : str[i];

        // if is digit
        if (isdigit(c))
        {
            // build the number
            digits++;
            number = number*10 + c - '0'; // shift left 1 digit and add the new digit to the right
        }
        // if is not a digit, it should be a delimiter
        else 
        // but first verify the value of the number
        if (verify_digits(level, number, digits) &&   // verify amount of digits
            verify_range(level, number, dt))  // verify range of the number
        {
            #if SHOW_LOG
            // show internal information after verification: OK bla bla..
            printf("..level %d OK (%s: %d)\n", level, LVL_NAME[level], number);
            #endif

            // update the result DT structure
            set_datetime_value(level, dt, number);

            // and now verify if delimiter is the correct for the level
            if(verify_delim(level, c, number))
            {
                // prepare to build a new number
                number = 0;
                digits = 0;
                // increment to next level
                level++;
            }
            else
            {
                // error ..bye bye!
                error = true;
                break;
            }
        }
        // if not valid
        else
        {
            // error ..bye bye!
            error = true;
            break;
        }
    }

    // no error.. but warning?
    if(!error)
    {
        // missing TIME
        if(level == L_HH)
        {
            #if SHOW_LOG
            printf("..level %d warning -> parsing truncated, missing values for TIME\n", level);
            #endif
            return true;
        }
        else // missing SECONDS
        if(level == L_ss)
        {
            #if SHOW_LOG
            printf("..level %d warning -> parsing truncated, missing value for SECONDS\n", level);
            #endif
            return true;
        }
    }

    return level == L_OK;
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
    test_dt("1975-02-12 23:61:"); // error: minutes range
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