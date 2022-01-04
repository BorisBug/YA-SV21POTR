/**
 * @file stack.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of stacks implemented using a dynamic size array
 *          1) Make a function to create a stack dynamically
 *          2) Make a function to push an element to the stack
 *          3) Make a function to peek in the stack
 *          4) Make a function to check if the stack is full
 *          5) Make a function to check if the stack is empty or not.
 *          6) Make a function to pop an element from the stack
 *          7) Make a function to destroy the stack
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

#define STACK_SIZE 5

typedef struct
{
    int *array;
    int capacity;
    int top;
} stack_t;

static stack_t *create(int size);
static bool push(stack_t *stack, int value);
static int peek(stack_t *stack);
static bool isfull(stack_t *stack);
static bool isempty(stack_t *stack);
static int pop(stack_t *stack);
static void destroy(stack_t **stack);

int main(void)
{
    stack_t *stack = create(STACK_SIZE);

    if (stack == NULL)
    {
        printf("Failed to create the stack!\n");
        exit(1);
    }

    if (isempty(stack))
    {
        printf("The stack is empty.\n");
    }

    (void)push(stack, 10);
    (void)push(stack, 20);

    printf("Peek: %d\n", peek(stack));

    (void)push(stack, 30);
    (void)push(stack, 40);
    (void)push(stack, 50);

    if (isfull(stack))
    {
        printf("The stack is full.\n");
    }

    printf("Peek: %d\n", peek(stack));

    if (!isempty(stack))
    {
        printf("Pop: %d\n", pop(stack));
        printf("Peek: %d\n", peek(stack));
    }

    destroy(&stack);

    return 0;
}

static void destroy(stack_t **stack)
{
    if (*stack != NULL)
    {
        free((*stack)->array);
        free(*stack);
        *stack = NULL;
    }
}

static int pop(stack_t *stack)
{
    int value = 0;

    if (stack != NULL)
    {
        if (stack->top > -1) // If the stack is not empty
        {
            value = stack->array[stack->top];
            stack->top--;
        }
    }

    return value;
}

static bool isempty(stack_t *stack)
{
    return ((stack != NULL) && (stack->top == -1));
}

static bool isfull(stack_t *stack)
{
    return ((stack != NULL) && (stack->top == (stack->capacity - 1)));
}

static int peek(stack_t *stack)
{
    int value = 0;

    if (stack != NULL)
    {
        if (stack->top > -1) // If the stack is not empty
        {
            value = stack->array[stack->top];
        }
    }

    return value;
}

static bool push(stack_t *stack, int value)
{
    bool status = false;

    if (stack != NULL)
    {
        if (stack->top < (stack->capacity - 1)) // If the stack is not full
        {
            stack->top++;
            stack->array[stack->top] = value;
            status = true;
        }
    }

    return status;
}

static stack_t *create(int size)
{
    stack_t *ptr = NULL;

    if (size > 0)
    {
        ptr = (stack_t *)malloc(sizeof(stack_t));
        if (ptr != NULL)
        {
            ptr->array = (int *)malloc(size * sizeof(int));

            if (ptr->array != NULL)
            {
                ptr->capacity = size;
                ptr->top = -1;
            }
            else
            {
                free(ptr);
                ptr = NULL;
            }
        }
    }

    return ptr;
}
