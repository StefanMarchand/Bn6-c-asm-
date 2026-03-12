#include "asm03_0_beast_helpers.h"

int sub_80265FE(int panelX, int panelY)
{
    if (sub_800E680(panelX, 2) == 0) {
        panelY = 2;
    }
    return (unsigned short)panelX | (panelY << 16);
}

int sub_802661C(void)
{
    return gBattleObjectPanelPos->panelX | (gBattleObjectPanelPos->panelY << 8);
}
