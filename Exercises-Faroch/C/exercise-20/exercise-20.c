/**
 * @file exercise-20.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 20
 * @version 0.1
 * @date 2021-10-25
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Beskrivning
Make a program to get a string as an argument from the command line,
then convert the uppercase letters to lowercase and vice versa and in
the end print the string to the standard output.

To change and print the string use only pointers.
*/

char* toggle(char *str)
{
    for(char *p=str; p && *p; p++)
        if(isalpha(*p))
            *p = isupper(*p) ? tolower(*p) : toupper(*p);

    return str;
}

int main(int argc, char *argv[])
{
    printf("Argument count: %d\n\n", argc);
    
    for(int i=0; i<argc; i++)
    {
        printf("Argument value[%d]: %s\n", i, argv[i]);
        printf("Argument toggled:  %s\n\n", toggle(argv[i]));
    }

    return 0;
}