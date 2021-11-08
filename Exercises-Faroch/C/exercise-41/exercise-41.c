/**
 * @file exercise-41.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 41
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

/*
Beskrivning
Make a C program to define a user structure with name and id members.
Then..
1) Make an array of user_t
2) Make a function to fill users with random names
3) Make a function to print the users
4) Make a function to write users to a binary file
5) Make a function to read the users from the file
6) Make a function to change a user name specified by the user id
*/

#define NAME_SIZE 30
#define USERS_SIZE 12
#define USERS_FILE "users.bin"

const char *names[]=
{"Albert", "Florinda", "Johan", "Maria", "William", "Violet",
"Kathryn", "George", "Terry", "Björn", "Åsa", "Milagros", "Harper",
"Agustin", "Dakota", "Juliet", "Scott", "Rey", "Crystal", "Penelope",
};

typedef struct
{
    char name[NAME_SIZE];
    unsigned short id;
} user_t;

// 2) Make a function to fill users with random names
void users_fill(user_t *users, size_t size)
{
    for(int i=0; i<size; i++)
    {
        // sequential ID
        users[i].id = i+1;

        // random name
        int sz = sizeof(names)/sizeof(names[0]);
        strcpy(users[i].name, names[rand()%sz]);
    }
}

// 3) Make a function to print the users
void users_print(user_t *users, size_t size)
{
    for(int i=0; i<size; i++)
        printf("%d- %s\n", users[i].id, users[i].name);
    printf("\n");
}

//4) Make a function to write users to a binary file
bool users_write(user_t *users, size_t size)
{
    // open the file
    FILE *file = fopen(USERS_FILE, "w+");

    if(!file)
    {
        printf("Not possible to open the file.\n");
        return false;
    }

    // write size
    fwrite(&size, sizeof(size), 1, file);
    // write complete array
    fwrite(users, sizeof(user_t), size, file);

    // close the file;
    fclose(file);
    return true;
}

// 5) Make a function to read the users from the file
bool users_read(user_t *users, size_t *size)
{
    // open the file
    FILE *file = fopen(USERS_FILE, "r");

    if(!file)
    {
        printf("Not possible to open the file.\n");
        return false;
    }

    // I am NOT returning a new pointer for the array.
    // Just as a gentile realistic thing i am changing the value of "size"
    // so it is possible to test the result on the other side of the function.
    // It should be always the same value. In this case size=USERS_SIZE

    // I am also NOT checking errors after the succeeding opening the file.

    // read size
    fread(size, sizeof(size), 1, file);
    // read complete array
    fread(users, sizeof(user_t), *size, file);

    // close the file;
    fclose(file);
    return true;
}

// 6) Make a function to change a user name specified by the user id
bool user_change_name_by_id(user_t *users, size_t size, unsigned short id, const char *newname)
{
    // For the simplicity of the code, i am not doing memory allocation on the name of each user
    // ..then i am expecting a fixed array with max NAME_SIZE chars. 
    assert(strlen(newname)<NAME_SIZE);

    for(int i=0; i<size; i++)
    if(users[i].id==id)
    {
        strcpy(users[i].name, newname);
        return true;
    }

    // not found
    return false;    
}

int main()
{
    srand(time(NULL));

    // 1) Make an array of user_t
    user_t users[USERS_SIZE] = {0};
    size_t size = USERS_SIZE;

    users_fill(users, size);
    users_print(users, size);
    users_write(users, size);
    users_read(users, &size);

    // This exercise is not a REAL case, so i am NOT doing memory
    // allocation before reading, i am just assuming that write and read
    // is always done for a full array with size = USERS_SIZE. 
    assert(size==USERS_SIZE);

    //6) Make a function to change a user name specified by the user id
    // if found, change name and print list again
    if(user_change_name_by_id(users, size, 3, "New Name Jr"))
        users_print(users, size);

    return 0;
}