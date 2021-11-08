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
    return x<10 ? 1 : 1 + digits(x/10);
}

unsigned power(int x, int pow)
{
    return x * (pow>1 ? power(x, pow-1) : 1);
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
    TEST_ASSERT_TRUE(digits(10)==2);
    TEST_ASSERT_TRUE(digits(123456789)==9);

    TEST_ASSERT_FALSE(digits(1)==2);
    TEST_ASSERT_FALSE(digits(543210)==3);
}

void test_power_pass()
{
    TEST_ASSERT_TRUE(power(2,3)==8);
    TEST_ASSERT_TRUE(power(10,4)==10000);

    TEST_ASSERT_FALSE(power(2,32)==255);
    TEST_ASSERT_FALSE(power(99,3)==25);
}

void test_digits_fail()
{
    TEST_ASSERT_TRUE(digits(100)==4);
    TEST_ASSERT_TRUE(digits(12345)==3);

    TEST_ASSERT_FALSE(digits(1000)==3);
    TEST_ASSERT_FALSE(digits(33)==3);
}

void test_power_fail()
{
    TEST_ASSERT_TRUE(power(12,2)==100);
    TEST_ASSERT_FALSE(power(12,2)==144);
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
	RUN_TEST(test_digits_fail);
	RUN_TEST(test_power_fail);
	return UNITY_END();
}