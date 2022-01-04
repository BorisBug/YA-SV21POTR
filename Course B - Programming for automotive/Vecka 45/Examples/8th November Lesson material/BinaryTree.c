#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} treenode;

treenode *createNode(int value)
{
    treenode *result = malloc(sizeof(treenode));

    if (result != NULL)
    {
        result->value = value;
        result->left = NULL;
        result->right = NULL;
    }

    return result;
}

void printTabs(int level)
{
    for (int i = 0; i < level; i++)
    {
        printf("\t");
    }
}

void printTreeRecursive(treenode *node, char direction[], int level)
{
    printTabs(level);
    if (node == NULL)
    {

        printf("%s: <empty>\n", direction);
        return;
    }
    //printTabs(level);
    printf("%s, Level %u. Value is %i\n", direction, level, node->value);
    printTreeRecursive(node->left, "Left", level + 1);
    printTreeRecursive(node->right, "Right", level + 1);
}

void printTree(treenode *root)
{
    printTreeRecursive(root, "Root", 0);
}

bool insertNumber(treenode **nodePtr, int value)
{
    treenode *node = *nodePtr;
    if (node == NULL)
    {
        (*nodePtr) = createNode(value);
        return true;
    }
    if (value == node->value)
    {
        return false; //Binary tree shouldn't contain more than one of the value we're sorting via.
    }
    if (value < node->value)
    {
        return insertNumber(&(node->left), value);
    }
    else
    {
        return insertNumber(&(node->right), value);
    }
}

int findNumber(treenode *node, int value)
{
    if (node == NULL)
    {
        return INT_MIN;
    }
    if (value == node->value)
    {
        return value;
    }
    printf("%i is not %i\n", value, node->value);

    if (value < node->value)
    {
        printf("%i is smaller than %i, heading left.\n", value, node->value);
        return findNumber(node->left, value);
    }
    else
    {
        printf("%i is bigger than %i, heading right.\n", value, node->value);
        return findNumber(node->right, value);
    }
}

int main()
{
    treenode *root = createNode(10);
    /*root->left = createNode(4);
    root->right = createNode(6);
    root->left->left = createNode(5);
    root->left->right = createNode(15);
    root->left->right->left = createNode(22);*/

    insertNumber(&root, 3);
    insertNumber(&root, 15);
    insertNumber(&root, -2);
    insertNumber(&root, 0);
    insertNumber(&root, 5);
    insertNumber(&root, 45);
    insertNumber(&root, 6);
    insertNumber(&root, 2);
    insertNumber(&root, 123);
    insertNumber(&root, 30);

    printTree(root);

    int searchFor = 32;
    int number = findNumber(root, searchFor);
    if (number == searchFor)
    {
        printf("%i exists in tree.\n", searchFor);
    }
    else
    {
        printf("%i doesn't exist in tree.\n", searchFor);
    }

    return 0;
}