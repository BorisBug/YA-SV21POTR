/**
 * @file linked-list.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of singly linked lists
 *          1) Make a function to insert a new node to the linked list
 *          2) Make a function to print the linked list
 *          3) Make a function to delete a specific node
 *          4) Make a function to search for a specific value
 *          5) Make a function to edit nodes whose data are a specific value
 *          6) Make a function to destroy a linked list
 * @version 0.1
 * @date 2021-03-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    uint8_t data;
    struct node *next;
} node_t;

static bool insert(node_t **head, uint8_t value);
static uint8_t delete (node_t **head, uint8_t value);
static uint8_t search(node_t *head, uint8_t value);
static uint8_t edit(node_t *head, uint8_t old_value, uint8_t new_value);
static void destroy(node_t **head);
static void print(node_t *head);

int main(void)
{
    node_t *list = NULL;

    if (!insert(&list, 12))
    {
        printf("Failed to insert the node!\n");
        exit(1);
    }

    if (!insert(&list, 20))
    {
        printf("Failed to insert the node!\n");
        exit(1);
    }

    if (!insert(&list, 20))
    {
        printf("Failed to insert the node!\n");
        exit(1);
    }

    if (!insert(&list, 5))
    {
        printf("Failed to insert the node!\n");
        exit(1);
    }

    print(list);

    printf("There is/are %u 20(s) in the list.\n", search(list, 20));

    if (2 != delete (&list, 20))
    {
        printf("Failed to delete all the node whose value is 2!\n");
    }

    edit(list, 5, 50);

    print(list);

    destroy(&list);

    print(list);

    return 0;
}

static void destroy(node_t **head)
{
    while (*head != NULL)
    {
        node_t *next = (*head)->next;
        free(*head);
        *head = next;
    }
}

static uint8_t edit(node_t *head, uint8_t old_value, uint8_t new_value)
{
    uint8_t count = 0;
    node_t *cursor = head;

    while (cursor != NULL)
    {
        if (cursor->data == old_value)
        {
            cursor->data = new_value;
            count++;
        }
        cursor = cursor->next;
    }

    return count;
}

static uint8_t search(node_t *head, uint8_t value)
{
    uint8_t count = 0;
    node_t *cursor = head;

    while (cursor != NULL)
    {
        if (cursor->data == value)
        {
            count++;
        }
        cursor = cursor->next;
    }

    return count;
}

static uint8_t delete (node_t **head, uint8_t value)
{
    uint8_t count = 0;
    node_t *previous = NULL;
    node_t *current = *head;

    while (current != NULL)
    {
        if (current->data == value)
        {
            // Move the pointers
            if (previous != NULL)
            {
                previous->next = current->next;
            }
            else // The first node
            {
                *head = current->next;
            }

            // Delete current
            free(current);
            count++;

            // Update the current pointer
            current = (previous != NULL) ? previous->next : *head;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    return count;
}

static void print(node_t *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        node_t *cursor = head;
        while (cursor != NULL)
        {
            printf("%u\t", cursor->data);
            cursor = cursor->next;
        }
        printf("\n");
    }
}

static bool insert(node_t **head, uint8_t value)
{
    bool status = false;

    node_t *ptr = (node_t *)malloc(sizeof(node_t));

    if (ptr != NULL)
    {
        status = true;
        ptr->next = NULL;
        ptr->data = value;

        if (*head == NULL) // The list is empty
        {
            *head = ptr;
        }
        else
        {
            node_t *current = *head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = ptr;
        }
    }

    return status;
}
