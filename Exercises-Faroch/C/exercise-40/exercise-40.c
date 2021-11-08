/**
 * @file exercise-40.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 40
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>


/*
Beskrivning
Make a program to write “Hello World!” to a file 10 times and
read it from the file and print it to the terminal.
*/
 
int main(void)
{
    // open the file
    const char *filename = "hello.txt";
    printf("\nA) Opening file for writing & reading: %s\n", filename);
    FILE *file = fopen(filename, "w+");

    if(!file)
    {
        printf("Not possible to open the file :(\n");
        return 1;
    }

    // write data 10 times
    const char *data = "Hello World!";
    printf("\nB) Writing \"%s\" 10 times\n", data);
    for(int i=0; i<10; i++)
    {
        fprintf(file, "%s\n", data);
        printf("..%d) %s\n", i+1, data);
    }

    // read the content of the file
    char line[50];
    printf("\nC) Reading\n");
    fseek(file, 0, SEEK_SET); // go to the begining of the file
    for(int i=0; i<10; i++)
    {
        fgets(line, sizeof(line), file);
        printf("..%d) %s", i+1, line); // note that i am not adding the "\n" since it is included in the fgets
    }

    fclose(file);

    return 0;
}