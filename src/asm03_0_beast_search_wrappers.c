#include "asm03_0_beast_helpers.h"

static const signed char sBeastSearchOffsets_8026753[] = {-1, 0, -1, -1, -1, 1, 0x7F};
static const signed char sBeastSearchOffsets_802675A[] = {-1, -1, -1, 1, -1, 0, 0x7F};
static const signed char sBeastSearchOffsets_8026761[] = {-2, 0, -1, 0, -2, -1, -1, -1, -2, 1, -1, 1, 0x7F};
static const signed char sBeastSearchOffsets_802676E[] = {-3, 0, -2, 0, -1, 0, -3, -1, -2, -1, -1, -1, -3, 1, -2, 1, -1, 1, 0x7F};
static const signed char sBeastSearchOffsets_8026781[] = {-1, 0, -1, -1, -1, 1, -2, 0, -2, -1, -2, 1, 0x7F};
static const signed char sBeastSearchOffsets_802678E[] = {-2, 0, 0x7F};
static const signed char sBeastSearchOffsets_8026791[] = {-3, 0, 0x7F};
static const signed char sBeastSearchOffsets_8026794[] = {-2, 0, -2, -1, -2, 1, 0x7F};
static const signed char sBeastSearchOffsets_802679B[] = {-5, 0, -4, 0, -3, 0, -2, 0, -1, 0, 0x7F};
static const signed char sBeastSearchOffsets_80267A6[] = {0, 0, -2, 0, 0x7F};
static const signed char sBeastSearchOffsets_80267AB[] = {-1, 0, 0x7F};
static const signed char sBeastSearchOffsets_80267AE[] = {-1, 0, -2, -1, -2, 1, 1, -1, 1, 1, 0x7F};
static const signed char sBeastSearchOffsets_80267B9[] = {-3, 0, -4, 0, -3, -1, -3, 1, -4, -1, -4, 1, -2, 0, -2, -1, -2, 1, 0x7F};
static const signed char sBeastSearchOffsets_80267CC[] = {-2, 0, -2, -1, -2, 1, -1, 0, 0x7F};
static const signed char sBeastSearchOffsets_80267D5[] = {-1, 0, -1, -1, -1, 1, 0, -1, 0, 1, 1, -1, 1, 1, 1, 0, 0x7F};

int sub_8026650(void)
{
    return sub_80265D0(sBeastSearchOffsets_8026753);
}

int sub_802665A(void)
{
    return sub_80265FE(sub_80265D0(sBeastSearchOffsets_802675A), 0);
}

int sub_8026668(void)
{
    return sub_80265D0(sBeastSearchOffsets_8026761);
}

int sub_8026672(void)
{
    return sub_80265D0(sBeastSearchOffsets_802676E);
}

int sub_802667C(void)
{
    return sub_80265FE(sub_80265D0(sBeastSearchOffsets_8026781), 0);
}

int sub_802668A(void)
{
    return sub_80265D0(sBeastSearchOffsets_802678E);
}

int sub_8026694(void)
{
    return sub_80265D0(sBeastSearchOffsets_8026791);
}

int sub_802669E(void)
{
    return sub_80265FE(sub_80265D0(sBeastSearchOffsets_8026794), 0);
}

int sub_80266AC(void)
{
    return sub_80264A8(gBeastSearchPanelX, gBeastSearchPanelY, sBeastSearchOffsets_802679B);
}

int sub_80266BA(void)
{
    int offsetIndex;

    offsetIndex = 0;
    if ((((gBattleObjectPanelPos->alliance ^ gBattleObjectPanelPos->directionFlip) ^ 1) * 5) + 1 == gBeastSearchPanelX) {
        offsetIndex = 2;
    }

    return sub_80265D0(&sBeastSearchOffsets_80267A6[offsetIndex]);
}

int sub_80266DE(void)
{
    return sub_80265D0(sBeastSearchOffsets_80267AB);
}

int sub_80266E8(void)
{
    return sub_80265D0(sBeastSearchOffsets_80267AE);
}

int sub_80266F2(void)
{
    return sub_80265FE(sub_8026450(gBeastSearchPanelX, gBeastSearchPanelY, sBeastSearchOffsets_802679B), 0);
}

int sub_8026704(void)
{
    return sub_80265D0(sBeastSearchOffsets_80267B9);
}

int sub_802670E(void)
{
    return sub_80265FE(sub_80265D0(sBeastSearchOffsets_8026791), 0);
}

int sub_802671C(void)
{
    return sub_80265D0(sBeastSearchOffsets_80267CC);
}

int sub_8026726(void)
{
    return sub_80265D0(sBeastSearchOffsets_80267D5);
}
