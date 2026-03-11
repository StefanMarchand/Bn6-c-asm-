#ifndef ASM00_2_AI_H
#define ASM00_2_AI_H

struct AIData {
    unsigned char pad[0x7C];
    unsigned int usedBit;
};

extern unsigned int eUsedAIDataBitfield;

int sub_800ED80(struct AIData *aiData);

#endif
