#include "asm00_0_rng_utils.h"

// Count the number of nibbles (4-bit groups) in a value.
// Returns 1 if value is 0, otherwise counts how many right-shifts
// by 4 are needed to reduce the value to 0.
unsigned int sub_8000C5C(unsigned int value)
{
    unsigned int count = 1;
    if (value != 0) {
        count = 0;
        do {
            if (value == 0) break;
            count++;
            value >>= 4;
        } while (1);
    }
    return count;
}
