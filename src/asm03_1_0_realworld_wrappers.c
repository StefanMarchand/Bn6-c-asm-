#include "asm03_1_0_realworld_wrappers.h"

void noop_8033A7C(void)
{
}

void sub_8033A80(void)
{
    sub_8033B80(0);
    sub_8033F80(0);
    gfxTransfer_8033DA0(0);
}

void onUpdateInRealWorld_8033A96(void)
{
    sub_8033B80(0);
    sub_8033F80(0);
    sub_8033BE8();
    gfxTransfer_8033DA0(0);
}

void sub_8033AB0(void)
{
    sub_8033B80(0);
    sub_8033F80(0);
    sub_8033C68();
}

void sub_8033AC4(void)
{
    sub_8033B80(0);
    sub_8033F80(0);
    sub_8033C68();
    sub_8033BE8();
}
