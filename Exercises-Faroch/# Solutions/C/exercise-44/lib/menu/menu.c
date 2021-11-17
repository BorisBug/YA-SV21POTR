#include "menu.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

static bool strtouint(const char *str, uint32_t *uiptr);

char get_command(void)
{
    char x, y;
    while ((y = getchar()) != '\n' && y != EOF)
    {
        x = y;
    }
    return toupper(x);
}

uint32_t get_user_id(void)
{
    printf("\n");

    uint32_t id = 0;

    while (1)
    {
        char chr = 0;
        char temp[10] = {0};
        printf("Enter the user ID: ");

        do
        {
            chr = getchar();

            if (isdigit(chr))
            {
                temp[id] = chr;
                id++;
            }
        } while ((chr != EOF) && (chr != '\n') && (id < sizeof(temp)));

        if (strtouint(temp, &id))
        {
            if (id > 0)
            {
                break;
            }
        }
    }

    return id;
}

void get_user_name(char *name)
{
    assert(name != NULL);

    while (1)
    {
        char chr = 0;
        uint8_t i = 0;
        printf("Enter the user Name: ");

        do
        {
            chr = getchar();
            if (isalpha(chr) || (chr == ' '))
            {
                name[i] = chr;
                i++;
            }
        } while ((chr != EOF) && (chr != '\n') && (i < MAX_NAME_SIZE - 1));

        if (strlen(name))
        {
            break;
        }
    }
}

static bool strtouint(const char *str, uint32_t *uiptr)
{
    bool status = true;

    if ((str == NULL) || (uiptr == NULL) || (*str == '\0'))
    {
        status = false;
    }
    else
    {
        *uiptr = 0;

        for (char *cptr = (char *)str; *cptr != '\0'; cptr++)
        {
            if ((*cptr < '0') || (*cptr > '9'))
            {
                status = false;
                break;
            }

            *uiptr *= 10;
            *uiptr += (*cptr - '0');
        }
    }

    return status;
}
