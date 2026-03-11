#include "asm00_0_sound.h"

int sound_80006A2(int songId, int unused1, int bankIndex)
{
    void *soundBank;

    if (songId <= 0x25) {
        gToolkit->gameState->bgMusicIndicator = (unsigned char)songId;
    }

    soundBank = off_8000704[bankIndex];
    sound_8000808(songId, unused1, bankIndex * 4, m4a_SongNumStart);
    sound_8000808((int)soundBank, unused1, bankIndex * 4, sub_814EB1C);
    sound_8000808((int)soundBank, 0xFF, 0, sub_814F9AC);
    sound_8000808(songId, unused1, bankIndex * 4, sub_814E9F0);
    return sound_8000808((int)soundBank, unused1, bankIndex * 4, sub_814EAF0);
}
