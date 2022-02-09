#include <stdio.h>
#include "get_uint32.h"
#include "play.h"

int main()
{
    uint32_t number = 0;

    // this might be optional since default values are set to original functions
    get_uint32_init(NULL);

    printf("Enter a number: ");

    if(get_uint32(&number))
    {
        printf("The number is: %d\n", number);

        if(play(number))
        {
            printf("You win!\n");
        }
        else
        {
            printf("You lose!\n");
        }
    }
    else
    {
        printf("Oh no! ..that was not a number!\n");
    }

    return 0;
}