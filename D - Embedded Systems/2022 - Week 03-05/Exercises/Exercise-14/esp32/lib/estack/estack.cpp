#include "estack.h"
#include <stdlib.h>

static embedded_stack_init_t estack_init = {.embedded_free=free, .embedded_malloc=malloc};

void embedded_estack_init(embedded_stack_init_t *init)
{
    if(init == NULL)
    {
        estack_init.embedded_malloc = malloc;
        estack_init.embedded_free = free;
    }
    else
    {
        estack_init.embedded_malloc = init->embedded_malloc ? init->embedded_malloc : malloc;
        estack_init.embedded_free = init->embedded_free ? init->embedded_free : free;
    }
}

struct estack
{
    int32_t top;
    uint16_t size;
    uint8_t *array;
};

estack_t *estack_create(uint16_t size)
{
    estack_t *stck = NULL;

    if (size > 0)
    {
        uint8_t *array = (uint8_t *)estack_init.embedded_malloc(size * sizeof(uint8_t));

        if (array != NULL)
        {
            stck = (estack_t *)estack_init.embedded_malloc(sizeof(estack_t));

            if (stck == NULL)
            {
                estack_init.embedded_free(array);
            }
            else
            {
                stck->array = array;
                stck->size = size;
                stck->top = -1;
            }
        }
    }

    return stck;
}

uint16_t estack_size(estack_t *stck)
{
    uint16_t size = 0;

    if (stck != NULL)
    {
        size = stck->size;
    }

    return size;
}

bool estack_clear(estack_t *stck)
{
    bool status = false;

    if (stck != NULL)
    {
        stck->top = -1;
        status = true;
    }

    return status;
}

int32_t estack_available(estack_t *stck)
{
    int32_t available = -1;

    if (stck != NULL)
    {
        available = stck->top + 1;
    }

    return available;
}

bool estack_push(estack_t *stck, uint8_t data)
{
    bool status = false;

    if (stck != NULL)
    {
        if (stck->top < stck->size - 1)
        {
            stck->top++;
            status = true;
            stck->array[stck->top] = data;
        }
    }

    return status;
}

bool estack_pop(estack_t *stck, uint8_t *data)
{
    bool status = false;

    if ((stck != NULL) && (data != NULL))
    {
        if (stck->top > -1)
        {
            *data = stck->array[stck->top];
            stck->top--;
            status = true;
        }
    }

    return status;
}

void estack_destroy(estack_t **stck)
{
    if ((stck != NULL) && (*stck != NULL))
    {
        estack_init.embedded_free((*stck)->array);
        estack_init.embedded_free(*stck);
        *stck = NULL;
    }
}
