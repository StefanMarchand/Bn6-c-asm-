#ifndef ASM03_2_TEXT_SPRITE_CLEAR_8046696_H
#define ASM03_2_TEXT_SPRITE_CLEAR_8046696_H

struct TextSpriteEntry8046696 {
    unsigned char flags;
    unsigned char pad1[0x57];
};

extern struct TextSpriteEntry8046696 eStructArr2008450[];

int sprite_makeUnscalable(void);

int sub_8046696(int index);

#endif
