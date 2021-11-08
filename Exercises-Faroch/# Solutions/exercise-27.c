/**
 * @file exercise-27.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a function to find the largest value in an array of type int and a function to get the average of values in the array.
 *        Make another function to find a specific value in an array of type int. If the value exists in the array,
 *        the index of the value in the array shall be returned; otherwise -1.
 * @version 0.1
 * @date 2021-03-05
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>

#define ARRAY_LENGTH(a) (sizeof(a) / sizeof(a[0]))

static int largest(const int arr[], size_t len);
static float average(const int arr[], size_t len);
static int find(int val, const int arr[], size_t len);

int main(void)
{
    int array[] = {12, 34, 0, -3, 89, 45, 7};

    (void)printf("The largest value in the array is: %d\n", largest(array, ARRAY_LENGTH(array)));

    (void)printf("The average of the values in the array is: %f\n", average(array, ARRAY_LENGTH(array)));

    int value = 0;
    int index = find(value, array, ARRAY_LENGTH(array));
    if (index < 0)
    {
        (void)printf("%d does not exist in the array.\n", value);
    }
    else
    {
        (void)printf("Index of the element containing %d is %d.\n", value, index);
    }

    value = 100;
    index = find(value, array, ARRAY_LENGTH(array));
    if (index < 0)
    {
        (void)printf("%d does not exist in the array.\n", value);
    }
    else
    {
        (void)printf("Index of the element containing %d is %d.\n", value, index);
    }

    return 0;
}

static int largest(const int arr[], size_t len)
{
    int result = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (result < arr[i])
        {
            result = arr[i];
        }
    }
    return result;
}

static float average(const int arr[], size_t len)
{
    int result = 0;
    for (size_t i = 0; i < len; i++)
    {
        result += arr[i];
    }
    return ((float)result / len);
}

static int find(int val, const int arr[], size_t len)
{
    int result = -1;
    for (size_t i = 0; i < len; i++)
    {
        if (val == arr[i])
        {
            result = i;
            break;
        }
    }
    return result;
}
