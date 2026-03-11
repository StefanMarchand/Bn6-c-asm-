#include "asm00_0_sound.h"

int PlayMusic(int songId, int unused1, int unused2)
{
    struct GameState *gameState;
    int currentSong;

    gameState = gToolkit->gameState;
    currentSong = gameState->bgMusicIndicator;
    if (songId != currentSong) {
        gameState->bgMusicIndicator = songId;
        if (songId == 0x63)
            return sound_8000630(songId, currentSong, unused2);

        return m4a_800061E(songId, currentSong, unused2);
    }

    return songId;
}
