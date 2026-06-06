#ifndef ASM02_CHIP_PACK_H
#define ASM02_CHIP_PACK_H

#include "asm00_0_sub_3005EBA.h"

#define CHIP_DATA_SIZE 44
#define CHIP_PACK_CODE_SLOTS 4
#define CHIP_PACK_ENTRY_SIZE 12
#define MAX_CHIP_QUANTITY 99

struct ChipDataPackEntry {
    unsigned int codes;
    unsigned char attackElement;
    unsigned char chipRarity;
    unsigned char chipElement;
    unsigned char libraryType;
    unsigned char mb;
    unsigned char effectFlags;
    unsigned char staminaDamageCounterFrames;
    unsigned char attackFamily;
    unsigned char attackSubFamily;
    unsigned char darkSoulUsage;
    unsigned char unk_0e;
    unsigned char lockOnEnable;
    unsigned char attackParam1;
    unsigned char attackParam2;
    unsigned char attackParam3;
    unsigned char attackParam4;
    unsigned char lockoutFrames;
};

extern struct ChipDataPackEntry ChipDataArr_8021DA8[];

int encryption_testPack_8006e84(int packIndex);
void ZeroFillByWord(void *memBlock, int size);

struct ChipDataPackEntry *getChip8021DA8(int whichChip);
unsigned int split9BitsFromBitfield_8021AE0(unsigned int bitfield);
unsigned char addChipsToChipPackOffset_8021b5a(unsigned char *quantityPtr, int amount);
int GetTotalChipCount(int packIndex);
void zeroFill_e2002230(void);

#endif