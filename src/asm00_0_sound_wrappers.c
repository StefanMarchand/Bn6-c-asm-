#include "asm00_0_sound.h"

int m4a_800061E(int songId, int unused1, int unused2)
{
    return sound_8000808(songId, unused1, unused2, m4a_SongNumStart);
}

int sound_8000630(int songId, int unused1, int unused2)
{
    return sound_8000808(songId, unused1, unused2, sub_814EA58);
}
