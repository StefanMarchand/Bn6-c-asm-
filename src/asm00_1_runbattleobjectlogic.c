#include "asm00_1_battle_objects.h"

static void (*const *const BattleObjectFunctionJumptableTable[])(void) = {
    0,
    T1BattleObjectJumptable,
    0,
    T3BattleObjectJumptable,
    T4BattleObjectJumptable,
};

int RunBattleObjectLogic(void)
{
    struct BattleObjectLinkedList *current;

    object_Clear3RAMBytes_800371A();
    current = &eBattleObjectsLinkedListStart;
    while (1) {
        struct BattleObjectRuntime *object;

        current = current->next;
        if (current == &eBattleObjectsLinkedListSentinel) {
            break;
        }

        eUnkBattleObjectLinkedList.prev = current;
        object = (struct BattleObjectRuntime *)((unsigned char *)current + 0x10);
        if (!gToolkit->gameState->battlePaused || (object->flags & 4) != 0) {
            if (!battle_isTimeStop() || (object->flags & 0x10) != 0) {
                BattleObjectFunctionJumptableTable[object->type & 0x0F][object->index]();
            }
        }

        object_800372A();
    }

    eUnkBattleObjectLinkedList.prev = 0;
    return 0;
}
