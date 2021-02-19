#ifndef PARITY_H_
#define PARITY_H_

#include <stdint.h>


/*!
 * Create parity bits from a nibble and add them to the nibble at first, second and third bit
 * by shifting the nibble three places to the left.
 *
 * @param nibble: A nibble.
 *
 * @return: A byte where the fourth till seventh bits are data bits, 
 * and the first till third bits are the parity bits.
 */
uint8_t parity_create(uint8_t nibble);

/*!
 * Remove parity bits from a byte by shifting the byte three places tot he left.
 *
 * @param byte: A byte containing parity
 *
 * @return: A nibble from the incomming byte where the parity is removed.
 */
uint8_t parity_remove(uint8_t byte);

#endif
