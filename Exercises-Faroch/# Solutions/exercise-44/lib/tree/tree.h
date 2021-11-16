#ifndef TREE_H
#define TREE_H

#include <stdint.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    uint32_t id;
    char *name;
} node_t;

void free_tree(node_t *root);
void print_tree(node_t *root);
node_t *delete_node(node_t *root, uint32_t user_id);
node_t *search_node(node_t *root, uint32_t user_id);
node_t *insert_node(node_t *root, uint32_t user_id, const char *user_name);

#endif
