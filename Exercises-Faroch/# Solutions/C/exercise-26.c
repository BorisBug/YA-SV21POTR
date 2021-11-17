/**
 * @file exercise-26.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Create a structure, person, which has name, age, weight and height as members.
 *        Make a function, get_person, to read these members from the standard input and return them as a struct person.
 * @version 0.1
 * @date 2021-03-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdint.h>

#define MAX_NAME_LENGTH 16U

typedef struct
{
    char name[MAX_NAME_LENGTH];
    float weight, height;
    uint8_t age;
} person_t;

static person_t get_person(void);

/**
 * @brief This function is used to clear the input buffer of the standard input stream.
 *        The function consumes all data in the input buffer. 
 */
static void clear_input_buffer(void);

int main(void)
{
    person_t person = get_person();

    (void)printf("\n%s is %d years old.\n", person.name, person.age);
    (void)printf("%s's weight is %.02f kg.\n", person.name, person.weight);
    (void)printf("%s's height is %.02f m.\n", person.name, person.height);

    return 0;
}

static void clear_input_buffer(void)
{
    char ch = 0;
    while (ch != '\n' && ch != EOF)
    {
        ch = getchar(); // Consume data in the input buffer.
    }
}

static person_t get_person(void)
{
    person_t p = {0};

    char format[MAX_NAME_LENGTH] = {0};

    (void)sprintf(format, "%%%us", MAX_NAME_LENGTH - 1); // %15s

    do
    {
        (void)printf("Enter the name(max. %u letters): ", MAX_NAME_LENGTH - 1);
    } while (1 != scanf(format, p.name));

    do
    {
        clear_input_buffer();
        (void)printf("Enter the age: ");
    } while (1 != scanf("%u", &p.age));

    do
    {
        clear_input_buffer();
        (void)printf("Enter the weight in kg: ");
    } while (1 != scanf("%f", &p.weight));

    do
    {
        clear_input_buffer();
        (void)printf("Enter the height in m: ");
    } while (1 != scanf("%f", &p.height));

    return p;
}
