#ifndef ASM03_2_TEXT_SPRITE_RESET_WRAPPERS_H
#define ASM03_2_TEXT_SPRITE_RESET_WRAPPERS_H

struct TextSpriteEntry8046670 {
    unsigned char flags;
    unsigned char kind;
    unsigned char unk_02;
    unsigned char index;
    unsigned int unk_04;
    unsigned int unk_08;
    unsigned char pad0c[0x58 - 0x0c];
};

extern struct TextSpriteEntry8046670 eStructArr2008450[];

void sub_80466AA(void);
void sub_804657C(void);

void sub_8046664(void);
struct TextSpriteEntry8046670 *sub_8046670(unsigned char kind, int index, unsigned int config);

#endif
