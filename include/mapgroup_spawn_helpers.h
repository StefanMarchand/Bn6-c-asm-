#ifndef MAPGROUP_SPAWN_HELPERS_H
#define MAPGROUP_SPAWN_HELPERS_H

struct WarpStateMapGroup {
    unsigned char pad0[0x14];
    void *warpDataPtr;
};

struct GameStateMapGroup {
    unsigned char pad0[4];
    unsigned char mapGroup;
    unsigned char mapNumber;
    unsigned char pad6[0x1E];
    unsigned int playerX;
    unsigned int playerY;
    unsigned int playerZ;
    unsigned char pad30[0x34];
    void *unk_64;
};

struct ToolkitMapGroup {
    unsigned char pad0[0x14];
    struct WarpStateMapGroup *warpState;
    unsigned char pad18[0x24];
    struct GameStateMapGroup *gameState;
};

register struct ToolkitMapGroup *gToolkit asm("r10");
register struct GameStateMapGroup *gGameState asm("r5");

extern void *unk_2037800;
extern void *off_804E38C[];
extern void *off_804E6E4[];
extern void *off_804E698[];
extern void *off_804E9CC[];
extern void *off_804E738[];
extern void *off_8052244[];
extern void *off_80526F4[];
extern void *off_8052778[];
extern void *off_8052EE8[];
extern void *off_8052808[];
extern void *off_8059294[];
extern void *off_8059624[];
extern void *off_8059678[];
extern void *off_8059DE8[];
extern void *off_80596E0[];

int initMapTilesState_803037c(int mapGroup, int mapNumber);
int decompressCoordEventData_8030aa4(int mapGroup, int mapNumber);
int camera_init_802FF4C(unsigned int playerX, unsigned int playerY, unsigned int playerZ, int mapGroup, int mapNumber);
int decompAndCopyMapTiles_8030472(void);
int initUncompSpriteState_80028d4(void *state);
int uncompSprite_8002906(void *spriteLoadData);
int chatbox_uncompMapTextArchives_803FD08(void);
int LoadGFXAnims(void *data);
int SpawnObjectsFromList(void *data);

void *CentralTown_EnterMapGroup(void);
int CentralTown_LoadGFXAnims(int unused, int mapNumber);
int CentralTown_SpawnMapObjectsForMap(void);
void *CyberAcademy_EnterMapGroup(void);
int CyberAcademy_LoadGFXAnims(int unused, int mapNumber);
int CyberAcademy_SpawnMapObjectsForMap(void);
void *SeasideTown_EnterMapGroup(void);
int SeasideTown_LoadGFXAnims(int unused, int mapNumber);
int SeasideTown_SpawnMapObjectsForMap(void);

#endif
