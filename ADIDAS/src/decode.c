#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "macros.h"
#include "decode.h"
#include "parity.h"

typedef enum
{
    DATA0 = 0x3, 
    DATA1 = 0x7, 
    DATA2 = 0x5,
    DATA3 = 0x6
} DataErrors;

uint8_t decode_combine_nibbles(uint8_t high, uint8_t low)
{
    return high << 4 | low;
}

void decode_byte(uint8_t input, uint8_t* nibble)
{
    uint8_t incommingParity = input & PARITY_HIGH_MASK;
    uint8_t createdParity = parity_create(parity_remove(input));

    DataErrors dataError = incommingParity ^ createdParity;

    switch (dataError)
    {
    case DATA0:
        *nibble = parity_remove(input) ^ BIT0;
        break;
    case DATA1:
        *nibble = parity_remove(input) ^ BIT1;
        break;
    case DATA2:
        *nibble = parity_remove(input) ^ BIT2;
        break;
    case DATA3:
        *nibble = parity_remove(input) ^ BIT3;
        break;
    default:
        *nibble = parity_remove(input);
        break;
    }
}