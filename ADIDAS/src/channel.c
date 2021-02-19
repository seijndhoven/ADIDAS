#include <stdlib.h>
#include <time.h>

#include "macros.h"
#include "channel.h"
#include "parity.h"

void channel_init()
{
    srand(time(NULL));
}

uint8_t channel_change_one_random_bit(uint8_t value)
{
    int random = rand() % BITS;
    
    if (random)
    {
        int n = rand() % BITS;
        value ^= 1 << n;
    }

    return value;
}
