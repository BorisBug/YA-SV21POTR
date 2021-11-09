/**
 * @file file-txt.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of file handling in C
 *        1) Make an array of user_t
 *        2) Make a function to fill users with random names
 *        3) Make a function to print the users
 *        4) Make a function to write users to a text file
 *        5) Make a function to read the users from the file
 *        6) Make a function to change a user name specified by the user id
 * @version 0.1
 * @date 2021-03-10
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILENAME "users.txt"

#define NAME_LENGTH 8U
#define USERS 4U

typedef struct
{
    char uname[NAME_LENGTH];
    uint8_t uid;
} user_t;

static void fill_users(user_t *arr, size_t len);
static void print_users(const user_t *arr, size_t len);

static bool write_users(user_t *arr, size_t len);
static bool read_users(user_t *arr, size_t len);
static bool update_user(uint8_t id, const char *name);

int main(void)
{
    user_t users[USERS] = {0};

    fill_users(users, USERS);

    print_users(users, USERS);

    if (!write_users(users, USERS))
    {
        printf("Failed to write the users to the file.\n");
        exit(1);
    }

    if (!read_users(users, USERS))
    {
        printf("Failed to read the users to the file.\n");
        exit(1);
    }

    printf("\n\n");
    print_users(users, USERS);

    if (!update_user(2U, "Abcdefg"))
    {
        printf("Failed to update user in the file.\n");
        exit(1);
    }

    if (!read_users(users, USERS))
    {
        printf("Failed to write the users to the file.\n");
        exit(1);
    }

    printf("\n\n");
    print_users(users, USERS);

    return 0;
}

static bool update_user(uint8_t id, const char *name)
{
    bool status = true;

    FILE *file = fopen(FILENAME, "r+");

    if (file == NULL)
    {
        status = false;
    }
    else
    {
        while (0 == feof(file))
        {
            long int pos = ftell(file);
            char line[5 + NAME_LENGTH] = {0};

            if (NULL == fgets(line, sizeof(line), file))
            {
                status = false;
                break;
            }

            uint8_t uid = 0;
            sscanf(line, "%hhu:", &uid);

            if (uid == id)
            {
                memset(line, 0, sizeof(line));
                sprintf(line, "%hhu: %s\n", id, name);
                fseek(file, pos, SEEK_SET);
                if (EOF == fputs(line, file))
                {
                    status = false;
                }
                break;
            }
        }

        (void)fclose(file);
    }

    return status;
}

static bool read_users(user_t *arr, size_t len)
{
    bool status = true;

    FILE *file = fopen(FILENAME, "r");

    if (file == NULL)
    {
        status = false;
    }
    else
    {
        memset(arr, 0, len * sizeof(user_t));
        for (size_t i = 0; i < len; i++)
        {
            (void)fscanf(file, "%hhu: %s\n", &arr[i].uid, arr[i].uname);
            if (0 != ferror(file))
            {
                status = false;
                break;
            }
        }
        (void)fclose(file);
    }

    return status;
}

static bool write_users(user_t *arr, size_t len)
{
    bool status = true;

    FILE *file = fopen(FILENAME, "w");

    if (file == NULL)
    {
        status = false;
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            (void)fprintf(file, "%u: %s\n", arr[i].uid, arr[i].uname);
            if (0 != ferror(file))
            {
                status = false;
                break;
            }
        }

        (void)fclose(file);
    }

    return status;
}

static void print_users(const user_t *arr, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%u: %s\n", arr[i].uid, arr[i].uname);
    }
}

static void fill_users(user_t *arr, size_t len)
{
    srand(time(NULL));
    for (size_t i = 0; i < len; i++)
    {
        arr[i].uid = (i + 1);
        for (size_t j = 0; j < NAME_LENGTH - 1; j++)
        {
            arr[i].uname[j] = ((j == 0) ? 'A' : 'a') + rand() % 26;
        }
    }
}
