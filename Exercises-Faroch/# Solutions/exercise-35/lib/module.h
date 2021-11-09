/**
 * @file module.h
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief A module to calculate the gcd and the lcm of two positive and non-zero numbers.
 *        a * b = gcd(a,b) * lcm(a, b); for a >= b
 *        For simplicity if a or b is zero, 0 is returned by both of the functions
 *        Examples:
 *               a = 12, b = 8 => gcd(12, 8) = 4 and lcm(12, 8) = 24
 * @version 0.1
 * @date 2021-03-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MODULE_H
#define MODULE_H

#include <math.h>
#include <stdint.h>

/**
 * @brief This function is used to calculate the gcd of two positive and non-zero numbers
 * 
 * @param m The first poisitive and non-zero number
 * @param n The second poisitive and non-zero number
 * @return uint32_t The gcd of m and n. 0 if m or n is zero.
 */
uint32_t get_gcd(uint32_t m, uint32_t n);

/**
 * @brief This function is used to calculate the lcm of two positive and non-zero numbers
 * 
 * @param m The first poisitive and non-zero number
 * @param n The second poisitive and non-zero number
 * @return uint32_t The gcd of m and n. 0 if m or n is zero.
 */
uint32_t get_lcm(uint32_t m, uint32_t n);

#endif /* MODULE_H */
