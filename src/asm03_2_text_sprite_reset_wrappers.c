#include "asm03_2_text_sprite_reset_wrappers.h"

void sub_8046664(void)
{
    sub_80466AA();
    sub_804657C();
}

struct TextSpriteEntry8046670 *sub_8046670(unsigned char kind, int index, unsigned int config)
{
    struct TextSpriteEntry8046670 *entry;

    entry = &eStructArr2008450[index];
    entry->kind = kind;
    entry->flags = 9;
    entry->unk_04 = config;
    entry->unk_08 = 0;
    return entry;
}
