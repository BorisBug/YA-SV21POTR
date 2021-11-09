/**
 * @file exercise-42.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 42
 * @version 0.1
 * @date 2021-11-09
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Beskrivning
Implement a stack using a singly linked list. Type of the data is int.
*/

#define STACK_DEMO 5

typedef struct node
{
    int value;
    struct node *next;
} node_t;

node_t *push(node_t *stack, int value)
{
    node_t *push = (node_t*)malloc(sizeof(node_t));
    if(push)
    {
        push->value = value;
        push->next = stack;
    }
    else
    {
        printf("Not enough memory!\n");
        exit(1);
    }

    return push;
}

node_t *pop(node_t *stack, int *value)
{
    node_t *pop = stack;
    if(pop)
    {
        *value = pop->value;
        stack = pop->next;
        free(pop);
    }

    return stack;
}


int main()
{
    node_t *stack = NULL;

    int value;

    for(int i=0; i<STACK_DEMO; i++)
    {
        value = rand()%100;
        stack = push(stack, value);
        printf("Push: %d\n", value);
    }

    while(stack)
    {
        stack = pop(stack, &value);
        printf("Pop: %d\n", value);
    }

    return 0;
}

