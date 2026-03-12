#include "asm03_0_beast_helpers.h"

static const signed char sBeastSearchOffsets_8026753[] = {-1, 0, -1, -1, -1, 1, 0x7F};
static const signed char sBeastSearchOffsets_802675A[] = {-1, -1, -1, 1, -1, 0, 0x7F};
static const signed char sBeastSearchOffsets_8026761[] = {-2, 0, -1, 0, -2, -1, -1, -1, -2, 1, -1, 1, 0x7F};
static const signed char sBeastSearchOffsets_802676E[] = {-3, 0, -2, 0, -1, 0, -3, -1, -2, -1, -1, -1, -3, 1, -2, 1, -1, 1, 0x7F};
static const signed char sBeastSearchOffsets_8026781[] = {-1, 0, -1, -1, -1, 1, -2, 0, -2, -1, -2, 1, 0x7F};

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
