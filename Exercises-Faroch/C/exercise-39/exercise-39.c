/**
 * @file exercise-39.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 39
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*
Beskrivning
Write a program to make an array, persons, of person_t dynamically.
The program shall ask the user to enter length of the array.
Then the program shall allocate memory for the array.
Then the program shall ask the user to enter the name and the age of each person.
In the end the program shall print a table of all the persons to the output.
*/

typedef struct
{
    char *name;
    uint8_t age;
} person_t;

#define MAX_NAME_SIZE 40

///////////////////////////////////
// general functions

void input_string(const char *label, char *dest, unsigned size)
{
    assert(dest);
    printf("%s", label);
    fgets(dest, size, stdin);
    dest[strlen(dest)-1] = 0;
}

long input_long(const char* label)
{
    char *next = "";
    char strnum[50];
    input_string(label, strnum, sizeof(strnum));
    return strtol(strnum, &next, 10);
}

///////////////////////////////////
// functions for persons
// -- singular: treat as 1 person
// -- plural: treat as array

void person_input(person_t *person, unsigned index)
{
    assert(person);

    person->name = (char*)malloc(MAX_NAME_SIZE);
    if(!person->name)
        exit(1);

    printf("%d) ", index+1);
    input_string("Name: ", person->name, MAX_NAME_SIZE);
    printf("%d) ", index+1);
    person->age = input_long("Age: ");
}

void persons_input(person_t *persons, unsigned size)
{
    assert(persons);
    for(unsigned i=0; i<size; i++)
        person_input(&persons[i], i);
}

void persons_list(const person_t *persons, unsigned size)
{
    assert(persons);
    for(unsigned i=0; i<size; i++)
        printf("%s, %d\n", persons[i].name, persons[i].age);
}

void persons_free(person_t *persons, unsigned size)
{
    assert(persons);
    for(unsigned i=0; i<size; i++)
    {
        free(persons[i].name);
        persons[i].name = NULL;
    }
}

 
int main(void)
{
    unsigned size = input_long("Amount of persons: ");

    person_t *persons = (person_t*)malloc(sizeof(person_t)*size);
    if(!persons)
        exit(1);

    printf("Enter info for each person..\n");
    persons_input(persons, size);

    printf("List of persons:\n");
    persons_list(persons, size);

    persons_free(persons, size);
    persons = NULL;
    return 0;
}