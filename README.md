# ADIDAS

Advanced Development for Internet where all Data Arrives Safely.

This project is inspired by the Hamming(7,4) Code, it contains three programs:

First of all we have the encode program. This program is used for encoding data with parity bits by splitting bytes in two nibbles, and then adding three parity bits to each nibble.

Then we have the channel program. This program is used to simulate data corruption. For each byte there is a one-in-eigth chance that a random bit will be flipped and thus the data will be corrupted. Only one bit will be flipped per byte!

At last we have the decode program. This program is used to decode the encoded and possible corrupted data. Possible errors will be corrected. Retrieving the original data correctly.
