#ifndef ASM03_0_BEAST_HELPERS_H
#define ASM03_0_BEAST_HELPERS_H

struct BattleObjectPanelPos {
    unsigned char pad0[0x12];
    unsigned char panelX;
    unsigned char panelY;
    unsigned char alliance;
    unsigned char directionFlip;
};

register struct BattleObjectPanelPos *gBattleObjectPanelPos asm("r5");
register int gBeastSearchPanelX asm("r6");
register int gBeastSearchPanelY asm("r7");

int object_getFrontDirection(void);
int sub_800E680(int panelX, int panelY);
int sub_8026510(int panelX, int panelY, int limitX);
int sub_80265D0(const signed char *offsets);

int sub_8026450(int panelX, int panelY, const signed char *offsets);
int sub_80264A8(int panelX, int panelY, const signed char *offsets);
int sub_80265FE(int panelX, int panelY);
int sub_802661C(void);
int sub_8026622(void);
int sub_8026650(void);
int sub_802665A(void);
int sub_8026668(void);
int sub_8026672(void);
int sub_802667C(void);
int sub_802668A(void);
int sub_8026694(void);
int sub_802669E(void);
int sub_80266AC(void);
int sub_80266BA(void);
int sub_80266DE(void);

#endif
