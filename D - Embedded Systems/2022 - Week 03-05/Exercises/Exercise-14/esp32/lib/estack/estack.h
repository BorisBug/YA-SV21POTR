#ifndef ESTACK_H
#define ESTACK_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>


/////////////////////////////////////////////////////////////////////////////////////

typedef struct
{
    void *(*embedded_malloc)(size_t);
    void (*embedded_free)(void*);

} embedded_stack_init_t;

void embedded_estack_init(embedded_stack_init_t *init);

/////////////////////////////////////////////////////////////////////////////////////


typedef struct estack estack_t; // estack_t is a forward declared abstracted data type

/**
 * @brief This function is used to create a estack
 *
 * @param size The capacity of the estack
 * @return estack_t* - NULL if an error occurres; otherwis a pointer to the created estack.
 */
estack_t *estack_create(uint16_t size);

/**
 * @brief This function returns size of the estack
 *
 * @param stck A pointer to the estack
 * @return uint16_t - 0 if stck is invalid; otherwise size of the estack
 */
uint16_t estack_size(estack_t *stck);

/**
 * @brief This function is used to clear a estack
 *
 * @param stck A pointer to the estack
 * @return bool - false if stck is not valid; otherwise true
 */
bool estack_clear(estack_t *stck);

/**
 * @brief This function returns the number of available data elements in the estack
 *
 * @param stck A pointer to the estack
 * @return int32_t -1 if the stck is invalid; otherwise the number of data elements to pop
 */
int32_t estack_available(estack_t *stck);

/**
 * @brief This function is used to insert an element in the estack.
 *
 * @param stck A pointer to the estack
 * @param data The data to push to the estack
 * @return bool - false if the estack is full; otherwise true
 */
bool estack_push(estack_t *stck, uint8_t data);

/**
 * @brief This function is used to pop the top element in the estack
 *
 * @param stck A pointer to the estack
 * @param data A pointer to an placeholder to fill with the top element
 * @return bool - false if the estack is empty; otherwise true
 */
bool estack_pop(estack_t *stck, uint8_t *data);

/**
 * @brief This function is used to destroy a estack
 *
 * @param stck A double pointer to the estack
 */
void estack_destroy(estack_t **stck);

#endif /* ESTACK_H */
