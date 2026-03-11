#include "asm00_2_sub_800ED90.h"

int sub_800ED90(struct BattleObject800ED90 *obj)
{
    unsigned char *hand;
    unsigned short *selectedChip;
    register int result asm("r0");
    register int chipCode asm("r1");
    register int damage asm("r2");
    register int chipsHeld asm("r3");

    if (sub_800F29C(obj->nameId) == 2) {
        hand = getBattleHandAddr_8010018(obj->alliance);
        selectedChip = (unsigned short *)(hand + hand[0] * 2 + 2);
        result = sub_800EF34(selectedChip[0], 0);
        damage = selectedChip[0x18 / 2] + result + selectedChip[0x24 / 2];
        chipCode = selectedChip[0x0C / 2];
        result = selectedChip[0];
    } else {
        result = obj->chip;
        chipCode = 0;
        damage = 0;
    }

    chipsHeld = obj->chipsHeld;
    return result;
}
