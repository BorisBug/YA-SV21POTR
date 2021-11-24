/**
 * @file exercise-42.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of stacks implemented using a linked list
 *          1) Make a function to push an element to the stack
 *          2) Make a function to peek in the stack
 *          3) Make a function to check if the stack is full
 *          4) Make a function to check if the stack is empty or not.
 *          5) Make a function to pop an element from the stack
 *          6) Make a function to destroy the stack
 *
 * @version 0.1
 * @date 2021-03-16
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

static bool push(node_t **top, int value);
static int pop(node_t **top);
static int peek(node_t *top);
static bool isempty(node_t *top);
static void destroy(node_t **top);

int main(void)
{
    node_t *stack = NULL;

    if (isempty(stack))
    {
        printf("The stack is empty.\n");
    }

    if (!push(&stack, 10))
    {
        printf("Failed to push to the stack!\n");
        exit(1);
    }

    if (!push(&stack, 20))
    {
        printf("Failed to push to the stack!\n");
        exit(1);
    }

    if (!push(&stack, 30))
    {
        printf("Failed to push to the stack!\n");
        exit(1);
    }

    printf("Peek: %d\n", peek(stack));

    printf("Pop: %d\n", pop(&stack));

    printf("Peek: %d\n", peek(stack));

    printf("Pop: %d\n", pop(&stack));

    printf("Peek: %d\n", peek(stack));

    printf("Pop: %d\n", pop(&stack));

    if (!isempty(stack))
    {
        printf("Peek: %d\n", peek(stack));
    }

    destroy(&stack);

    return 0;
}

static void destroy(node_t **top)
{
    if (top != NULL)
    {
        while (*top != NULL)
        {
            node_t *next = (*top)->next;
            free(*top);
            *top = next;
        }
    }
}

static bool isempty(node_t *top)
{
    return (top == NULL);
}

static int pop(node_t **top)
{
    int value = 0;

    if ((top != NULL) && (*top != NULL))
    {
        value = (*top)->data;
        node_t *next = (*top)->next;
        free(*top);
        *top = next;
    }

    return value;
}

static int peek(node_t *top)
{
    return (top == NULL) ? 0 : top->data;
}

static bool push(node_t **top, int value)
{
    bool status = false;

    if (top != NULL)
    {
        node_t *ptr = (node_t *)malloc(sizeof(node_t));

        if (ptr != NULL)
        {
            status = true;
            ptr->data = value;

            if (*top == NULL)
            {
                ptr->next = NULL;
                *top = ptr;
            }
            else
            {
                ptr->next = *top;
                *top = ptr;
            }
        }
    }

    return status;
}
