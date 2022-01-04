/**
 * @file main.c 
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example code about identifiers and scope of identifiers
 * @version 0.1
 * @date 2021-02-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Include standar IO library which contains functions to work with the standard IO
#include <stdio.h>

// Global scope
// Identifiers begin with an underscore and not followed by an uppercase letter are reserved as identifiers with file scope.
int _a12 = 0;        // An invalid identifier
float _func_a(void); // An invalid identifier

// File scope
// Identifiers begin with an underscore and not followed by an uppercase letter are reserved as identifiers with file scope.
static double _temp = 12.0; // A valid identifier
static char _func_b(void);  // A valid identifier

// Function parameter
// Identifiers begin with an underscore and not followed by an uppercase letter can be used as function parameters name.
float funct_c(char _a); // _a is a valid identifier

float scanf(void); // scanf is an identifier in stdio.h and it can not be used

int my_func(float a, double b); // my_func, a and b are valid

int main(void)
{
    // Some invalid identifiers
    int double = 0.0; // double is a reserved keyword and it must not be used as an identifier

    char my - name = 'c';  // An invalid identifier
    float y / x = 0.0f;    // An invalid identifier
    float 2_values = 0.0f; // Identifiers must not start with a digit

    int temp_value = 0;  // A valid identifier
    int value = 0;       // A valid identifier
    printf("%d", Value); // Value is undefined. Identifiers in C are case-sensitive

    int __LINE__ = 0, __x = 0; // Identifiers begin with two underlines are reserved and shall not be used
    int _Max = 0;              // Identifiers begin with an underline and followed by a capital letter are reserved and shall not be used

    return 0;
}
