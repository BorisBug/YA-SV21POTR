/**
 * @file exercise-15.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to get a string from the standard input, then print the string to the output in reverse order.
 *        For examaple:
 *            Enter a string: ABCDEF
 *            Reversed string: FEDCBA
 * @version 0.1
 * @date 2021-02-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <string.h>

#define LENGTH 100

int main(void)
{
    char string[LENGTH] = {0};

    // Read the string from the standard input
    printf("Enter a string: ");
    fgets(string, LENGTH, stdin);
    string[strlen(string) - 1] = '\0'; // fgets captures the newline also and we don't want to have it in the string

    // Reverse the string
    int left = 0, right = strlen(string) - 1;
    while (left < right)
    {
        char temp = string[left];
        string[left] = string[right];
        string[right] = temp;

        right--;
        left++;
    }

    // Print the reversed string to the output
    printf("Enter a string: %s\n", string);

    return 0;
}
