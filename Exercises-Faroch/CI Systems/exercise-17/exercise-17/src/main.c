#include <stdio.h>
#include "expression.h"

#define ERROR_MESSAGE "Enter an expression as an argument!\n"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        (void)printf(ERROR_MESSAGE);
        exit(1);
    }

    if (expression_check(argv[1]))
    {
        (void)printf("%s is correctly parenthesized\n", argv[1]);
    }
    else
    {
        (void)printf("The expression is invalid\n");
    }

    return 0;
}
