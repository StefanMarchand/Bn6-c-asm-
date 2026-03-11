#include "asm00_0_sound.h"

int PlaySoundEffect(int songId, int unused1, int unused2)
{
    return m4a_800061E(songId, unused1, unused2);
}
