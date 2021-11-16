#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_SIZE 100

void stack_clear(void);
bool stack_push(char ch);
char stack_pop(void);

#endif /* STACK_H */
