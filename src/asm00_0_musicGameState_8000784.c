#include "asm00_0_sound.h"

int musicGameState_8000784(int songId, int unused1, int unused2)
{
    sound_8000808(songId, (int)gToolkit, unused2, (int (*)(void))sub_814EA58);
    gToolkit->gameState->bgMusicIndicator = 0xFF;
    return 0xFF;
}
