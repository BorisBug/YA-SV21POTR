#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static node_t *new_node(uint32_t user_id, const char *user_name);

node_t *insert_node(node_t *root, uint32_t user_id, const char *user_name)
{
    if (root == NULL)
    {
        root = new_node(user_id, user_name);
    }
    else if (user_id < root->id)
    {
        root->left = insert_node(root->left, user_id, user_name);
    }
    else
    {
        root->right = insert_node(root->right, user_id, user_name);
    }

    return root;
}

void free_tree(node_t *root)
{
    if (root != NULL)
    {
        free_tree(root->right);
        free_tree(root->left);
        free(root->name);
        free(root);
    }
}

void print_tree(node_t *root)
{
    if (root != NULL)
    {
        print_tree(root->right);

        printf("%d\t\t%s\n", root->id, root->name);

        print_tree(root->left);
    }
}

node_t *delete_node(node_t *root, uint32_t user_id)
{
    if (root != NULL)
    {
        if (user_id > root->id)
        {
            root->right = delete_node(root->right, user_id);
        }
        else if (user_id < root->id)
        {
            root->left = delete_node(root->left, user_id);
        }
        else if (root->left == NULL)
        {
            node_t *user = root->right;
            free(root);
            root = user;
        }
        else if (root->right == NULL)
        {
            node_t *user = root->left;
            free(root);
            root = user;
        }
        else
        {
            node_t *user = root->right;
            while ((user != NULL) && (user->left != NULL))
            {
                user = user->left;
            }

            root->id = user->id;
            free(root->name);
            root->name = (char *)malloc(strlen(user->name) + 1);
            strcpy(root->name, user->name);

            root->right = delete_node(root->right, user->id);
        }
    }

    return root;
}

node_t *search_node(node_t *root, uint32_t user_id)
{
    if ((root != NULL) && (root->id != user_id))
    {
        if (user_id > root->id)
        {
            root = search_node(root->right, user_id);
        }
        else
        {
            root = search_node(root->left, user_id);
        }
    }

    return root;
}

static node_t *new_node(uint32_t user_id, const char *user_name)
{
    node_t *user = (node_t *)malloc(sizeof(node_t));

    if (user != NULL)
    {
        user->left = NULL;
        user->right = NULL;
        user->id = user_id;

        uint8_t length = strlen(user_name) + 1;

        user->name = (char *)malloc(length);

        if (user->name == NULL)
        {
            free(user);
            user = NULL;
        }
        else
        {
            memset(user->name, 0, length);
            strcpy(user->name, user_name);
        }
    }

    return user;
}
