/**
 * @file exercise-43.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 43
 * @version 0.1
 * @date 2021-11-09
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/*
Beskrivning
Implement a sorted singly linked list which supports the following operations:
- Inserting a new node
- Editing a node
- Deleting a node
- Printing the list
- Destroying the list
- Sorted means that when you want to add a new node, you should find the right position for the node in a way that the list is always sorted.
*/

#define LIST_DEMO 7

typedef struct node
{
    uint8_t data;
    struct node *next;
} node_t;


node_t *new_node(uint8_t data)
{
    node_t *new = (node_t*)malloc(sizeof(node_t));

    if(!new)
    {
        printf("Not enough memory!\n");
        exit(1);
    }

    printf("New: %u\n", data);

    new->data = data;
    new->next = NULL;
    return new;
}

node_t *list_insert(node_t *list, node_t *new)
{
    if(new)
    {
        printf("Insert: %u\n", new->data);

        if(!list || new->data < list->data)
        {
            new->next = list;
            list = new;
        }
        else
        {
            node_t *i = list;

            while(i->next && new->data > i->next->data)
                i = i->next;

            new->next = i->next;
            i->next = new;
        }
    }

    return list;
}

node_t *list_insert_new(node_t *list, uint8_t data)
{
    return list_insert(list, new_node(data));
}

node_t *list_last(node_t *list)
{
    while(list && list->next)
        list = list->next;

    return list;
}

node_t *list_remove(node_t *list, node_t *x)
{
    if(list && x)
    {
        printf("Remove: %u\n", x->data);

        if(list == x)
        {
            list = list->next;
            x->next =  NULL;
        }
        else
        {
            node_t *i = list;

            while(i->next && i->next!=x)
                i = i->next;

            if(i->next==x)
            {
                i->next = i->next->next;
                x->next =  NULL;
            }
            else
            {
                printf("Data %d not found in list\n", x->data);
            }
        }
    }

    return list;
}

node_t *list_edit(node_t *list, node_t *x, uint8_t newval)
{
    if(x && x->data!=newval)
    {
        printf("Edit: %u changing to %u \n", x->data, newval);
        list = list_remove(list, x);
        x->data = newval;
        list = list_insert(list, x);
    }

    return list;
}

node_t *list_delete(node_t *list, node_t *x)
{
    list = list_remove(list, x);

    if(x)
    {
        printf("Delete: %u\n", x->data);
        free(x);
    }

    return list;
}

node_t *list_destroy(node_t *list)
{
    while(list)
    {
        node_t *next = list->next;
        printf("Destroy: %u\n", list->data);
        free(list);
        list = next;
    }

    return list;
}

void list_print(node_t *list)
{
    printf("Print: ");

    while(list)
    {
        printf("%d -> ", list->data);
        list = list->next;
    }

    printf("NULL\n");
}


node_t *list_insert_many_rand(node_t *list)
{
    uint8_t data;

    for(int i=0; i<LIST_DEMO; i++)
    {
        data = rand()%200;
        list = list_insert_new(list, data);
    }

    return list;
}

int main()
{
    node_t *list = NULL;

    srand(time(0));

    // Fill many nodes with random values
    list = list_insert_many_rand(list);
    list_print(list);

    // Delete the last node
    node_t *last = list_last(list);
    list = list_delete(list, last);
    list_print(list);

    // Delete the first node
    list = list_delete(list, list);
    list_print(list);

    // Delete the third node
    list = list_delete(list, list->next->next);
    list_print(list);

    // Delete an external node
    node_t *external = new_node(123);
    list = list_delete(list, external);
    list_print(list);

    // Edit the value of the third node
    list = list_edit(list, list->next->next, 99);
    list_print(list);

    // Destroy the list
    list = list_destroy(list);
    list_print(list);

    return 0;
}

