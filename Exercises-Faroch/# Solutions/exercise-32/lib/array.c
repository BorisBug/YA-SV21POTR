#include <time.h>
#include "array.h"
#include <stdlib.h>

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_array(int *arr, size_t len, compare_t compare)
{
    for (int *iptr = arr; (iptr - arr) < len; iptr++)
    {
        for (int *jptr = iptr + 1; (jptr - arr) < len; jptr++)
        {
            if (compare(*iptr, *jptr))
            {
                swap(iptr, jptr);
            }
        }
    }
}

void print_array(const int *arr, size_t len)
{
    int *iptr = (int *)arr;

    (void)printf("{");
    while ((iptr - arr) < (len - 1))
    {
        (void)printf("%d, ", *iptr++);
    }
    (void)printf("%d}\n", *iptr);
}

void fill_array(int *arr, size_t len)
{
    srand(time(NULL));

    for (int *iptr = arr; (iptr - arr) < len; iptr++)
    {
        *iptr = rand() % 100;
    }
}
