#include "asm00_0_rng_utils.h"

// Shuffle a byte list using the primary RNG.
// For each iteration, picks two random indices (mod length) and swaps the bytes.
void ShuffleByteList_PrimaryRNG(unsigned char *list, int length, int unused1, int unused2)
{
    int i, j, tmp;
    (void)unused1;
    (void)unused2;
    for (;;) {
        i = GetPositiveSignedRNG() % length;
        j = GetPositiveSignedRNG() % length;
        tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
        if (--length <= 0) break; // BUG: original decrements and loops while != 0
    }
}

// Shuffle a byte list using the secondary RNG.
void ShuffleByteList_SecondaryRNG(unsigned char *list, int length, int unused1, int unused2)
{
    int i, j, tmp;
    (void)unused1;
    (void)unused2;
    for (;;) {
        i = GetPositiveSignedRNGSecondary() % length;
        j = GetPositiveSignedRNGSecondary() % length;
        tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
        if (--length <= 0) break;
    }
}

// Shuffle a halfword list using the primary RNG.
void ShuffleHwordList_PrimaryRNG(unsigned short *list, int length, int unused1, int unused2)
{
    int i, j, tmp;
    (void)unused1;
    (void)unused2;
    for (;;) {
        i = GetPositiveSignedRNG() % length;
        j = GetPositiveSignedRNG() % length;
        tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
        if (--length <= 0) break;
    }
}

// Shuffle a halfword list using the secondary RNG.
void ShuffleHwordList_SecondaryRNG(unsigned short *list, int length, int unused1, int unused2)
{
    int i, j, tmp;
    (void)unused1;
    (void)unused2;
    for (;;) {
        i = GetPositiveSignedRNGSecondary() % length;
        j = GetPositiveSignedRNGSecondary() % length;
        tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
        if (--length <= 0) break;
    }
}
