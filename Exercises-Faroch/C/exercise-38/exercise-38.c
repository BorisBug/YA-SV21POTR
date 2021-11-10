/**
 * @file exercise-38.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 38
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <ctype.h>
#include "unity.h"

/*
Beskrivning
Make a function to read a string of max. length N from the standard input using the getchar function.
Make another function to sort the string in alphabetical order. Using unity test the sort function.
*/

int get_string(char *str, unsigned size)
{
    char c;
    int i = 0;
    while ((c=getchar())!='\n' && c!='\0' && i<size-1)
        *str=c, str++, i++;

    *str = 0;
    return i;
}

unsigned string_len(char *str)
{
    unsigned i = 0;
    if(str) while(str[i]) i++;
    return i;
}

void sort_string(char *str)
{
    int len = string_len(str);

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            char a = toupper(str[i]);
            char b = toupper(str[i]);

            if((a>b) || (a==b && str[i]>str[j]))
            {
                char c = str[i];
                str[i] = str[j];
                str[j] = c;
            }
        }
    }
}

void sort_string_2(int len, char str[len])
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            char a = toupper(str[i]);
            char b = toupper(str[i]);

            if((a>b) || (a==b && str[i]>str[j]))
            {
                char c = str[i];
                str[i] = str[j];
                str[j] = c;
            }
        }
    }
}

void test_sort()
{
    char test[30]="KJFBELHINCMGAD";
    sort_string(test);
    TEST_ASSERT_EQUAL_STRING("ABCDEFGHIJKLMN", test);
}

int main()
{
    char str[20];
    printf("Enter a string: ");
    get_string(str, 20);
    printf("Echo: %s\n", str);
    sort_string(str);
    //sort_string_2(string_len(str), str);
    printf("Sort: %s\n", str);

    UNITY_BEGIN();
	RUN_TEST(test_sort);
	return UNITY_END();
}
