#include "stack.h"

static int top = -1;
static char stack[STACK_SIZE] = {0};

void stack_clear(void)
{
    top = -1;
}

bool stack_push(char ch)
{
    bool status = false;

    return status;
}

char stack_pop(void)
{
    char ch = '\0';

    return ch;
}
