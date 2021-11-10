/**
 * @file list.h
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 43
 * @version 0.1
 * @date 2021-11-09
 */

#ifndef _LIST_H_
#define _LIST_H_

#include <stdint.h>
#include <stddef.h>

typedef struct node
{
    uint8_t data;
    struct node *next;
} node_t;


node_t *new_node(uint8_t data);
node_t *list_insert(node_t *list, node_t *node);
node_t *list_insert_new(node_t *list, uint8_t data);
node_t *list_last(node_t *list);
node_t *list_remove(node_t *list, node_t *node);
node_t *list_edit(node_t *list, uint8_t old, uint8_t new);
node_t *list_delete(node_t *list, node_t *node);
node_t *list_destroy(node_t *list);
node_t *list_search(node_t *list, uint8_t data);
node_t *list_get_nth(node_t *list, size_t nth, uint8_t *data);
size_t list_count(node_t *list);
void list_print(node_t *list);

#endif
