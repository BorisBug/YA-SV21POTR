#include <stdio.h>
#include "module.h"

int main()
{
    uint32_t number = 0;

    printf("Enter a number: ");

    if(module_get_uint32(&number))
    {
        printf("The number is: %d\n", number);
    }
    else
    {
        printf("Oh no! ..that was not a number!\n");
    }

    return 0;
}