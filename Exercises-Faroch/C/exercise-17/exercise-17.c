/**
 * @file exercise-17.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 17
 * @version 0.1
 * @date 2021-10-25
 */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/*
Beskrivning
Make a program to read a string from the standard input, 
then split the string by spaces as the delimiter and print them to the output. 

Example: 
The input string: I am  a C programmer

The output:
I
am
a
C
programmer
*/

int main()
{
    int c;
    bool spc = false;

    printf("Enter a text:\n");

    // stay in the loop until ENTER appears
    while ((c = getchar()) != '\n')
    {
        // if find the delimiter (space) make a new line
        if (isspace(c))
        {
            if(!spc) // no need for two consecutives..
                putchar('\n');
            spc = true;
        }
        // if not delimiter just echo
        else
        {
            spc = false;
            putchar(c);
        }
    }

    printf("\n");
    return 0;
}