#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "get_uint32.h"


static bool string_to_uint32(const char *str, uint32_t *pnum)
{
    bool result = false;

    if(str && pnum)
    {
        uint32_t num = 0;

        // build the number one char at the time
        while(*str)
        {
            if(isdigit(*str))
            {
                num = num*10 + (*str)-'0';
                result = true;
            }
            else
            {
                result = false;
                break;
            }

            str++;
        }

        if(result)
            *pnum = num;
    }

    return result;
}

static bool user_input(char *string, int size)
{
    bool result = fgets(string, size, stdin)!=NULL;
    
    if(result)
    {
        string[strlen(string)-1] = 0;
    }

    return result;
}

///////////////////////////////////////////////////////////////
// new for testing

user_input_t user_input_function = user_input;

void get_uint32_init(user_input_t user_input_ptr)
{
    user_input_function = user_input_ptr ? user_input_ptr : user_input;
}

///////////////////////////////////////////////////////////////

bool get_uint32(uint32_t *pnumber)
{
    bool result = false;

    if(pnumber)
    {
        char string[100];

        // before: using the real function
        // if(user_input(string, sizeof(string)))

        // after: using the pointer to the function substitution.
        // this allows testing using different function independent from the user
        if(user_input_function(string, sizeof(string)))
        {
            if(string_to_uint32(string, pnumber))
            {
                result = true;
            }
        }
    }

    return result;
}