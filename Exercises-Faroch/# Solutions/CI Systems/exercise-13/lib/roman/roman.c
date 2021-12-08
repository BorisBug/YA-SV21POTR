#include "roman.h"
#include <stdio.h>
#include <string.h>

static int convert(char ch);

int roman2decimal(const char *roman)
{
    int decimal = 0;

    if (roman != NULL)
    {
        int i = 0;
        size_t length = strlen(roman);

        while (roman[i] != '\0')
        {
            // Check if the letter is a roman numeral
            if (0 == convert(roman[i]))
            {
                decimal = 0;
                break;
            }

            // Check the validity of roman number
            if ((length - i) > 2)
            {
                if (convert(roman[i]) < convert(roman[i + 2]))
                {
                    decimal = 0;
                    break;
                }
            }

            // Convert roman number to decimal

            if (convert(roman[i]) >= convert(roman[i + 1]))
            {
                decimal += convert(roman[i]);
            }
            else
            {
                decimal += (convert(roman[i + 1]) - convert(roman[i]));
                i++;
            }

            i++;
        }
    }

    return decimal;
}

static int convert(char ch)
{
    int value = 0;

    switch (ch)
    {
    case 'I':
        value = 1;
        break;
    case 'V':
        value = 5;
        break;
    case 'X':
        value = 10;
        break;
    case 'L':
        value = 50;
        break;
    case 'C':
        value = 100;
        break;
    case 'D':
        value = 500;
        break;
    case 'M':
        value = 1000;
        break;
    default:
        break;
    }

    return value;
}
