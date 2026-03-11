#include "asm00_0_sound.h"

int sound_8000808(int value, int unused1, int unused2, int (*handler)(void))
{
    int count;
    struct SoundRequest *request;

    count = dword_200A490[0];
    if (count < 0x20) {
        dword_200A490[0] = count + 1;
        request = (struct SoundRequest *)&dword_200A490[(count * 4) + 3];
        request->value = value;
        request->unused1 = unused1;
        request->unused2 = unused2;
        request->handler = handler;
    }
    return value;
}
