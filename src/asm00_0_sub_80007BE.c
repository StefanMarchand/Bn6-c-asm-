#include "asm00_0_sound.h"

int sub_80007BE(void)
{
    int count;
    int result;
    struct SoundRequest *request;

    count = dword_200A490[0];
    if (count != 0) {
        byte_200A494[0]++;
        if (byte_200A494[0] >= 0x1A)
            byte_200A494[0] = 0;

        dword_200A498 = 0;
        request = algn_200A49C;
        do {
            ((int (*)(int, int, int))request->handler)(
                request->value,
                request->unused1,
                request->unused2);
            request++;
            count--;
        } while (count != 0);
    }

    result = 0;
    dword_200A490[0] = 0;
    if (dword_200A498 != 0) {
        result = sound_8000808(
            dword_200A498->value,
            dword_200A498->unused1,
            dword_200A498->unused2,
            dword_200A498->handler);
    }

    return result;
}
