/**
 * @file exercise-43.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 43
 * @version 0.1
 * @date 2021-11-09
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

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

/*
Beskrivning 2
Using TDD develop and test a sorted singly linked list which supports the following operations:

- Inserting a new node      <- done
- Editing a node            <- done
- Deleting a node           <- done
- Search for a value        <- done
- Getting nth data          <- done
- Getting available number of elements <- done
- Printing the list         <- done
- Clearing the list         <- done

Sorted means that when you want to add a new node, you should find the right position for the node in a way that the list is always sorted.
*/

#define LIST_DEMO 7

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
    uint8_t data = 0;

    srand(time(0));

    // Fill many nodes with random values
    list = list_insert_many_rand(list);
    list_print(list);

    // Tell how many nodes
    printf("The list has %u nodes\n", list_count(list));

    // Get the data of a specific 'nth' node
    unsigned nth = 5;
    if(list_get_nth(list, nth, &data))
        printf("Data on index %u is %u\n", nth, data);
    else
        printf("List doesn't have a %u index\n", nth);

    // Search for a value
    data = 100;
    if(list_search(list, data))
        printf("Data %u is in the list\n", data);
    else
        printf("Data %u is NOT in the list\n", data);

    // Search for a value again..
    data = list->next->next->data;
    if(list_search(list, data))
        printf("Data %u is in the list\n", data);
    else
        printf("Data %u is NOT in the list\n", data);

    // Delete node, try different cases

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

