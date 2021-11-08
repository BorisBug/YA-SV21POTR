/**
 * @file exercise-28.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 28
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <string.h>

/*
Beskrivning
Make a function to compare two strings.
If they are equal, the function shall return 1; otherwise 0.
*/

int string_equal(const char* s1, const char* s2)
{
    while(*s1==*s2 && *s1)
        s1++, s2++;

    return *s1 == *s2;
}

int main()
{
    printf("Compare strings:\n");

    const char *s1, *s2;
    
    s1 = "abc";
    s2 = "abc";
    printf("\"%s\" vs \"%s\" = %d\n", s1, s2, string_equal(s1, s2));

    s1 = "ABC";
    s2 = s1;
    printf("\"%s\" vs \"%s\" = %d\n", s1, s2, string_equal(s1, s2));

    s1 = "ABC";
    s2 = "def";
    printf("\"%s\" vs \"%s\" = %d\n", s1, s2, string_equal(s1, s2));

    s1 = "Juan Perez";
    s2 = "Sebastian Pier";
    printf("\"%s\" vs \"%s\" = %d\n", s1, s2, string_equal(s1, s2));

    return 0;
}