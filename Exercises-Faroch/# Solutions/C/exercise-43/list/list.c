#include "list.h"
#include <stdlib.h>

typedef struct node
{
    uint8_t data;
    struct node *next;
} node_t;

static node_t *head = NULL;
static size_t available = 0;

bool list_insert(uint8_t data)
{
    bool status = false;

    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    if (new_node != NULL)
    {
        node_t *current = head;
        node_t *previous = NULL;

        while (current != NULL)
        {
            if (current->data >= data)
            {
                break;
            }
            previous = current;
            current = current->next;
        }

        new_node->data = data;
        new_node->next = NULL;

        // Insert the node into
        if (current == NULL && previous == NULL) // an empty list
        {
            head = new_node;
        }
        else if (current != NULL && previous == NULL) // the begining of the list
        {
            head = new_node;
            new_node->next = current;
        }
        else if (current == NULL && previous != NULL) // the end of the list
        {
            previous->next = new_node;
        }
        else
        {
            new_node->next = current;
            previous->next = new_node;
        }

        status = true;
        available++;
    }

    return status;
}

uint8_t list_nth_data(size_t n)
{
    size_t position = 1;
    node_t *cursor = (n > 0) ? head : NULL;

    while ((position < n) && (cursor != NULL))
    {
        cursor = cursor->next;
        position++;
    }

    return (cursor != NULL) ? cursor->data : 0;
}

size_t list_find(uint8_t value)
{
    size_t position = 0;
    node_t *cursor = head;

    while (cursor != NULL)
    {
        position++;

        if (cursor->data == value)
        {
            break;
        }

        cursor = cursor->next;
    }

    return position;
}

size_t list_available(void)
{
    return available;
}

void list_clear(void)
{
    while (head != NULL)
    {
        node_t *next = head->next;
        free(head);
        head = next;
    }
    available = 0;
}

bool list_edit(uint8_t old_value, uint8_t new_value)
{
    bool status = false;

    if (list_delete(old_value))
    {
        status = list_insert(new_value);
    }

    return status;
}

bool list_delete(uint8_t value)
{
    bool status = false;
    node_t *current = head;
    node_t *previous = NULL;

    while (current != NULL)
    {
        if (current->data == value)
        {
            available--;
            status = true;

            if (previous == NULL)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            free(current);
            break;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    return status;
}
