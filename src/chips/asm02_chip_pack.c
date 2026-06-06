#include "chips/asm02_chip_pack.h"

struct ChipDataPackEntry *getChip8021DA8(int whichChip)
{
    return &ChipDataArr_8021DA8[whichChip];
}

unsigned int split9BitsFromBitfield_8021AE0(unsigned int bitfield)
{
    register unsigned int lower asm("r0");
    register unsigned int upper asm("r1");

    upper = bitfield >> 9;
    lower = bitfield & 0x1FF;
    return lower;
}

unsigned char addChipsToChipPackOffset_8021b5a(unsigned char *quantityPtr, int amount)
{
    register unsigned char status asm("r3");
    unsigned char quantity;

    status = 1;
    quantity = *quantityPtr;
    if (quantity == MAX_CHIP_QUANTITY) {
        status = 0;
    } else {
        quantity = (unsigned char)(quantity + amount);
        if (quantity > MAX_CHIP_QUANTITY) {
            quantity = MAX_CHIP_QUANTITY;
            status = 2;
        }
    }
    *quantityPtr = quantity;
    return status;
}

int GetTotalChipCount(int packIndex)
{
    unsigned char *packEntry;
    register int total asm("r0");

    if (encryption_testPack_8006e84(packIndex) != 0) {
        return 0;
    }

    packEntry = (unsigned char *)gToolkit->Unk2002230_Ptr + packIndex * CHIP_PACK_ENTRY_SIZE;
    total = packEntry[0] + packEntry[1] + packEntry[2] + packEntry[3];
    return total;
}

void zeroFill_e2002230(void)
{
    ZeroFillByWord(gToolkit->Unk2002230_Ptr, 0xF00);
}