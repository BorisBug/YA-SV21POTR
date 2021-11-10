/**
 * @file exercise-44.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 44
 * @version 0.1
 * @date 2021-11-09
 */
#include <stdio.h>
#include <stdint.h>

/*
Beskrivning
Make a program which has a menu system to store,
remove and search for users based on users id in a binary search tree.
The program shall also be able to print the users as a table in the terminal. 
The menu shall have an option to terminate the program and before terminating
the program there shall be a function to destroy the tree. Each user has a name
and a unique ID. The ID shall be between 1 and 100.
*/

typedef struct node
{
    struct node *left;
    struct node *right;
    uint8_t id;
    char *name;
} node_t;


int main()
{
    node_t *tree = NULL;

/*
    // Destroy the list
    tree = tree_destroy(tree);
    tree_print(list);*/

    return 0;
}

