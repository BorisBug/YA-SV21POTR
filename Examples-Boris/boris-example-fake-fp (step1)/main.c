#include <stdio.h>
#include "module.h"

int main()
{
    uint32_t number = 0;

    // this might be optional since default values are set to original functions
    module_init(NULL);

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