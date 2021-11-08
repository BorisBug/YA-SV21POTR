/**
 * @file struct-union.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of user defined data types in C
 * @version 0.1
 * @date 2021-02-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdint.h>

struct Date
{
    unsigned char day;
    unsigned char month;
    unsigned short int year;
};

struct Person
{
    char name[32];
    unsigned char age;
    float height, weight;
    struct Date birthdate; // It is possible to have a member which is a user defined data type.
};

struct Rectangle
{
    float height; // Members with the same name but declared in two different structs (float height in Person)
    float width;
    struct // Unnamed structure
    {
        int x;
        int y;
    } position;
};

union Data
{
    uint32_t dword;
    uint16_t word;
    uint8_t byte;
};

// A defined bitfield struct
typedef struct
{
    uint32_t day : 5;   // 5 bits which can have an unsigned number from 0 to 31
    uint32_t month : 4; // 4 bits which can have an unsigned number from 0 to 15
    uint32_t year : 23; // 23 bits which can have an unsigned number from 0 to 8,388,607
} date_t;

int main(void)
{
    struct Date date_a = {}; // All the members are set to zero
    printf("Date A: %02d-%02d-%04d\n", date_a.day, date_a.month, date_a.year);

    struct Date date_b = {0}; // All the members are explicitly set to zero
    printf("Date B: %02d-%02d-%04d\n", date_b.day, date_b.month, date_b.year);

    struct Date date_c = {15, 2, 2021}; // Members shall be initialized in order
    printf("Date C: %02d-%02d-%04d\n", date_c.day, date_c.month, date_c.year);

    // Initialization using member designators.
    // Members shall be initialized in order
    // year is automatically set to zero
    struct Date date_d = {.day = 15, 2};
    printf("Date D: %02d-%02d-%04d\n", date_d.day, date_d.month, date_d.year);

    struct Date date_e;
    // Initialization using . operator
    date_e.day = 15;
    date_e.month = 2;
    date_e.year = 2021;
    printf("Date E: %02d-%02d-%04d\n", date_d.day, date_d.month, date_d.year);

    date_a = date_e; // copy date_e to date_a
    printf("Date A: %02d-%02d-%04d\n", date_a.day, date_a.month, date_a.year);

    // Using the sizeof operator to get size of Date and its member, year
    printf("Size of Date is %lu and size of year is %lu\n", sizeof(struct Date), sizeof(((struct Date *)0)->year));

    struct Rectangle rec = {2.5f, 10.0f};
    printf("The rectangle width is %f,its height is %f and its position is (%d, %d)\n",
           rec.width, rec.height, rec.position.x, rec.position.y);

    struct Person stefan = {"Stefan", 20, 180.0f, 75.0f, {1, 1, 1990}}; // Initialize Person and its Date type member(birthdate)
    printf("Name: %s\nAge: %d\nHeight: %f\nWeight: %f\nBirthdate: %04d-%02d-%02d\n",
           stefan.name, stefan.age, stefan.height, stefan.weight,
           stefan.birthdate.year, stefan.birthdate.month, stefan.birthdate.day);

    union Data data = {0x01020304U}; // Declare and initialize a variable of union Data
    // We can have access to the same data in different ways
    printf("Byte: 0x%02X, Word: 0x%04X, Double Word: 0x%08X\n", data.byte, data.word, data.dword);

    date_t bf_date = {.day = 15U, .month = 2U, .year = 2021U};

    printf("Bit-Field Date: %02d-%02d-%04d\n", bf_date.day, bf_date.month, bf_date.year);

#if 0
    printf("%p\n", &bf_date.month); // Impossible to get the address of a bit-field
#endif

    return 0;
}
