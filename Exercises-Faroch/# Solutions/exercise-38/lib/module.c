#include <stdio.h>
#include "module.h"
#include <ctype.h>

void sort_string(char str[], size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = i; j < len; j++)
        {
            char upper_i = toupper(str[i]);
            char upper_j = toupper(str[j]);

            if (upper_i > upper_j)
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
            else if (upper_i == upper_j)
            {
                if (islower(str[i]) && isupper(str[j]))
                {
                    char temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
            }
            else
            {
                ;
            }
        }
    }
}

void get_string(char str[], size_t len)
{
    size_t i = 0;
    while (i < len)
    {
        char chr = (char)getchar();

        if (chr == EOF || chr == '\n')
        {
            break;
        }
        else if (isalpha(chr))
        {
            str[i++] = chr;
        }
        else
        {
            ;
        }
    }
}
