#include "menu_core_initmainmenu.h"

int sub_801FE5E(void)
{
    return eStruct203F7D8.active;
}

int sub_801FE24(void)
{
    if (GetBattleEffects() & 8) {
        sub_803DCE8(0x10, 0, 2, 0);
    } else {
        if (!notZero_eByte200AD04()) {
            return 0;
        }

        sub_803DE88(0, 0, 0, 0);
        sub_803DCE8(0x10, 0, 2, 5);
    }

    eStruct203F7D8.active = 1;
    return 1;
}

int sub_801FE64(void)
{
    eStruct203F7D8.active = 0;
    return 0;
}

void sub_801FE6C(void)
{
    int previousState;

    previousState = eStruct203F7D8.unk_01;
    eStruct203F7D8.unk_01 = 2;
    if (eStruct203F7D8.active) {
        if (TestEventFlagFromImmediate(23, 45)) {
            eStruct203F7D8.unk_01 = previousState;
            if (previousState == 2 && (GetBattleEffects() & 8)
                && (sub_8144D04(0) != 1 || sub_8144D04(3) != 1)) {
                eStruct203F7D8.unk_01 = 4;
            }
        } else if (GetBattleEffects() & 8) {
            eStruct203F7D8.unk_01 = previousState;
        } else {
            eStruct203F7D8.unk_01 = sub_803DEB4();
        }
    } else {
        CopyWords(&eStruct2036780, &unk_20399F0, 0x10);
        CopyWords(&eStruct2036780, &unk_2039A00, 0x10);
    }
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
