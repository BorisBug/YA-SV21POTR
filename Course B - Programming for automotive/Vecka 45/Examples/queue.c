/**
 * @file queue.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of queues implemented using a linked list.
 *           1) Make a function to create a queue dynamically.
 *           2) Make a function to enqueue a data
 *           3) Make a function to dequeue data
 *           4) Make a function to check if the queue is empty or not
 *           5) Make a function to destroy a queue
 * @version 0.1
 * @date 2021-03-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node
{
    uint8_t data;
    struct node *next;
} node_t;

typedef struct
{
    node_t *head;
    node_t *tail;
} queue_t;

static queue_t *create(void);
static bool enqueue(queue_t *queue, uint8_t value);
static uint8_t dequeue(queue_t *queue);
static bool isempty(queue_t *queue);
static void destroy(queue_t **queue);

int main(void)
{
    queue_t *queue = create();

    if (queue == NULL)
    {
        printf("Failed to create the queue.\n");
        exit(1);
    }

    if (!enqueue(queue, 12))
    {
        printf("Failed to enqueue the data.\n");
        exit(1);
    }

    if (!enqueue(queue, 20))
    {
        printf("Failed to enqueue the data.\n");
        exit(1);
    }

    if (!enqueue(queue, 5))
    {
        printf("Failed to enqueue the data.\n");
        exit(1);
    }

    if (!isempty(queue))
    {
        printf("Dequeue: %u\n", dequeue(queue));
    }

    if (!isempty(queue))
    {
        printf("Dequeue: %u\n", dequeue(queue));
    }

    if (!isempty(queue))
    {
        printf("Dequeue: %u\n", dequeue(queue));
    }

    if (isempty(queue))
    {
        printf("The queue is empty.\n");
    }

    destroy(&queue);

    return 0;
}

static void destroy(queue_t **queue)
{
    if (*queue != NULL)
    {
        node_t *head = (*queue)->head;

        while (head != NULL)
        {
            node_t *current = head;
            head = head->next;
            free(current);
            current = NULL;
        }

        free(*queue);
        *queue = NULL;
    }
}

static bool isempty(queue_t *queue)
{
    return ((queue != NULL) && (queue->head == NULL));
}

static uint8_t dequeue(queue_t *queue)
{
    uint8_t value = 0;

    if (queue != NULL)
    {
        if (queue->head != NULL)
        {
            value = queue->head->data;
            node_t *head = queue->head;
            queue->head = queue->head->next;

            free(head);

            if (queue->head == NULL)
            {
                queue->tail = NULL;
            }
        }
    }

    return value;
}

static bool enqueue(queue_t *queue, uint8_t value)
{
    bool status = false;

    if (queue != NULL)
    {
        node_t *node = (node_t *)malloc(sizeof(node_t));

        if (node != NULL)
        {
            status = true;

            node->next = NULL;
            node->data = value;

            if (queue->head == NULL)
            {
                queue->head = node;
                queue->tail = queue->head;
            }
            else
            {
                queue->tail->next = node;
                queue->tail = node;
            }
        }
    }

    return status;
}

static queue_t *create(void)
{
    queue_t *ptr = (queue_t *)malloc(sizeof(queue_t));

    if (ptr != NULL)
    {
        ptr->head = NULL;
        ptr->tail = NULL;
    }

    return ptr;
}
