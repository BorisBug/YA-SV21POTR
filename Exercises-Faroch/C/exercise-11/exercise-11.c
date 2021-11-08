/**
 * @file exercise-11.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 11
 * @version 0.1
 * @date 2021-10-25
 */
#include <stdio.h>
#include <stdint.h>

/*
Beskrivning
Make a program to read a number in the range of 0 and 255 from
the standard input using the scanf function in stdio.h and print
the binary form of the number to the output. While the enetered
number is not in the range, the program shall ask for a new number.
*/

#define MIN_VAL 0
#define MAX_VAL 255

void print_uint8(unsigned char b)
{
    // shift left & print most significant bit (first left)
    for (int i = 0; i < 8; i++, b <<= 1)
        printf("%c", (b & 0x80) ? '1' : '0');
}

int main()
{
    int x = 0, r = 0;

    // ask for a number in range 0-255 (MIN_VAL - MAX_VAL)
    do
    {
        printf("Enter a number [%d-%d]: ", MIN_VAL, MAX_VAL);
        r = scanf("%d", &x);
        fflush(stdin);

        if (r <= 0)
            printf("That was not a number.. try again!\n");
        else if (x < MIN_VAL || x > MAX_VAL)
            printf("Number not in range.. try again!\n");
    }
    while (r==0 || x<MIN_VAL || x>MAX_VAL);

    // print the binary representation
    printf("Binary representation of %d (0x%X) is : ", x, x);
    print_uint8(x);
    printf("\n");
    
    return 0;
}