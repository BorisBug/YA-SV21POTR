/**
 * @file list.h
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief A linked list of sorted elements.
 * @version 0.1
 * @date 2021-05-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief This function is used to insert an element in the list.
 *
 * @param data The integer to insert.
 * @return bool - true if value is unique and inserted successfully; otherwise false
 */
bool list_insert(uint8_t data);

/**
 * @brief This function returns number of the elements in the list.
 *
 * @return size_t - Number of the available elements
 */
size_t list_available(void);

/**
 * @brief This function is used to search for a data in the list.
 *
 * @param value The data to search for.
 * @return size_t - 0 if data is not in the list; otherwise the position of the first occurrence in the list.
 */
size_t list_find(uint8_t value);

/**
 * @brief This function is used to get the data value of the nth element in the list.
 *
 * @param n The nth element. n shall be a valid position and greater than 0
 * @return uint8_t - 0 if n is not valid; otherwise the data stored in the nth element.
 */
uint8_t list_nth_data(size_t n);

/**
 * @brief This function is used to delete an element in the list
 *
 * @param value The data value of a node
 * @return bool - false if data does not exist; otherwise true
 */
bool list_delete(uint8_t value);

/**
 * @brief This function is used to change data in the list.
 *
 * @param old_value The old data value
 * @param new_value The new data value
 * @return bool - false if old_data does not exist or new_data already exists; otherwise true
 */
bool list_edit(uint8_t old_value, uint8_t new_value);

/**
 * @brief This function is used to free the allocated memory for all the nodes.
 *
 */
void list_clear(void);

#endif /* LIST_H */
