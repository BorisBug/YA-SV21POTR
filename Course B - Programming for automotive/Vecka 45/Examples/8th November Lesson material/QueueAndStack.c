#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct aQueue
{
    char name[30];
    int age;
    char address[30];
    struct aQueue *nextQueue;
};

#define QUEUE_SIZE 2
int queue[QUEUE_SIZE];
int queueCount = 0;

bool queue_is_full()
{
    return queueCount >= QUEUE_SIZE;
}

bool queue_is_empty()
{
    return queueCount <= 0;
}

void enqueue(int number)
{
    if (!queue_is_full())
    {

        queue[queueCount] = number;
        queueCount += 1;
    }
    else
    {
        printf("Queue is full.\n");
    }
}

int dequeue()
{
    int result = INT_MIN;
    if (!queue_is_empty())
    {
        result = queue[0];
        for (int i = 0; i < queueCount - 1; i++)
        {
            queue[i] = queue[i + 1];
        }
        queueCount--;
        printf("Removing %u from queue.\n", result);
    }
    else
    {
        printf("Queue is empty.\n");
    }
    return result;
}

#define STACK_SIZE 10
int stack[STACK_SIZE];
int stackCount = 0;

bool stack_is_full()
{
    return stackCount >= STACK_SIZE;
}

bool stack_is_empty()
{
    return stackCount <= 0;
}

void push(int number)
{
    if (!stack_is_full())
    {

        stack[stackCount] = number;
        stackCount += 1;
    }
    else
    {
        printf("Stack is full.\n");
    }
}

int pop()
{
    int result = INT_MIN;
    if (!stack_is_empty())
    {
        result = stack[stackCount - 1];

        stackCount--;
        printf("Removing %u from stack.\n", result);
    }
    else
    {
        printf("Stack is empty.\n");
    }
    return result;
}

int main()
{
    /*enqueue(1);
    enqueue(54);
    enqueue(345);
    enqueue(32);

    printf("Printing %u\n", dequeue());
    printf("Printing %u\n", dequeue());
    printf("Printing %u\n", dequeue());
    printf("Printing %u\n", dequeue());*/

    push(34);
    push(23);
    push(2);
    push(26);
    push(75);

    printf("Printing %u\n", pop());
    printf("Printing %u\n", pop());
    printf("Printing %u\n", pop());
    printf("Printing %u\n", pop());
    printf("Printing %u\n", pop());
    return 0;
}