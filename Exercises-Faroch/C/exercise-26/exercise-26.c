/**
 * @file exercise-26.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 26
 * @version 0.1
 * @date 2021-10-25
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>

/*
Beskrivning
Create a structure, person, which has name, age, weight and height as members.
Make a function, get_person, to read these members from the standard input and return them as a struct person.
*/

/*
Boris:
As an extra, i added the versions with pointers.
Also added a simple verification for the faulty scanf.
*/

typedef struct PERSON
{
    char name[30]; // alphabetic
    unsigned age; // years (unsigned char?)
    float weight; // kilograms
    unsigned height; // centimeters (unsigned char?)

} person_t;

const char *lbl_name = "Name: ";
const char *lbl_age = "Age (years): ";
const char *lbl_weight = "Weight (kg): ";
const char *lbl_height = "Height (cm): ";

#define print_scan(lbl, fmt, var)         \
    {                                     \
        int r = 0;                        \
        do                                \
        {                                 \
            printf("%s", (lbl));          \
            r = scanf((fmt), (var));      \
            fflush(stdin);                \
            if (r <= 0)                   \
                printf("..try again!\n"); \
        } while (r <= 0);                 \
    }                                     \

person_t get_person()
{
    printf("Enter values for a person:\n");

    person_t p;
    print_scan(lbl_name, "%s", p.name);
    print_scan(lbl_age, "%u", &p.age);
    print_scan(lbl_weight, "%f", &p.weight);
    print_scan(lbl_height, "%u", &p.height);
    return p;
}

void print_person(person_t p)
{
    printf("Person:\n");
    printf("%s%s\n",lbl_name, p.name);
    printf("%s%u\n", lbl_age, p.age);
    printf("%s%.2f\n", lbl_weight, p.weight);
    printf("%s%u\n", lbl_height, p.height);
}

void get_person_ptr(person_t *p)
{
    printf("Enter values for a person:\n");
    print_scan(lbl_name, "%s", p->name);
    print_scan(lbl_age, "%u", &p->age);
    print_scan(lbl_weight, "%f", &p->weight);
    print_scan(lbl_height, "%u", &p->height);
}

void print_person_ptr(const person_t *p)
{
    printf("Person:\n");
    printf("%s%s\n",lbl_name, p->name);
    printf("%s%u\n", lbl_age, p->age);
    printf("%s%.2f\n", lbl_weight, p->weight);
    printf("%s%u\n", lbl_height, p->height);
}

int main()
{
    // use the return value
    person_t p1 = get_person();
    printf("\n");
    print_person(p1);

    printf("\n----\n\n");

    // use the reference value (pointer!)
    person_t p2 = {0};
    get_person_ptr(&p2);
    printf("\n");
    print_person_ptr(&p2);

    printf("\n");
    return 0;
}