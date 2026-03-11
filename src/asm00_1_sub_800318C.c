#include "asm00_1_battle_objects.h"

struct BattleObjectLinkedList *sub_800318C(void)
{
    eUnkBattleObjectLinkedList.prev = 0;
    eBattleObjectsLinkedListStart.prev = 0;
    eBattleObjectsLinkedListStart.next = &eBattleObjectsLinkedListSentinel;
    eBattleObjectsLinkedListSentinel.prev = &eBattleObjectsLinkedListStart;
    eBattleObjectsLinkedListSentinel.next = 0;
    return &eBattleObjectsLinkedListStart;
}
