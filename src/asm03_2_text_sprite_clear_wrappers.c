#include "asm03_2_text_sprite_clear_wrappers.h"

register struct TextSpriteEntryClear804668A *gTextSpriteEntryClear804668A asm("r5");

int sub_804668A(void)
{
    gTextSpriteEntryClear804668A->flags = 0;
    return sprite_makeUnscalable();
}

int sub_80466AA(void)
{
    struct TextSpriteEntryClear804668A *entry;
    int i;
    int result;

    result = 0;
    entry = eStructArr2008450;
    for (i = 0; i < 15; i++) {
        if (entry->flags) {
            gTextSpriteEntryClear804668A = entry;
            result = sub_804668A();
        }
        entry++;
    }
    return result;
}
