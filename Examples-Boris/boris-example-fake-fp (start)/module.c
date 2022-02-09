#include "module.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>


static bool string_to_uint32(const char *str, uint32_t *pnum)
{
    bool result = false;

    if(str && pnum)
    {
        result = true;
        uint32_t num = 0;

        // build the number one char at the time
        while(*str)
        {
            if(isdigit(*str))
            {
                num = num*10 + (*str)-'0';
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

bool module_get_uint32(uint32_t *pnumber)
{
    bool result = false;

    if(pnumber)
    {
        char string[100];

        if(user_input(string, sizeof(string)))
        {
            if(string_to_uint32(string, pnumber))
            {
                result = true;
            }
        }
    }

    return result;
}