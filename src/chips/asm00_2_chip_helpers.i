# 0 "src/chips/asm00_2_chip_helpers.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "src/chips/asm00_2_chip_helpers.c"
# 1 "include/asm00_2_chip_helpers.h" 1



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
# 2 "src/chips/asm00_2_chip_helpers.c" 2

static struct BattleObject800EDHelpers *sBattleObject;
static struct PlayerChipState800ED *sPlayerChipState;
static struct AIAttackVars800ED *sAIAttackVars;

int sub_800EDD0(struct BattleObject800EDHelpers *obj, int arg1)
{
    unsigned char *hand;
    unsigned char handIndex;
    unsigned char *selectedChip;
    register int result asm("r0");
    register int chipCode asm("r1");
    register int damage asm("r2");
    register int chipsHeld asm("r3");

    if (sub_800F29C(obj->nameId) == 2) {
        hand = getBattleHandAddr_8010018(obj->alliance);
        handIndex = hand[0];
        selectedChip = hand + handIndex * 2 + 2;
        result = sub_800EF34(*(unsigned short *)(selectedChip + 0x00), arg1);
        chipCode = *(unsigned short *)(selectedChip + 0x0C);
        damage = *(unsigned short *)(selectedChip + 0x18)
            + result
            + *(unsigned short *)(selectedChip + 0x24);
        chipsHeld = (hand[0x3E + handIndex] << 8) + hand[0x44 + handIndex];
        result = *(unsigned short *)(selectedChip + 0x00);
    } else {
        result = obj->chip;
        chipCode = 0;
        damage = 0;
        chipsHeld = obj->chipsHeld;
    }

    return result;
}

int sub_800EE26(struct BattleObject800EDHelpers *obj)
{
    struct ChipData800EDHelpers *chipData;
    register int result asm("r0");
    register int chipCode asm("r1");
    register int damage asm("r2");
    register int attackFamily asm("r3");

    sBattleObject = obj;
    if (sub_800F29C(obj->nameId) == 2) {
        sPlayerChipState = sub_802E070(obj->alliance);
        sub_800EE98();
        result = sub_800EF34(sPlayerChipState->chipId, 0);
        chipData = getChip8021DA8(sPlayerChipState->chipId);
        if (sAIAttackVars != 0) {
            sAIAttackVars->unk_1d = chipData->attackFamily;
        }
        chipCode = sub_80109A4(sPlayerChipState->chipId, obj->alliance);
        damage = result;
        if ((chipData->flags & 2) != 0) {
            damage += sPlayerChipState->addDamage;
            sPlayerChipState->addDamage = 0;
        }
        if ((chipData->flags & 4) != 0) {
            damage += sPlayerChipState->counterDamage;
            sPlayerChipState->counterDamage = 0;
        }
        attackFamily = 0;
        result = sPlayerChipState->chipId;
    } else {
        result = obj->chip;
        chipCode = 0;
        damage = 0;
        attackFamily = obj->chipsHeld;
    }

    return result;
}

void sub_800EE98(void)
{
    struct ChipData800EDHelpers *chipData;
    unsigned short delta;
    int value;

    value = sub_802E830(sBattleObject->alliance, sPlayerChipState->chipId);
    if (!battle_networkInvert(sBattleObject->alliance)) {
        sub_801E2BA(value);
        PlaySoundEffect(0x8D, 0, 0);
    }

    chipData = getChip8021DA8(sPlayerChipState->chipId);
    if ((chipData->unk_16 & 0x80) == 0) {
        delta = *(unsigned short *)((unsigned char *)"\x00\x15\x00\x2A\x00\x40\xFF\xFF\xFF\xFF" + chipData->elemIdx * 2);
        word_200F3C4[(unsigned int)sPlayerChipState] = delta;
        if (sPlayerChipState->hp >= delta) {
            sPlayerChipState->hp -= delta;
        } else {
            sPlayerChipState->hp = 0;
        }
    }
}

int sub_800EF02(int chipId)
{
    register int result asm("r0");
    register int chipCode asm("r1");
    register int damage asm("r2");
    register int chipsHeld asm("r3");

    if (sub_800F29C(sBattleObject->nameId) == 2) {
        damage = sub_800EF34(chipId, 0);
        chipCode = sub_80109A4(chipId, sBattleObject->alliance);
        result = chipId;
    } else {
        result = sBattleObject->chip;
        chipCode = 0;
        damage = 0;
        chipsHeld = sBattleObject->chipsHeld;
    }

    return result;
}
