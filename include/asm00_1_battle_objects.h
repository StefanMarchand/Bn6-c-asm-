#ifndef ASM00_1_BATTLE_OBJECTS_H
#define ASM00_1_BATTLE_OBJECTS_H

struct BattleObjectLinkedList {
    struct BattleObjectLinkedList *prev;
    struct BattleObjectLinkedList *next;
    unsigned char pad[8];
    unsigned char size;
};

struct BattleObjectRuntime {
    unsigned char flags;
    unsigned char index;
    unsigned char type;
};

struct GameState80031AC {
    unsigned char pad[0x0A];
    unsigned char battlePaused;
};

struct Toolkit80031AC {
    unsigned char pad[0x3C];
    struct GameState80031AC *gameState;
};

register struct Toolkit80031AC *gToolkit asm("r10");

extern struct BattleObjectLinkedList eBattleObjectsLinkedListStart;
extern struct BattleObjectLinkedList eBattleObjectsLinkedListSentinel;
extern struct BattleObjectLinkedList eUnkBattleObjectLinkedList;
extern void (*T1BattleObjectJumptable[])(void);
extern void (*T3BattleObjectJumptable[])(void);
extern void (*T4BattleObjectJumptable[])(void);

void object_Clear3RAMBytes_800371A(void);
int battle_isTimeStop(void);
void object_800372A(void);

struct BattleObjectLinkedList *sub_800318C(void);
int RunBattleObjectLogic(void);

#endif
