#include "asm00_0_sound.h"

int sub_8000F86(int arg)
{
    int r4 = arg;
    if (sub_803F838() == 0) {
        SetEventFlagFromImmediate(0xE, 0x00);
        SetEventFlagFromImmediate(0x10, 0x01);
        *(int *)((char *)gToolkit->S2001c04_Ptr + 0x18) = r4;
        sub_803F79E();
    }
    return 0;
}
