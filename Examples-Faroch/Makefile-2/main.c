#include "data.h"
#include <stdio.h>
#include "display.h"

int main(void)
{
    int value = get_data();
    display(value);
    return 0;
}
