#include "asm00_2_small_helpers.h"

int sub_800F29C(int nameId)
{
    struct EnemyInfo800F29C *enemyInfo;
    register int result asm("r0");
    register int side asm("r1");
    register int type asm("r2");

    enemyInfo = sub_80182B4(nameId);
    type = enemyInfo->type;
    side = enemyInfo->side;
    result = enemyInfo->kind;
    return result;
}

void sub_800F2AA(void)
{
    (void)gBattleObject800F2AA->nameId;
    nullsub_3();
}
