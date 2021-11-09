#include "module.h"

// gcd(a,b) = (a * b) / lcm(a, b); Example: gcd(12, 8) = 4
uint32_t get_gcd(uint32_t m, uint32_t n)
{
    uint32_t gcd = 0;

    if ((m != 0) && (n != 0))
    {
        uint32_t minval = (m < n) ? m : n;

        for (uint32_t i = 1; i <= minval; i++)
        {
            if ((m % i == 0) && (n % i == 0))
            {
                gcd = i;
            }
        }
    }

    return gcd;
}

// lcm(a,b) = (a * b) / gcd(a, b); Example: lcm(12, 8) = 24
uint32_t get_lcm(uint32_t m, uint32_t n)
{
    uint32_t lcm = 0;

    if ((m != 0) && (n != 0))
    {
        lcm = (m > n) ? m : n;

        while ((lcm % m != 0) || (lcm % n != 0))
        {
            lcm++;
        }
    }

    return lcm;
}
