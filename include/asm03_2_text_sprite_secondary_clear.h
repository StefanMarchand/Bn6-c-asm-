#ifndef ASM03_2_TEXT_SPRITE_SECONDARY_CLEAR_H
#define ASM03_2_TEXT_SPRITE_SECONDARY_CLEAR_H

struct TextSpriteEntrySecondary80468E0 {
    unsigned char flags;
    unsigned char pad1[0x57];
};

extern struct TextSpriteEntrySecondary80468E0 byte_2011860[];

int sprite_makeUnscalable(void);

int sub_80468E0(void);
int sub_80468EC(int index);
int sub_8046900(void);

#endif
