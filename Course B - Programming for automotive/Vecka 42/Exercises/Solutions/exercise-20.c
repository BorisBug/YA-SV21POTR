/**
 * @file exercise-20.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to get a string as an argument from the command line, then convert
 *        the uppercase letters to lowercase and vice versa and in the end print the string to the standard output.
 *
 *        *** To change and print the string use only pointers ***
 *
 * @version 0.1
 * @date 2021-03-05
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        (void)printf("Invalid number of arguments. Enter a string as an argument\n");
        exit(1);
    }

    // Change the case of the letters
    for (char *cptr = *(argv + 1); *cptr != '\0'; cptr++)
    {
        *cptr = isupper(*cptr) ? tolower(*cptr) : toupper(*cptr);
    }

    (void)printf("The converted string: %s\n", *(argv + 1));

    return 0;
}
