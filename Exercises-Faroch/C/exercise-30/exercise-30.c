/**
 * @file exercise-30.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 30
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>

/*
Beskrivning
1) Create two pointers pa and pb to int a = 5; char b = ’s’;
2) Change values of a and b VIA the pointers
3) Create a function that takes a variabel (pa above) as a parameter and add 5 to it.
4) Create a function pointer, funcptr, to the following function and execute it.
*/

// 3) Create a function that takes a variabel (pa above) as a parameter and add 5 to it.
void my_function(int *p)
{
    *p += 5;
}

void say_value(int a)
{
    printf("Value of a is %d\n", a);
}

int main()
{
// 1) Create two pointers pa and pb to int a = 5; char b = ’s’;
    int a = 5;
    char b = 's';

    int *pa = &a;
    char *pb = &b;
    printf("Original values: a=%i b='%c'\n", a, b);

// 2) Change values of a and b VIA the pointers
    *pa = 50;
    *pb = 'X';
    printf("After using pointer.. a=%i b='%c'\n", a, b);

// 3) Create a function that takes a variabel (pa above) as a parameter and add 5 to it.
    my_function(pa);
    printf("After my_function.. a=%i\n", a);

// 4) Create a function pointer, funcptr, to the following function and execute it.
    void (*ptr_function)(int) = say_value; // declare & initialize
    ptr_function(a); // execute

    return 0;
}
