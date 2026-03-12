#ifndef ASM03_2_TEXT_SPRITE_WRAPPERS_H
#define ASM03_2_TEXT_SPRITE_WRAPPERS_H

struct TextSpriteEntry804657C {
    unsigned char flags;
    unsigned char kind;
    unsigned char unk_02;
    unsigned char index;
    unsigned int unk_04;
    unsigned int unk_08;
    unsigned char pad0c[0x58 - 0x0c];
};

struct TextSpriteInitEntry80465A0 {
    unsigned char kind;
    unsigned char index;
    unsigned short config;
};

extern struct TextSpriteEntry804657C eStructArr2008450[];

void ZeroFillByWord(void *memBlock, int size);
int sprite_makeUnscalable(void);
void sub_80466AA(void);

void sub_804657C(void);
void sub_80465A0(const struct TextSpriteInitEntry80465A0 *entries);

#endif
