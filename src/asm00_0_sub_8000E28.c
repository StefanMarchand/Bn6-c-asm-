#include "asm00_0_sound.h"

int sub_8000E28(void)
{
    return *(int *)((char *)gToolkit->S2001c04_Ptr + 0x18);
}
