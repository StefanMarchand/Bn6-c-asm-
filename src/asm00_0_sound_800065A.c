#include "asm00_0_sound.h"

int sound_800065A(int index, int unused1, int unused2)
{
    return sound_8000808((int)off_8000704[index], unused1, unused2, sub_814FA14);
}
