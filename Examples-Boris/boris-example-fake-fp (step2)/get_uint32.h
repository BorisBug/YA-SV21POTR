#ifndef GET_UINT32_H
#define GET_UINT32_H

#include <stdbool.h>
#include <stdint.h>

// the important function of this module
bool get_uint32(uint32_t *pnumber);

// modifications to allow testing
typedef bool (*user_input_t)(char*, int);
void get_uint32_init(user_input_t user_input_function);

#endif
