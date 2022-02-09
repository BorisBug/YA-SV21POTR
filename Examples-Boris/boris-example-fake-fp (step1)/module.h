#ifndef MODULE_H
#define MODULE_H

#include <stdbool.h>
#include <stdint.h>

// the important function of this module
bool module_get_uint32(uint32_t *pnumber);

// modifications to allow testing
typedef bool (*user_input_t)(char*, int);
void module_init(user_input_t user_input_function);

#endif
