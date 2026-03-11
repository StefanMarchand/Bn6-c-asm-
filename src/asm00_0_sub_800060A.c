#include "asm00_0_sound.h"

int sub_800060A(int value, int unused1, int unused2)
{
    int bgMusicIndicator;

    bgMusicIndicator = byte_2010B90[0];
    if (bgMusicIndicator == 0)
        bgMusicIndicator = 0xFF;

    return sound_8000808(value, bgMusicIndicator, unused2, (int (*)(void))sound_8000822);
}
