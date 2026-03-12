#include "menu_core_initmainmenu.h"

void eStruct2038160_clearStruct(void)
{
    ZeroFillByWord(&eStruct2038160, 4);
}

int sub_8020140(void)
{
    int result;

    result = test0x200bc50_0x5_813D60C();
    if (result && eStruct200BC30_getJumpOffset00() == 12) {
        sub_813D66C();
        result = sub_803C620();
        eStruct2038160.battleTerminate01 = result;
    }

    return result;
}

int eStruct2038160_getBattleTerminate01(void)
{
    return eStruct2038160.battleTerminate01;
}
