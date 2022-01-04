/**
 * @file exercise-40.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a program to write “Hello World!” to a file 10 times and read it from the file and print it to the terminal.
 * @version 0.1
 * @date 2021-03-10
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define HELLO_WORLD "Hello World!\n"

int main(void)
{
    FILE *file = fopen("temp.txt", "w");

    if (file == NULL)
    {
        printf("Failed to open temp.txt\n");
        exit(1);
    }

    for (size_t i = 0; i < 10U; i++)
    {
        fwrite(HELLO_WORLD, sizeof(char), sizeof(HELLO_WORLD) - 1, file);
    }

    if (EOF == fclose(file))
    {
        printf("Failed to close temp.txt\n");
        exit(1);
    }

    file = fopen("temp.txt", "r");

    if (file == NULL)
    {
        printf("Failed to open temp.txt\n");
        exit(1);
    }

    for (size_t i = 0; i < 10U; i++)
    {
        char temp[sizeof(HELLO_WORLD)] = {0};
        fread(temp, sizeof(char), sizeof(HELLO_WORLD) - 1, file);
        printf("%s", temp);
    }

    if (EOF == fclose(file))
    {
        printf("Failed to close temp.txt\n");
        exit(1);
    }

    return 0;
}
