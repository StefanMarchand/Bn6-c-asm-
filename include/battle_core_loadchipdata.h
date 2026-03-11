#ifndef BATTLE_CORE_LOADCHIPDATA_H
#define BATTLE_CORE_LOADCHIPDATA_H

struct ChipData {
    unsigned int codes;
    unsigned char attackElement;
    unsigned char rarity;
    unsigned char chipElement;
    unsigned char libraryType;
    unsigned char mb;
    unsigned char effectFlags;
    unsigned char staminaDamageCounterFrames;
    unsigned char attackFamily;
    unsigned char attackSubFamily;
    unsigned char darkSoulUsage;
    unsigned char unk_0e;
    unsigned char lockOnEnable;
    unsigned char attackParam1;
    unsigned char attackParam2;
    unsigned char attackParam3;
    unsigned char attackParam4;
    unsigned char lockoutFrames;
};

struct BattleObject {
    unsigned char pad0[0x16];
    unsigned char alliance;
    unsigned char directionFlip;
    unsigned char pad1[0x40];
    void *aiDataPtr;
};

struct AIAttackVars {
    unsigned char unk_00;
    unsigned char unk_01;
    unsigned char hitFlags;
    unsigned char attackSubFamily;
    unsigned char unk_04;
    unsigned char lockoutFrames;
    unsigned short attackBoost;
    unsigned int damage;
    unsigned short unk_0a;
    unsigned int hitboxFlags;
    unsigned short chipId;
};

register struct BattleObject *gBattleObject asm("r5");
register struct AIAttackVars *gAIAttackVars asm("r7");

extern unsigned char byte_80129E4[];

struct ChipData *getChip8021DA8(int chipId);
int sub_80109A4(int chipId, int alliance);
void sub_8021D14(int alliance, int chipId);

int somethingWriteChipParams_80126E4(int chipId);
int loc_80126EA(int chipId);

#endif
