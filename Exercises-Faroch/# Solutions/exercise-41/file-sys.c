/**
 * @file file-sys.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of file handling in C
 *        1) Make an array of user_t
 *        2) Make a function to fill users with random names
 *        3) Make a function to print the users
 *        4) Make a function to write users to a binary file
 *        5) Make a function to read the users from the file
 *        6) Make a function to change a user name specified by the user id
 *        7) Use the POSIX syscall for file handling (https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/)
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

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define USERS 4U
#define NAME_LENGTH 8U

#define FILENAME "users.bin"

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

    int file = open(FILENAME, O_RDWR);

    if (file < 0)
    {
        status = false;
    }
    else
    {
        user_t user = {0};

        while (read(file, &user, sizeof(user_t)) == sizeof(user_t))
        {
            if (user.uid == id)
            {
                strcpy(user.uname, name);
                lseek(file, lseek(file, 0, SEEK_CUR) - sizeof(user_t), SEEK_SET);
                if (sizeof(user_t) != write(file, &user, sizeof(user_t)))
                {
                    status = false;
                }
                break;
            }
        }

        (void)close(file);
    }

    return status;
}

static bool read_users(user_t *arr, size_t len)
{
    bool status = true;

    int file = open(FILENAME, O_RDONLY);

    if (file < 0)
    {
        status = false;
    }
    else
    {
        memset(arr, 0, len * sizeof(user_t));
        for (size_t i = 0; i < len; i++)
        {
            if (sizeof(user_t) != read(file, &arr[i], sizeof(user_t)))
            {
                status = false;
                break;
            }
        }
        (void)close(file);
    }

    return status;
}

static bool write_users(user_t *arr, size_t len)
{
    bool status = true;

    int file = open(FILENAME, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

    if (file < 0)
    {
        status = false;
    }
    else
    {
        uint32_t length = len * sizeof(user_t);
        if (length != write(file, arr, length))
        {
            status = false;
        }

        (void)close(file);
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
