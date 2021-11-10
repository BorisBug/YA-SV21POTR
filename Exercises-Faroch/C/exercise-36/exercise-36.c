/**
 * @file exercise-36.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 36
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include "unity.h"


/*
Beskrivning
Make a function to count the digits of a given number using recursion. E.g. 456 has 3 digits
Make a function to calculate X power Y; i.e (XY ) using recursion. E.g. 2^3 = 8. X and Y are two integers.
Using unity test the functions.
*/


unsigned digits(int x)
{
    if(x<0) x=-x;
    return x<10 ? 1 : 1 + digits(x/10);
}

float power(int x, int pow)
{
    float p = pow>=0 ? pow : -pow; 
    float res = (pow==0 ? 1 : (x * (p>1 ? power(x, p-1) : 1)));
    return pow<0 ? 1/res : res;
}

/*
void test_function() {TEST_ASSERT_TRUE(1);}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_function);
	return UNITY_END();
}
*/

void test_digits_pass()
{
    TEST_ASSERT_EQUAL_UINT8(2,digits(10));
    TEST_ASSERT_EQUAL_UINT8(2,digits(-10));
    TEST_ASSERT_EQUAL_UINT8(9,digits(123456789));

    TEST_ASSERT_NOT_EQUAL_UINT8(2,digits(1));
    TEST_ASSERT_NOT_EQUAL_UINT8(4,digits(-123));
    TEST_ASSERT_NOT_EQUAL_UINT8(3,digits(543210));
}

void test_power_pass()
{
    TEST_ASSERT_EQUAL_FLOAT(8,power(2,3));
    TEST_ASSERT_EQUAL_FLOAT(-8, power(-2,3));
    TEST_ASSERT_EQUAL_FLOAT(10000, power(10,4));
    TEST_ASSERT_EQUAL_FLOAT(0.00032, power(5,-5));
    TEST_ASSERT_FLOAT_WITHIN(0.000001, 0.000059, power(7, -5));
}


int main()
{
    /*
    int x=0, y=0;

    printf("Enter a number: ");
    scanf("%d", &x);
    printf("The number %d has %u digits\n", x, digits(x));

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("The result of %d^%d is %u\n", x, y, power(x, y));
    */

    UNITY_BEGIN();
	RUN_TEST(test_digits_pass);
	RUN_TEST(test_power_pass);
	return UNITY_END();
}