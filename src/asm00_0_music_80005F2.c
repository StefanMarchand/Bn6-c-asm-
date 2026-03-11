#include "asm00_0_sound.h"

int music_80005F2(int songId, int previousSong, int unused2)
{
    gToolkit->gameState->bgMusicIndicator = songId;
    if (songId == 0x63)
        return sound_8000630(songId, previousSong, unused2);

    return m4a_800061E(songId, previousSong, unused2);
}
