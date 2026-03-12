#include "asm03_1_0_small_helpers.h"

void sub_80342DC(void)
{
    gPetUpdateSmall->state = 4;
}

void sub_80342E4(void)
{
    gPetUpdateSmall->state = 8;
}

void sub_80342EC(void)
{
    *gToolkitJackIn->mainJumptableIndexPtr = 4;
    zeroFillVRAM();
    ZeroFillGFX30025c0();
    gToolkitJackIn->gameState->enterMapFadeParam1 = 0;
    gToolkitJackIn->gameState->enterMapFadeParam2 = 0x10;
    map_triggerEnterMapOnWarp_8005C04();
    navi_80340F6();
}
