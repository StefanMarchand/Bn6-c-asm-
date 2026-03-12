#ifndef MAPGROUP_SPAWN_HELPERS_H
#define MAPGROUP_SPAWN_HELPERS_H

struct GameStateMapGroup {
    unsigned char pad0[5];
    unsigned char mapNumber;
};

struct ToolkitMapGroup {
    unsigned char pad0[0x3C];
    struct GameStateMapGroup *gameState;
};

register struct ToolkitMapGroup *gToolkit asm("r10");

extern void *off_804E6E4[];
extern void *off_804E738[];
extern void *off_8052778[];
extern void *off_8052808[];
extern void *off_8059678[];
extern void *off_80596E0[];

int LoadGFXAnims(void *data);
int SpawnObjectsFromList(void *data);

int CentralTown_LoadGFXAnims(int unused, int mapNumber);
int CentralTown_SpawnMapObjectsForMap(void);
int CyberAcademy_LoadGFXAnims(int unused, int mapNumber);
int CyberAcademy_SpawnMapObjectsForMap(void);
int SeasideTown_LoadGFXAnims(int unused, int mapNumber);
int SeasideTown_SpawnMapObjectsForMap(void);

#endif
