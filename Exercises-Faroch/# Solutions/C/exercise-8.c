/**
 * @file expressions.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Evaluate the following program. What is the output of the program?
 * @version 0.1
 * @date 2021-02-19
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdint.h>

#define EXPRESSION (3 * j / k - 2)
#define SET_VARIABLES \
    {                 \
        i = 3;        \
        j = 2;        \
        k = 0;        \
    }

int main(void)
{
    int i = 0, j = 7, k = 6;
    char a = 'A', b = '3';
    int32_t x, y = 3;
    uint32_t z = 32;
    double d;

    /**
     * EXPRESSION is replaced by (3 * j / k - 2); j = 7, k = 6
     * First 3 * j is evaluated to 21 and then the result is divided by 6 => 21 / 6 = 3
     * Then 2 is subtacted from 3 which is 1. So the output of the expression is 1.
     */
    x = EXPRESSION;
    printf("A) %d\n", x);

    /**
     * y = 3, j = 7 and k = 6
     * (j << 1) = 7 x 2 = 14
     * (k >> 1) = 6 / 2 = 3
     * (14 & 3) = 00001110 & 00000011 = 00000010 = 2
     * y -= 2 => y = y - 2 => y = 3 -2 = 1
     */
    y -= ((j << 1) & (k >> 1));
    printf("B) %d\n", y);

    /**
     * b = '3' = 51 (look at the ASCII table),  i = 0, j = 7, k = 6
     * (i && k) = (0 && 6) = 0
     * !(i && k) = !0 = 1
     * !k = !6 = 0
     * (!(i && k) || !k) = (1 || 0) = 1 => k + b is assigned to x
     * x = k + b = 51 + 6 = 57
     */
    x = (!(i && k) || !k) ? k + b : j + b;
    printf("C) %d\n", x);

    /**
     * a = 'A' = 65, b = '3' = 51, k = 6
     * (b + k--) = (51 + 6) = 57; now the value of k is 5
     * (b + k--) % 10 = 57 % 10 = 7
     * a += 7 => a = a + 7 => a = 65 + 7 = 72
     */
    a += (b + k--) % 10;
    printf("D) %d\n", a);

    /**
     * j = 7, k = 5
     * --k: the value of k is 4
     * (double)j => j = 7.000000
     * j * 100 = 700.000000
     * 700.000000 / 4 = 175.000000
     * 175.000000 / 3 = 58.333333
     */
    d = (double)j * 100 / --k / 3;
    printf("E) %f\n", d);

    /**
     * a = 65, b = 51, i = 0, j = 7, k = 4, x = -1, z = 32
     * (x < z) => (-1 < 32U) = (0xFFFFFFFFU < 0x00000010U) = 0; Note that x is promoted to unsigned int.
     * So (b >= a < i) is evaluated and assigned to y.
     * b >= a: 51 >= 65 = 0
     * y = (0 < 0) = 0
     */
    x = -1;
    y = (x < z) ? (k < j < 0) : (b >= a < i);
    printf("F) %d\n", y);

    /**
     * x = -1, z = 32; x is promoted to unsigned int becasue z is an unsigned int => x = 4294967295
     * x / z = 4294967295 / 32 = 134 217 727
     */
    d = x / z;
    printf("G) %f\n", d);

    i = 4;
    j = -1;
    k = 0;

    x = i && j && k; // x = 4 && -1 && 0 = 1 && 0 = 0
    y = i || j && k; // y = 4 || -1 && k = 4 || (-1 && 0) = 4 || 0 = 1
    printf("H) %d, %d\n", x, y);

    x = i && j || k; // (4 && -1) || 0 = 1 || 0 = 1
    y = i || j || k; // 4 || -1 || 0 = 1 || 0 = 1
    printf("I) %d, %d\n", x, y);

    SET_VARIABLES;         // i = 3, j = 2, k = 0
    y = ++i || ++j && k++; // y = 4 || any number = 1; i is incremented but ++j and k++ are not executed
    printf("J) %d, %d, %d, %d\n", i, j, k, y);

    SET_VARIABLES;                // i = 3, j = 2, k = 0
    y = (123 && --i) ? k++ : ++k; // --i => i = 2; (123 && 2) = 1 => y = k++ is evaluated. y is 0 and k will be 1
    printf("K) %d, %d, %d, %d\n", i, j, k, y);

    SET_VARIABLES;         // i = 3, j = 2, k = 0
    y = ++i && ++j && k++; // ++i: i = 4; ++j: j = 3; y = (4 && 3 && k++) = (4 && 3 && 0) = 0 and k will be 1
    printf("L) %d, %d, %d, %d\n", i, j, k, y);

    i = 4;
    j = --i; // j is 3 and i will be 3
    k = i--; // k is 3 and i will be 2
    printf("M) %d, %d, %d\n", i, j, k);

    i = -1;
    j = 1;
    // Note that printf returns the number of written characters to the output.
    i &&printf("N) Hello World!\n") && --j; // The message is printed to the output and j will be 0.

    ++i &&j &&printf("O) Hello World!\n"); // i will be 0 => the rest of the expression is not executed.

    i || printf("P) Hello World!\n") || j++; // i is 0; the message is printed to the output and j++ is not executed

    j-- || !printf("Q) Hello World!\n") || i++; // j is 0 => printf is executed, and !printf is 0 and i++ is evaluted.
                                                // In the end i is 1 and j is -1

    printf("R) %d, %d\n", i, j);

    return 0;
}
