/**
 * @file main.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example about preprocessor directives
 * @version 0.1
 * @date 2021-02-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>       // Include a standard library using < and >
#include "./lib/mylib.h" // Include a library developed by myself using double quotation marks

#ifndef BUFSIZE // Check if BUFSIZE has been defined or not
#error "The buffer size is not defined!" // If BUFSIZE is not defined the error message is printed to the terminal and the compilation is stopped
#endif // End of the conditional block

#define DEBUG // Define DEBUG as a macro

#define PI (3.1415) // Define PI as a macro. Macros can be used as constants

#define SQRX(x) ((x) * (x)) // A function like macro

// A Multi line macro
#define PRINT_MSG(msg) \
    {                  \
        printf(msg);   \
        printf("\n");  \
    }

#define AREA(r) (PI * (r) * (r)) // A macro can be used in another macro. PI is used to calculate the area of a circle.

#ifdef TEENSY
#define print_log(fmt, ...) Serial.printf(fmt, __VA_ARGS__); // A macro with a variable number of arguments.
#else
#define print_log(fmt, ...) printf(fmt, __VA_ARGS__); // A macro with a variable number of arguments.
#endif

// A macro with the stringify operator (#) and the spread operator (...).
// puts is defined in stdio.h and it is used to put a string to the terminal
#define print_args(...) puts(#__VA_ARGS__)

#define print_exp(exp) printf(#exp " = %f \n", (double)(exp)) // An example of the stringify operator

#define TEXT_A "Hello, world!"
#define TEXT_B "I Love Programming."
#define print_msg(x) puts(TEXT_##x) // A macro with the concatenation operator (##)

// An example of a type-generic macro
#define print(m) _Generic((m), \
                    double: print_double, \
                    int:    print_int, \
                    char*:  print_string, \
                    default: print_string)(m)

// And example of defined operator
#if defined(__unix__) && defined(__GNUC__)
/* ... */
#endif

         int
         main(void)
{
    // An example of conditional compilation
#ifdef DEBUG
    printf("A debug message\n");
#endif

    // Some predefined macros
    printf("Date: %s\n", __DATE__);
    printf("Function: %s\n", __func__);
    printf("Line Number: %d\n", __LINE__);

    // Using print_log as a macro with a variable number of arguments
    print_log("%d - %f\n", 10, 20.0f);
    print_log("%d - %f - %s\n", 10, 20.0f, "Test");

    // Using print_args to print the arguments to the terminal
    print_args(one\n, "2\n", three);

    // Using printEXP to print the expression and its result to the terminal
    print_exp(4 * 32 * 20);

    // Print BUFSIZE which is defined during compilation to the terminal
    printf("\nSize of the buffer: %d\n", BUFSIZE);

    // Using print_msg to print TEXT_A and TEXT_B
    // print_msg uses concatenation operator (##)
    print_msg(A);
    print_msg(B);

#define A 10 // Define A as 10

    printf("A = %d\n", A); // Print A which is 10 to the terminal

#undef A     // Undefine A
#define A 20 // Redefine A as 20

    printf("A = %d\n", A); // Print A which is 20 to the terminal

    // Using print as a type-generic macro
    print(5);       // 5 is an integer
    print(5.5);     // 5.5 is a double
    print("Hello"); // Hello is a string

// The right way to comment a block of code out
#if 0
    printf("................");
    printf("......ABCD......");
    printf("................");
#endif

    return 0;
}
