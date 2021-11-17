#include "module.h"

uint8_t get_digits(int num)
{
    int a = (num < 0) ? -num : num;
    return (a < 10) ? 1 : (1 + get_digits(a / 10));
}

float power(int base, int exp)
{
    int temp = (exp < 0) ? -exp : exp;
    float result = (exp == 0) ? 1 : (base * power(base, temp - 1));
    return (exp < 0) ? (1 / result) : result;
}
