/**
 * @file exercise-28.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a function to compare two strings. If they are equal, the function shall return 1; otherwise 0.
 * @version 0.1
 * @date 2021-03-05
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 20U

static bool compare(const char str1[], const char str2[]);

int main(void)
{
    char text1[MAX_LEN + 1] = "Hello";
    char text2[MAX_LEN + 1] = "Hello";

    (void)printf("%s and %s are%s equal!\n", text1, text2, compare(text1, text2) ? "" : " not");

    (void)strncpy(text1, "Text1", MAX_LEN);
    (void)strncpy(text2, "Text2", MAX_LEN);
    (void)printf("%s and %s are%s equal!\n", text1, text2, compare(text1, text2) ? "" : " not");

    return 0;
}

static bool compare(const char str1[], const char str2[])
{
    bool equal = true;
    size_t length = strlen(str1);

    if (length != strlen(str2))
    {
        equal = false;
    }
    else
    {
        for (size_t i = 0; i < length; i++)
        {
            if (str1[i] != str2[i])
            {
                equal = false;
                break;
            }
        }
    }

    return equal;
}
