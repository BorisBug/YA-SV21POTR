/**
 * @file list.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 43
 * @version 0.1
 * @date 2021-11-09
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"


#define if_print  if(print_info) printf
static int print_info = 0;

node_t *new_node(uint8_t data)
{
    node_t *node = (node_t*)malloc(sizeof(node_t));

    if(!node)
    {
        perror("Not enough memory!\n");
        exit(1);
    }

    if_print("New: %u\n", data);

    node->data = data;
    node->next = NULL;
    return node;
}

node_t *list_insert(node_t *list, node_t *node)
{
    if(node)
    {
        if_print("Insert: %u\n", node->data);

        if(!list || node->data < list->data)
        {
            node->next = list;
            list = node;
        }
        else
        {
            node_t *i = list;

            while(i->next && node->data > i->next->data)
                i = i->next;

            node->next = i->next;
            i->next = node;
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

node_t *list_remove(node_t *list, node_t *node)
{
    if(list && node)
    {
        if_print("Remove: %u\n", node->data);

        if(list == node)
        {
            list = list->next;
            node->next =  NULL;
        }
        else
        {
            node_t *i = list;

            while(i->next && i->next!=node)
                i = i->next;

            if(i->next==node)
            {
                i->next = i->next->next;
                node->next =  NULL;
            }
            else
            {
                if_print("Data %d not found in list\n", node->data);
            }
        }
    }

    return list;
}

node_t *list_edit(node_t *list, uint8_t old, uint8_t new)
{
    if(old!=new)
    {
        node_t *node = list_search(list, old);

        if(node)
        {
            if_print("Edit: changing from %u to %u \n", node->data, new);
            list = list_remove(list, node);
            node->data = new;
            list = list_insert(list, node);
        }
    }

    return list;
}

node_t *list_delete(node_t *list, node_t *node)
{
    list = list_remove(list, node);

    if(node)
    {
        if_print("Delete: %u\n", node->data);
        free(node);
    }

    return list;
}

node_t *list_destroy(node_t *list)
{
    while(list)
    {
        node_t *next = list->next;
        if_print("Destroy: %u\n", list->data);
        free(list);
        list = next;
    }

    return list;
}

node_t *list_search(node_t *list, uint8_t data)
{
    while(list && list->data!=data)
        list = list->next;

    return list;
}

node_t *list_get_nth(node_t *list, size_t nth, uint8_t *data)
{
    for(size_t i=0; i<nth && list; i++)
        list = list->next;

    if(list)
        *data = list->data;

    return list;
}

size_t list_count(node_t *list)
{
    size_t i=0;

    for(i=0; list; i++)
        list = list->next;

    return i;
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
