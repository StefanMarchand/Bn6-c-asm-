#include "asm03_2_text_sprite_secondary_clear.h"

register struct TextSpriteEntrySecondary80468E0 *gTextSpriteEntrySecondary80468E0 asm("r5");

int sub_80468E0(void)
{
    gTextSpriteEntrySecondary80468E0->flags = 0;
    return sprite_makeUnscalable();
}

int sub_80468EC(int index)
{
    gTextSpriteEntrySecondary80468E0 = &byte_2011860[index];
    gTextSpriteEntrySecondary80468E0->flags = 0;
    return sprite_makeUnscalable();
}

int sub_8046900(void)
{
    struct TextSpriteEntrySecondary80468E0 *entry;
    int i;
    int result;

    result = 0;
    entry = byte_2011860;
    for (i = 0; i < 5; i++) {
        if (entry->flags) {
            gTextSpriteEntrySecondary80468E0 = entry;
            result = sub_80468E0();
        }
        entry++;
    }
    return result;
}
