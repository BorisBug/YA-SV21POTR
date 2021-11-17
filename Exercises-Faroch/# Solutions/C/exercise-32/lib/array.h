#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdbool.h>

typedef bool (*compare_t)(int, int);

void fill_array(int *arr, size_t len);

void print_array(const int *arr, size_t len);

void sort_array(int *arr, size_t len, compare_t compare);

#endif /* ARRAY_H */
