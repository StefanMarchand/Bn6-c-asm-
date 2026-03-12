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

struct BattleTerminateState {
    unsigned char pad0;
    unsigned char battleTerminate01;
    unsigned char pad2[2];
};

register struct Toolkit *gToolkit asm("r10");

extern struct MenuTransferState eStruct203F7D8;
extern struct MenuTransferBuffer eStruct2036780;
extern struct MenuTransferBuffer unk_20399F0;
extern struct MenuTransferBuffer unk_2039A00;
extern struct BattleTerminateState eStruct2038160;
extern struct MenuTransferWordTarget unk_2036120;
extern struct MenuTransferWordTarget unk_20362F0;
extern unsigned int dword_203F4A0[];
extern unsigned int dword_203F5A0[];
extern unsigned int dword_203CBE0[];

int GetBattleEffects(void);
int notZero_eByte200AD04(void);
void sub_800A0D6(int side, unsigned short flags);
void sub_803DCE8(int arg0, int arg1, int arg2, int arg3);
void sub_803DE88(int arg0, int arg1, int arg2, int arg3);
int sub_803DEB4(void);
unsigned short sub_803F740(int arg0);
void CopyWords(const void *src, void *dest, int size);
void ZeroFillByWord(void *memBlock, int size);
int test0x200bc50_0x5_813D60C(void);
int eStruct200BC30_getJumpOffset00(void);
void sub_813D66C(void);
int sub_803C620(void);
int sub_8144D04(int arg0);

int sub_801FF18(int stateFlags);
int sub_801FFD6(int stateFlags);

#endif
