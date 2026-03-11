#include "asm00_2_ai.h"

int sub_800ED80(struct AIData *aiData)
{
    eUsedAIDataBitfield &= ~aiData->usedBit;
    return (int)aiData;
}
