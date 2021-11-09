/**
 * @file exercise-39.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Write a program to make an array, persons, of person_t dynamically.
 *        The program shall ask the user to enter length of the array.
 *        Then the program shall allocate memory for the array.
 *        Then the program shall ask the user to enter the name and the age of each person.
 *        In the end the program shall print a table of all the persons to the output.
 * @version 0.1
 * @date 2021-03-11
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    uint8_t age;
} person_t;

static void clear_inbuf(void)
{
    char ch = '\0';
    while ((ch != '\n') && (ch != EOF))
    {
        ch = (char)getchar();
    }
}

static void free_persons(person_t **prsns, size_t len)
{
    for (person_t *person = *prsns; (person - *prsns) < len; ++person)
    {
        if (person->name != NULL)
        {
            free(person->name);
            person->name = NULL;
        }
    }

    free(*prsns);
    *prsns = NULL;
}

int main(void)
{
    size_t length = 0;

    while (length == 0)
    {
        (void)printf("Enter length of the array: ");
        scanf("%lu", &length);
        clear_inbuf();
    }

    person_t *persons = (person_t *)calloc(length, sizeof(person_t));
    if (persons == NULL)
    {
        (void)printf("Failed to allocate memory for persons.\n");
        exit(1);
    }

    for (size_t i = 0; i < length; ++i)
    {
        char name[32] = {0};

        (void)printf("Enter name of the person[%lu]: ", i);
        scanf("%31s", name);
        clear_inbuf();

        uint32_t age = 0;
        (void)printf("Enter age of the person[%lu]: ", i);
        scanf("%u", &age);
        clear_inbuf();

        persons[i].age = (uint8_t)age;
        persons[i].name = (char *)malloc((strlen(name) + 1) + sizeof(char));
        if (persons[i].name == NULL)
        {
            (void)printf("Failed to allocate memory for person[%u].\n", i);
            free_persons(&persons, length);
            exit(1);
        }
        strcpy(persons[i].name, name);
    }

    for (size_t i = 0; i < length; ++i)
    {
        printf("%s\t%u\n", persons[i].name, persons[i].age);
    }

    free_persons(&persons, length);

    return 0;
}
