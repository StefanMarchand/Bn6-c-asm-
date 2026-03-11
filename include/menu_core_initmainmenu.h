#ifndef MENU_CORE_INITMAINMENU_H
#define MENU_CORE_INITMAINMENU_H

struct Joypad {
    unsigned short held;
};

struct BattleState {
    unsigned char pad0[0x11];
    unsigned char unk_11;
    unsigned char pad1[2];
    unsigned char unk_14;
    unsigned char unk_15;
};

struct Toolkit {
    unsigned char pad0[4];
    struct Joypad *joypad;
    unsigned char pad1[0x10];
    struct BattleState *battleState;
};

struct MenuTransferState {
    unsigned char active;
    unsigned char unk_01;
    unsigned char flags;
    signed char timer;
};

struct MenuTransferBuffer {
    unsigned char pad0[2];
    unsigned short held;
    signed char transferIndex;
    unsigned char pad5;
    unsigned char battleStateValue;
    unsigned char pad7;
    unsigned int transferValue;
    unsigned short unk_0c;
};

struct MenuTransferWordTarget {
    unsigned char pad0[0x2c];
    unsigned short value;
};

register struct Toolkit *gToolkit asm("r10");

extern struct MenuTransferState eStruct203F7D8;
extern struct MenuTransferBuffer eStruct2036780;
extern struct MenuTransferBuffer unk_20399F0;
extern struct MenuTransferBuffer unk_2039A00;
extern struct MenuTransferWordTarget unk_2036120;
extern struct MenuTransferWordTarget unk_20362F0;
extern unsigned int dword_203F4A0[];
extern unsigned int dword_203F5A0[];
extern unsigned int dword_203CBE0[];

void sub_800A0D6(int side, unsigned short flags);
unsigned short sub_803F740(int arg0);

int sub_801FFD6(int stateFlags);

#endif
