#include "asm03_0_beast_helpers.h"

static const signed char sBeastPanelSearchRowOffsets_8026730[] = {-1, 1, -2, 2, 0x7F};
static const signed char sBeastPanelSearchSameRowOffsets_802673A[] = {1, 0};
static const signed char sBeastPanelSearchOffsets_802673C[] = {
    0, 0, 1, 0, -1, 0, 2, 0, -2, 0, 3, 0, -3, 0, 4, 0, -4, 0, 5, 0, -5, 0, 0x7F
};

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

int sub_8026622(void)
{
    int panelY;
    const signed char *searchOffsets;
    const signed char *rowOffsets;
    int result;

    panelY = gBeastSearchPanelY;
    searchOffsets = sBeastPanelSearchOffsets_802673C;
    if (panelY == gBattleObjectPanelPos->panelY) {
        searchOffsets = sBeastPanelSearchSameRowOffsets_802673A;
    }

    rowOffsets = sBeastPanelSearchRowOffsets_8026730;
    while (1) {
        result = sub_8026450(gBattleObjectPanelPos->panelX, panelY, searchOffsets);
        if (result) {
            break;
        }

        if (*rowOffsets == 0x7F) {
            break;
        }

        panelY = *rowOffsets + gBeastSearchPanelY;
        rowOffsets++;
        searchOffsets = sBeastPanelSearchOffsets_802673C;
    }

    return result;
}
