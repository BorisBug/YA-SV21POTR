/**
 * @file scope.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of identifiers scope
 * @version 0.1
 * @date 2021-02-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>

/**
 * @brief The scope of an identifier generally begins after its declaration.
 * Exeptions: Tag names of structures, unions, enums, and constants in enums
 */

int value = 2; // value is a global variable and after its declaration it is accessible everywhere

struct person // person is a structure tag name
{
    int age;
    char *name;
};
static struct person me; // This is a valid variable and it's scope is this file

// This is the func prototype. _a and _b have function prototype scope and even they can be omitted.
// It can be written: void func(int, int)
void func(int a, int b);

void func(int x, int y) // The scope of x and y is func and they can be used in the body of func
{
    int m = x * y; // The scope of m is the body of func and it can not be used out of this function

    int temp = 0;

// The scope of start and end is this function
start:
    printf("%d\n", m);
    if (temp > 0)
        goto end;

    {
        temp = 1;
        int a = 0; // The scope of a is this block and it is not accessible out of this block
        goto start;
    }

end:
    printf("end");
}

int main(void)
{
    me.age = 40;

    value = 5; // value can be used everywhere

    int val_a = 0; // The scope of val_a is the main function and out of main it is not accessible

    if (1)
    {
        val_a = 10;
        float fval = 0.0f; // The scope of fval is this block and out of this block, fval is not valid
    }

    func(1, 2);

    return 0;
}
