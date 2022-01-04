/**
 * @file typecasting.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of implicit and explicit type casting in C
 * @version 0.1
 * @date 2021-02-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>

int main(void)
{
    char a = 'A'; // The ASCII code of A is 65
    float b = 12.0f;
    double c = a + b; // Implicit type casting
    printf("c is %.20lf\n", c);

    unsigned int p = 48;
    (void)p; // We can discard an expression by converting it to void. i.e. (void) expression;

    int x = 300;
    char y = p; // Implicit type casting of int to char (Some part of the data is lost)
    printf("Y is %d\n", y);

    _Bool bl = 10; // 10 is converted to 1
    short int si = 20;

    // _Bool, unsigned/signed char and short int are implicitly converted to int
    printf("Size: %lu, Value: %d\n", sizeof(bl + si), bl + si);

    long int aa = 20;
    int bb = 3;
    float cc = (float)aa / bb; // If we want to do a floating-point division, we shall convert aa or bb to float
    printf("CC is %f\n", cc);

    return 0;
}
