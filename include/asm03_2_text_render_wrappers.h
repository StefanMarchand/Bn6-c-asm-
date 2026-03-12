#ifndef ASM03_2_TEXT_RENDER_WRAPPERS_H
#define ASM03_2_TEXT_RENDER_WRAPPERS_H

struct TextRenderState8045F8C {
    unsigned char pad0[3];
    unsigned char unk_03;
    unsigned char unk_04;
    unsigned char pad1[0x33];
    const void *unk_38;
    int unk_3c;
    const void *unk_40;
};

struct Toolkit8045F8C {
    unsigned char pad0[0x38];
    struct TextRenderState8045F8C *unk200A220;
};

register struct Toolkit8045F8C *gToolkit8045F8C asm("r10");

extern int dword_200A25C;
extern const int dword_3006B84[];

int sub_3006B94(const void *script, int arg1, int arg2, int arg3);
int sub_8046154(const void *script, int arg1, int arg2, int arg3);

int renderTextGfx_8045F8C(const void *dialogScript, int scriptIndex, int arg2, int arg3);
void sub_8045FBC(void);
void sub_8045FC6(void);
int sub_8045FD0(const void *dialogScript, unsigned int scriptOffset, int arg2, int arg3);
int loc_8045FE4(const void *dialogScript, unsigned int scriptOffset, int arg2, int arg3);

#endif
