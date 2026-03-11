#ifndef ASM00_2_CHIP_HELPERS_H
#define ASM00_2_CHIP_HELPERS_H

struct BattleObject800EDHelpers {
    unsigned char pad0[0x16];
    unsigned char alliance;
    unsigned char pad1[3];
    unsigned char chipsHeld;
    unsigned char pad2[0x0D];
    unsigned short nameId;
    unsigned short chip;
};

struct PlayerChipState800ED {
    unsigned char pad0[0x28];
    unsigned short hp;
    unsigned char pad1[0x0A];
    unsigned short chipId;
    unsigned short addDamage;
    unsigned short counterDamage;
};

struct ChipData800EDHelpers {
    unsigned char pad0[7];
    unsigned char elemIdx;
    unsigned char pad1;
    unsigned char flags;
    unsigned char pad2[5];
    unsigned char attackFamily;
    unsigned char pad3[6];
    unsigned char unk_16;
};

struct AIAttackVars800ED {
    unsigned char pad0[0x1D];
    unsigned char unk_1d;
};

extern unsigned short word_200F3C4[];

int PlaySoundEffect(int songId, int arg1, int arg2);
int battle_networkInvert(int alliance);
unsigned char *getBattleHandAddr_8010018(int alliance);
struct ChipData800EDHelpers *getChip8021DA8(int chipId);
struct PlayerChipState800ED *sub_802E070(int alliance);
int sub_800EF34(int chipId, int arg1);
int sub_800F29C(int nameId);
int sub_80109A4(int chipId, int alliance);
int sub_801E2BA(int value);
int sub_802E830(int alliance, int chipId);

int sub_800EDD0(struct BattleObject800EDHelpers *obj, int arg1);
int sub_800EE26(struct BattleObject800EDHelpers *obj);
void sub_800EE98(void);
int sub_800EF02(int chipId);

#endif
