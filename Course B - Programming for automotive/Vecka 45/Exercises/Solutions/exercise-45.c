#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

char *split_string(const char *, const char);

int main()
{
    char temp = ' ';
    char test[] = "This is a test!";

    char *ptr = split_string(test, temp);
    while (ptr != NULL)
    {
        printf("%s\n", ptr);
        ptr = split_string(NULL, temp);
    }

    return 0;
}

char *split_string(const char *string, const char delim)
{
    static uint16_t length = 0;
    static char *result = NULL;
    static char *pstr = NULL;

    if (string != NULL)
    {
        pstr = (char *)string;
        if (result != NULL)
        {
            free(result);
            result = NULL;
        }
        length = strlen(string) + 1;
        result = (char *)malloc(length);
    }
    memset(result, 0, length);

    uint16_t i = 0;

    while (*pstr && (*pstr != delim))
    {
        result[i++] = *pstr;
        pstr++;
    }

    while (*pstr == delim)
    {
        pstr++;
    }

    if (!strlen(result))
    {
        pstr = NULL;
        free(result);
        result = NULL;
    }

    return result;
}
