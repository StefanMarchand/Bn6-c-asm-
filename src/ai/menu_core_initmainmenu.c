#include "menu_core_initmainmenu.h"

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
