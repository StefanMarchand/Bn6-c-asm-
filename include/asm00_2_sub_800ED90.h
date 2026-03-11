#ifndef ASM00_2_SUB_800ED90_H
#define ASM00_2_SUB_800ED90_H

struct BattleObject800ED90 {
    unsigned char pad0[0x16];
    unsigned char alliance;
    unsigned char pad1[3];
    unsigned char chipsHeld;
    unsigned char pad2[0x0D];
    unsigned short nameId;
    unsigned short chip;
};

int sub_800F29C(int nameId);
unsigned char *getBattleHandAddr_8010018(int alliance);
int sub_800EF34(int chipId, int arg1);

int sub_800ED90(struct BattleObject800ED90 *obj);

#endif
