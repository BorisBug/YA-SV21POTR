/**
 * @file exercise-30.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief 1) Create two pointers pa and pb to int a = 5; char b = 's';
 *        2) Change the values of a and b VIA the pointers.
 *        3) Create a function that takes a variable (pa above) as a parameter and add 5 to it.
 *        4) Create a function pointer to the following function with the name function_ptr and execute it.
 *                          void say_value(int a) { printf("Value of a is %d\n", a); }
 * @version 0.1
 * @date 2021-03-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>

static void say_value(int a)
{
    printf("The value is %d.\n", a);
}

static void add5(int *p)
{
    *p += 5;
}

int main(void)
{
    int a = 5;
    char b = 's';

    int *pa = &a;
    char *pb = &b;

    *pa = 10;
    *pb = 'A';

    void (*func_ptr)(int) = say_value;

    func_ptr(a);

    return 0;
}
