# 0 "src/ai/menu_core_initmainmenu.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "src/ai/menu_core_initmainmenu.c"
# 1 "include/menu_core_initmainmenu.h" 1



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
int sub_803EA2C(void);
# 2 "src/ai/menu_core_initmainmenu.c" 2

int sub_801FF18(int stateFlags)
{
    struct MenuTransferState *menuState;
    struct BattleState *battleState;
    struct MenuTransferBuffer *buffer;

    if (stateFlags != 2) {
        return stateFlags;
    }

    menuState = &eStruct203F7D8;
    battleState = gToolkit->battleState;


    buffer = &unk_20399F0;
    if (buffer->held & 0xFC00) {
        sub_800A0D6(0, buffer->held);
        battleState->unk_14 = buffer->battleStateValue;
        unk_2036120.value = buffer->unk_0c;
        if (buffer->transferIndex >= 0) {
            dword_203F4A0[(int)buffer->transferIndex] = buffer->transferValue;
        }
    }


    buffer = &unk_2039A00;
    if (!menuState->active || (buffer->held & 0xFC00)) {
        sub_800A0D6(1, buffer->held);
        battleState->unk_15 = buffer->battleStateValue;
        unk_20362F0.value = buffer->unk_0c;
        if (buffer->transferIndex >= 0) {
            dword_203F5A0[(int)buffer->transferIndex] = buffer->transferValue;
        }
    }


    buffer = &eStruct2036780;
    buffer->held = gToolkit->joypad->held;
    buffer->battleStateValue = battleState->unk_11;
    buffer->unk_0c = sub_803F740(4);

    if (menuState->flags & 1) {
        if (sub_803EA2C()) {
            return stateFlags;
        }
        {
            signed char timer;
            timer = menuState->timer - 1;
            menuState->timer = timer;
            if (timer >= 0) {
                buffer->transferIndex = timer;
                stateFlags = dword_203CBE0[(int)timer];
                buffer->transferValue = stateFlags;
                return stateFlags;
            }
        }
    }

    menuState->flags &= (unsigned char)~1;
    stateFlags = 0xFF;
    buffer->transferIndex = -1;
    return stateFlags;
}

int sub_801FFD6(int stateFlags)
{
    struct MenuTransferState *menuState;
    struct BattleState *battleState;
    struct MenuTransferBuffer *buffer;
    unsigned char originalStateFlags;

    originalStateFlags = stateFlags;
    if (stateFlags == 1) {
        return stateFlags;
    }

    menuState = &eStruct203F7D8;
    battleState = gToolkit->battleState;
    if (!(stateFlags & 8)) {
        buffer = &unk_20399F0;
        if (buffer->held & 0xFC00) {
            sub_800A0D6(0, buffer->held);
            battleState->unk_14 = buffer->battleStateValue;
            unk_2036120.value = buffer->unk_0c;
            if (buffer->transferIndex >= 0) {
                dword_203F4A0[(int)buffer->transferIndex] = buffer->transferValue;
            }
        }

        buffer = &unk_2039A00;
        if (!menuState->active || (buffer->held & 0xFC00)) {
            sub_800A0D6(1, buffer->held);
            battleState->unk_15 = buffer->battleStateValue;
            unk_20362F0.value = buffer->unk_0c;
            if (buffer->transferIndex >= 0) {
                dword_203F5A0[(int)buffer->transferIndex] = buffer->transferValue;
            }
        }
    }

    if (!(originalStateFlags & 0x10)) {
        buffer = &eStruct2036780;
        buffer->held = gToolkit->joypad->held;
        buffer->battleStateValue = battleState->unk_11;
        buffer->unk_0c = sub_803F740(4);
        if (menuState->flags & 1) {
            signed char transferIndex;

            transferIndex = menuState->timer - 1;
            menuState->timer = transferIndex;
            if (transferIndex >= 0) {
                buffer->transferIndex = transferIndex;
                stateFlags = dword_203CBE0[(int)transferIndex];
                buffer->transferValue = stateFlags;
                return stateFlags;
            }
        }

        menuState->flags &= (unsigned char)~1;
        stateFlags = 0xFF;
        buffer->transferIndex = -1;
    }

    return stateFlags;
}
