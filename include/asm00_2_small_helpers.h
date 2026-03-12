#ifndef ASM00_2_SMALL_HELPERS_H
#define ASM00_2_SMALL_HELPERS_H

struct EnemyInfo800F29C {
    unsigned char type;
    unsigned char kind;
    unsigned char side;
};

struct BattleObject800F2AA {
    unsigned char pad0[0x28];
    unsigned short nameId;
};

register struct BattleObject800F2AA *gBattleObject800F2AA asm("r5");

struct EnemyInfo800F29C *sub_80182B4(int nameId);
void nullsub_3(void);

int sub_800F29C(int nameId);
void sub_800F2AA(void);

#endif
