#include "mmetro.h"
#include <stdlib.h>
#include <stdbool.h>

struct mmetro
{
    bool mu;
    uint32_t interval;
    uint32_t previous;
};

static bool initialized = false;
static mmetro_bsp_t bsp = {0};

void mmetro_init(mmetro_bsp_t *bsp_ptr)
{
    initialized = false;

    if(bsp_ptr && bsp_ptr->malloc && bsp_ptr->micros && bsp_ptr->millis)
    {
        bsp.malloc = bsp_ptr->malloc;
        bsp.micros = bsp_ptr->micros;
        bsp.millis = bsp_ptr->millis;
        initialized = true;
    }
}

mmetro_t *mmetro_create(bool mu, uint32_t interval)
{
    mmetro_t *ptr = NULL;

    if (initialized && (interval > 0))
    {
        ptr = (mmetro_t *)bsp.malloc(sizeof(mmetro_t));

        if (ptr != NULL)
        {
            ptr->mu = mu;
            ptr->interval = interval;
            ptr->previous = mu ? bsp.millis() : bsp.micros();
        }
    }

    return ptr;
}

uint8_t mmetro_check(mmetro_t *metro)
{
    uint8_t status = MMETRO_ERROR;

    if (initialized && (metro != NULL))
    {
        status = MMETRO_NO;
        uint32_t now = (metro->mu) ? bsp.millis() : bsp.micros();

        if (now - metro->previous >= metro->interval)
        {
            status = MMETRO_YES;
            metro->previous = now;
        }
    }

    return status;
}

void mmetro_reset(mmetro_t *metro)
{
    if (initialized && (metro != NULL))
    {
        metro->previous = (metro->mu) ? bsp.millis() : bsp.micros();
    }
}