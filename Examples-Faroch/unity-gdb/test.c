#include <unity.h>
#include "prime.h"

/**
 * @brief This function is called before running every test case to initialize the environment for the test case.
 *        For example if the module needs initialization or to start, we can do it in this function, 
 *        or reseting the required variables for the test case.
 */
void setUp(void) {}

/**
 * @brief This function is called after running every test case to cleanup the environment.
 *        For example if the module needs to free memory, to be stoped, or etc. we can do it in this function
 */
void tearDown(void) {}

/**
 * @brief This is a test case.
 *        In this test case we are going to check for prime numbers
 * 
 */
void test_prime_numbers(void)
{
    TEST_ASSERT_TRUE(isprime(2));
    TEST_ASSERT_TRUE(isprime(3));
    TEST_ASSERT_TRUE(isprime(23));
}

/**
 * @brief This is another test case.
 *        In this test case we are going to check for non-prime numbers
 * 
 */
void test_non_prime_numbers(void)
{
    TEST_ASSERT_FALSE(isprime(0));
    TEST_ASSERT_FALSE(isprime(1));
    TEST_ASSERT_FALSE(isprime(20));
    TEST_ASSERT_FALSE(isprime(1000));
}

int main(void)
{
    UNITY_BEGIN(); // Start Unity

    RUN_TEST(test_prime_numbers);     // Run test cases
    RUN_TEST(test_non_prime_numbers); // Run test cases

    return UNITY_END(); // End Unity
}
