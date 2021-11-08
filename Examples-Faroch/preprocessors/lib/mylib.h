/**
 * @file mylib.h
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief A simple module
 * @version 0.1
 * @date 2021-02-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MY_LIB_H // Inclusion gard
#define MY_LIB_H

#define MYBUFSIZE 16 // The value shall be a multiple of 8

/**
 * @brief This function is used to print an integer to the output.
 * @param a The integer number to print to the output.
 */
void print_int(int a);

/**
 * @brief This function is used to print a double to the output.
 * @param a The double number to print to the output.
 */
void print_double(double a);

/**
 * @brief This function is used to print a string to the output.
 * @param s The string to print to the output.
 */
void print_string(char *s);

#endif /* MY_LIB_H */
