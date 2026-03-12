#include "asm03_2_text_sprite_clear_8046696.h"

int sub_8046696(int index)
{
    eStructArr2008450[index].flags = 0;
    return sprite_makeUnscalable();
}
