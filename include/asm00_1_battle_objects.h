#ifndef ASM00_1_BATTLE_OBJECTS_H
#define ASM00_1_BATTLE_OBJECTS_H

struct BattleObjectLinkedList {
    struct BattleObjectLinkedList *prev;
    struct BattleObjectLinkedList *next;
    unsigned char pad[8];
    unsigned char size;
};

extern struct BattleObjectLinkedList eBattleObjectsLinkedListStart;
extern struct BattleObjectLinkedList eBattleObjectsLinkedListSentinel;
extern struct BattleObjectLinkedList eUnkBattleObjectLinkedList;

struct BattleObjectLinkedList *sub_800318C(void);

#endif
