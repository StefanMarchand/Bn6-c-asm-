#include "asm03_2_text_sprite_wrappers.h"

void sub_804657C(void)
{
    struct TextSpriteEntry804657C *entry;
    int i;

    ZeroFillByWord(eStructArr2008450, 0x528);
    entry = eStructArr2008450;
    for (i = 0; i < 15; i++) {
        entry->unk_02 = 0x20;
        entry->index = i;
        entry++;
    }
}

void sub_80465A0(const struct TextSpriteInitEntry80465A0 *entries)
{
    while (entries->kind != 0xFF) {
        sub_8046670(entries->kind, entries->index, entries->config);
        entries++;
    }
}
