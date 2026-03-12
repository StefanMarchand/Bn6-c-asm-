#ifndef ASM03_2_TEXT_SPRITE_CLEAR_WRAPPERS_H
#define ASM03_2_TEXT_SPRITE_CLEAR_WRAPPERS_H

struct TextSpriteEntryClear804668A {
    unsigned char flags;
    unsigned char pad1[0x57];
};

extern struct TextSpriteEntryClear804668A eStructArr2008450[];

int sprite_makeUnscalable(void);

int sub_804668A(void);
int sub_80466AA(void);

#endif
