#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdint.h>

#define MAX_NAME_SIZE 32

char get_command(void);
uint32_t get_user_id(void);
void get_user_name(char *name);

#endif
