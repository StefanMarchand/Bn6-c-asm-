#include "menu_core_initmainmenu.h"

int sub_801FE5E(void)
{
    return eStruct203F7D8.active;
}

int sub_801FE64(void)
{
    eStruct203F7D8.active = 0;
    return 0;
}

int eStruct203F7D8_getUnk01(void)
{
    return eStruct203F7D8.unk_01;
}

int sub_801FEEE(int arg0)
{
    static int (*const sMenuTransferHandlers[])(int) = {
        sub_801FF18,
        sub_801FFD6,
        sub_801FFD6,
        sub_801FF18,
    };

    return sMenuTransferHandlers[eStruct200BC30_getJumpOffset00()](arg0);
}

int sub_80200A4(int timer)
{
    eStruct203F7D8.timer = timer;
    eStruct203F7D8.flags |= 1;
    return eStruct203F7D8.flags;
}
