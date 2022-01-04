#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// To create a linked list, create a struct that contains a pointer towards a struct of the same type.
struct node
{
    int number;
    struct node *next;     //Like this.
    struct node *previous; //Doubly linked lists also have a pointer to the previous node.
};

// When we want to make a new node, we need to allocate the memory for it and then create our struct at this location.
struct node *makeNewNode(int number)
{
    struct node *newNode = NULL;
    newNode = malloc(sizeof(struct node));
    printf("%u\n", sizeof(struct node));
    if (newNode != NULL)
    {
        newNode->number = number;
        newNode->next = NULL;
        newNode->previous = NULL;
        printf("Created new node at %p\n", newNode);
    }
    else
    {
        printf("Memory allocation failure.\n");
    }

    return newNode;
}

//When we add a node we add it at the end of the list, after the last lastNode.
void *addNode(struct node **lastPtr, int number)
{
    struct node *lastNode = *lastPtr;
    lastNode->next = makeNewNode(number);
    lastNode->next->previous = lastNode;
    if (lastNode->next != NULL)
    {

        *lastPtr = lastNode->next; //We need to repoint the last pointer to the next last node when we add a new one.
    }
    else
    {
        printf("Could not add node.");
    }
};

/*struct node *addNode(struct node *lastPtr, int number)
{
    struct node *lastNode = lastPtr;
    lastNode->next = makeNewNode(number);
    if (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    else
    {
        printf("Could not add node.");
    }
    return lastNode; //We can alternatively return what the next lastNode is as a return.
};*/

bool isValueAlreadyInList(int number, struct node *firstNode)
{
    bool result = false;
    struct node *currentNode = firstNode;
    while (currentNode != NULL)
    {
        if (currentNode->number == number)
        {
            result = true;
        }
    }
    return result;
}

//Not programmed for doubly linked list.
struct node *removeValueFromLinkedList(struct node *firstNode, int valueToRemove)
{
    struct node *currentNode = firstNode;
    if (firstNode->number == valueToRemove)
    {
        struct node *removedNode = currentNode;
        firstNode = currentNode->next;
        free(removedNode);
    }
    while (currentNode != NULL)
    {
        if (currentNode->next != NULL)
        {
            break;
        }
        if (currentNode->number == valueToRemove)
        {
            struct node *removedNode = currentNode->next;
            currentNode->next = currentNode->next->next;
            free(removedNode);
            break;
        }
        currentNode = currentNode->next;
    }
    return firstNode;
}

/*  To loop through a linked list, we can set a node object to first be
    the first node, and then set it to be the next node once for each step.
*/
void printLinkedList(struct node *firstNode)
{
    struct node *currentNode = firstNode;
    while (currentNode != NULL) //If the next element is NULL, the list is over.
    {
        printf("Value at %p is %u. Next node is %p and previous is %p\n", currentNode, currentNode->number, currentNode->next, currentNode->previous);
        currentNode = currentNode->next; //Here I walk forward through the list.
    }
}

void printLinkedListInReverse(struct node *lastNode)
{
    struct node *currentNode = lastNode;
    while (currentNode != NULL) //If the next element is NULL, the list is over.
    {
        printf("Value at %p is %u. Next node is %p and previous is %p\n", currentNode, currentNode->number, currentNode->next, currentNode->previous);
        currentNode = currentNode->previous; //Here I walk forward through the list.
    }
}

void freeLinkedList(struct node *firstNode)
{
    struct node *currentNode = firstNode;
    while (currentNode != NULL)
    {
        struct node *nextNode = currentNode->next;
        free(currentNode);
        printf("Freeing %p\n", currentNode);
        currentNode = nextNode;
    }
}

int main()
{
    /*  A linked list should keep track of what is the first node in the 
        list, as well as what's the last node in the list.
        When there's only one node in the list, it's the same node.
    */
    struct node *firstNode = makeNewNode(1);
    struct node *lastNode = firstNode;

    //Changing so the pointer points at the next node inside the function.
    addNode(&lastNode, 25);
    addNode(&lastNode, 53);
    addNode(&lastNode, 67);

    firstNode = removeValueFromLinkedList(firstNode, 1);
    /*//Returning the next lastNode.
    lastNode = addNode(lastNode, 25);
    lastNode = addNode(lastNode, 53);
    lastNode = addNode(lastNode, 67);*/

    //Manually adding nodes.
    /*firstNode->next = makeNewNode(25);
    firstNode->next->next = makeNewNode(52);
    firstNode->next->next->next = makeNewNode(11);*/

    printLinkedList(firstNode);
    //printLinkedListInReverse(lastNode);
    freeLinkedList(firstNode);

    //printf("Value: %u\n", firstNode->number);

    return 0;
}
