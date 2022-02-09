#ifndef IOPORT_H
#define IOPORT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    void ioport_init(void);
    volatile uint8_t *ioport_address(void);

#ifdef __cplusplus
}
#endif

#endif /* IOPORT_H */