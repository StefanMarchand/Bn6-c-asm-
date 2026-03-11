#include "battle_core_loadchipdata.h"

static int battle_core_loadchipdata_impl(int chipId, struct AIAttackVars *attackVars, int updateChipUsage)
{
    struct ChipData *chipData;

    attackVars->chipId = chipId;
    chipData = getChip8021DA8(chipId);
    attackVars->hitboxFlags = *(unsigned int *)&chipData->attackParam1;
    attackVars->damage = ((unsigned int)chipData->staminaDamageCounterFrames << 16)
        + sub_80109A4(attackVars->chipId, gBattleObject->alliance);
    attackVars->lockoutFrames = chipData->lockoutFrames;
    attackVars->attackBoost = 0;
    attackVars->attackSubFamily = chipData->attackSubFamily;
    attackVars->hitFlags = chipData->attackElement | byte_80129E4[chipData->chipElement];
    attackVars->unk_04 = 0;
    if (updateChipUsage) {
        sub_8021D14(gBattleObject->alliance, attackVars->chipId);
    }
    return chipData->attackFamily;
}

int somethingWriteChipParams_80126E4(int chipId)
{
    return battle_core_loadchipdata_impl(chipId, (struct AIAttackVars *)((unsigned char *)gBattleObject->aiDataPtr + 0xA0), 1);
}

int loc_80126EA(int chipId)
{
    return battle_core_loadchipdata_impl(chipId, gAIAttackVars, 0);
}
