/**
 * @file module.h
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief A module to count number of digits in a given integer number and calculate the power of any integer number using recursion.
 * 
 * @version 0.1
 * @date 2021-03-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MODULE_H
#define MODULE_H

#include <stdint.h>

uint8_t get_digits(int num);

float power(int base, int exp);

#endif /* MODULE_H */
