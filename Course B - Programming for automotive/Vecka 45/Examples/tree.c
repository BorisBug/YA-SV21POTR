/**
 * @file tree.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of a binary search tree.
 *          1) Make a function to insert a node in the BST
 *          2) Make a function to print the data in the BST
 *          3) Make a function to destroy the BST
 *          4) Make a function to check if a specific data is in the BST or not
 *          5) Make a function to delete a node with a specific data
 * @version 0.1
 * @date 2021-03-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *right;
    struct node *left;
    int key;
} node_t;

static node_t *insert(node_t *node, int key);
static node_t *search(node_t *node, int key);
static node_t *delete (node_t *node, int key);
static node_t *destroy(node_t *node);
static void print(node_t *node);

int main(void)
{
    node_t *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("[1] The tree: ");
    print(root);
    printf("\n");

    root = insert(root, 45);

    printf("[2] The tree: ");
    print(root);
    printf("\n");

    root = delete (root, 45);

    printf("[3] The tree: ");
    print(root);
    printf("\n");

    if (NULL != search(root, 20))
    {
        printf("[4] The tree: ");
        print(root);
        printf("\n");
    }

    root = destroy(root);

    printf("[5] The tree: ");
    print(root);
    printf("\n");

    return 0;
}

static node_t *delete (node_t *node, int key)
{
    if (node != NULL)
    {
        if (key > node->key)
        {
            node->right = delete (node->right, key);
        }
        else if (key < node->key)
        {
            node->left = delete (node->left, key);
        }
        else
        {
            if ((node->left == NULL) && (node->right == NULL)) // The node has only no child
            {
                free(node);
                node = NULL;
            }
            else if ((node->left == NULL) && (node->right != NULL)) // The node has only a right child
            {
                node_t *right = node->right;
                free(node);
                node = right;
            }
            else if ((node->left != NULL) && (node->right == NULL)) // The node has only a left child
            {
                node_t *left = node->left;
                free(node);
                node = left;
            }
            else // The node has 2 children
            {
                /**
                 * @brief We need to find the minimum value in the right subtree of the node and assign it 
                 *        to the value of the node we want to delete and then delete the node with the minimum 
                 *        value in the right subtree of the node.                 * 
                 */

                node_t *current = node->right;

                while ((current != NULL) && (current->left != NULL))
                {
                    current = current->left;
                }

                node->key = current->key;

                node->right = delete (node->right, key);
            }
        }
    }

    return node;
}

static node_t *search(node_t *node, int key)
{
    node_t *current = NULL;

    if (node != NULL)
    {
        if (key == node->key)
        {
            current = node;
        }
        else if (key > node->key)
        {
            current = search(node->right, key);
        }
        else
        {
            current = search(node->left, key);
        }
    }

    return current;
}

static node_t *destroy(node_t *node)
{
    if (node != NULL)
    {
        destroy(node->right);
        destroy(node->left);
        free(node);
        node = NULL;
    }

    return node;
}

static void print(node_t *node)
{
    if (node != NULL)
    {
        print(node->left);
        printf("%d\t", node->key);
        print(node->right);
    }
}

static node_t *insert(node_t *node, int key)
{
    if (node == NULL) // The tree is empty
    {
        node = (node_t *)malloc(sizeof(node_t));

        if (node != NULL)
        {
            node->left = NULL;
            node->right = NULL;
            node->key = key;
        }
    }
    else if (key < node->key) // Add the node to the left subtree
    {
        node->left = insert(node->left, key);
    }
    else // Add the node to the right subtree
    {
        node->right = insert(node->right, key);
    }

    return node;
}
