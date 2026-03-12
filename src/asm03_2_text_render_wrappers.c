#include "asm03_2_text_render_wrappers.h"

static int sub_8045FEE(const void *dialogScript, unsigned int scriptOffset, int arg2, int arg3, int mode,
                       int copyMode)
{
    const unsigned char *scriptTable;
    unsigned int entryOffset;

    gToolkit8045F8C->unk200A220->unk_03 = mode;
    gToolkit8045F8C->unk200A220->unk_04 = copyMode;
    gToolkit8045F8C->unk200A220->unk_38 = (const unsigned char *)dword_3006B84 + (scriptOffset >> 16);

    scriptTable = dialogScript;
    entryOffset = *(const unsigned short *)(scriptTable + ((scriptOffset & 0xFFFF) << 1));
    sub_8046154(scriptTable + entryOffset, scriptOffset, arg2, arg3);
    return dword_200A25C;
}

int renderTextGfx_8045F8C(const void *dialogScript, int scriptIndex, int arg2, int arg3)
{
    const unsigned char *scriptTable;

    gToolkit8045F8C->unk200A220->unk_40 = dialogScript;
    scriptTable = dialogScript;
    return sub_3006B94(scriptTable + ((const unsigned short *)scriptTable)[scriptIndex], scriptIndex, arg2, arg3);
}

void sub_8045FBC(void)
{
}

void sub_8045FC6(void)
{
}

int sub_8045FD0(const void *dialogScript, unsigned int scriptOffset, int arg2, int arg3)
{
    return sub_8045FEE(dialogScript, scriptOffset, arg2, arg3, 1, 1);
}

int loc_8045FE4(const void *dialogScript, unsigned int scriptOffset, int arg2, int arg3)
{
    return sub_8045FEE(dialogScript, scriptOffset, arg2, arg3, 2, 0);
}
