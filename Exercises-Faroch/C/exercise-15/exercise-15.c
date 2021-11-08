/**
 * @file exercise-15.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 15
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <string.h>

/*
Beskrivning
Make a program to get a string from the standard input,
then print the string to the output in reverse order.

For examaple:
Enter a string: ABCDEF
Reversed string: FEDCBA
*/

#define ARR_SIZE 255

int main()
{
    char str[ARR_SIZE];

    // get the text
    printf("Enter a text:\n");
    fgets(str, ARR_SIZE, stdin);    // I use fgets just for the sake of simplicity.
    int len = strlen(str);          // ..the focus is on reversing!
    str[--len] = 0;

    // reverse the text
    for(int i=0; i<len/2; i++)
    {
        char c = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = c;
        printf("..swap [%d]='%c' with [%d]='%c' -> %s\n", i, str[i], len-i-1, str[len-i-1], str);
    }

    // print result
    printf("Reversed:\n%s\n", str);
    return 0;
}