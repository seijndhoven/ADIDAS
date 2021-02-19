#include "macros.h"
#include "parity.h"

uint8_t create_parity(uint8_t nibble)
{
    uint8_t p0 = (nibble ^ nibble >> 1 ^ nibble >> 2) & BIT0;
    uint8_t p1 = (nibble ^ nibble >> 1 ^ nibble >> 3) & BIT0;
    uint8_t p2 = (nibble >> 1 ^ nibble >> 2 ^ nibble >> 3) & BIT0;

    return p0 | p1 << 1 | p2 << 2;
}

uint8_t remove_parity(uint8_t byte)
{
    return byte >> 3;
}