#ifndef MACROS_H_
#define MACROS_H_

#define BITS 0x8
#define LSB_NIBBLE_HIGH_MASK 0xF
#define PARITY_HIGH_MASK 0x7

typedef enum
{
    BIT0 = 0x1,
    BIT1 = 0x2, 
    BIT2 = 0x4, 
    BIT3 = 0x8,
    BIT4 = 0x10,
    BIT5 = 0x20, 
    BIT6 = 0x40, 
    BIT7 = 0x80
} Byte;

#endif