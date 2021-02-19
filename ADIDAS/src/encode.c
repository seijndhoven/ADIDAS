#include <stdio.h>
#include <stdlib.h>

#include "macros.h"
#include "encode.h"
#include "parity.h"

void encode_get_nibbles(uint8_t value, uint8_t* low, uint8_t* high)
{
    *low = value & LSB_NIBBLE_HIGH_MASK;
    *high = value >> 4;
}

void encode_value(uint8_t value, uint8_t* high, uint8_t* low)
{
    encode_get_nibbles(value, low, high);

    *high = *high << 3 | create_parity(*high);
    *low = *low << 3 | create_parity(*low);
}
