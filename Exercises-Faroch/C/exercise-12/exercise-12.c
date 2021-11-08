/**
 * @file exercise-12.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 12
 * @version 0.1
 * @date 2021-10-25
 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

/*
Beskrivning
Make a program to read the full name of the user character by character from the standard input.
The program shall filter, capitalize and then print it out to the standard output (terminal). 
The filtered name can only contain one space between parts of the name and uppercase/lowercase letters.

Use getchar and putchar functions in stdio.h and character handling functions like toupper, tolower,
isspace and etc. in ctype.h
*/

int main()
{
    int c;
    bool inside = false;

    printf("Enter your full name:\n");

    // stay in the loop until ENTER appears
    while((c=getchar())!='\n')
    {
        // use if alpha
        if(isalpha(c))
        {
            // if inside of text, use lower
            if(inside)
            {
                putchar(tolower(c));
            }
            // if starting a text, use upper (capitalize)
            else
            {
                inside = true;
                putchar(toupper(c));
            }
        }
        // if not alpha, but it was alpha before..
        else if (inside)
        {
            // close text
            inside = false;
            putchar(' ');
        }
    }

    printf("\n");
    return 0;
}