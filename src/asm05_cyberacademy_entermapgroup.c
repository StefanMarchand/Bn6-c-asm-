#include "mapgroup_spawn_helpers.h"

void *CyberAcademy_EnterMapGroup(void)
{
    int mapGroup = gGameState->mapGroup;
    int mapNumber = gGameState->mapNumber;

    gToolkit->warpState->warpDataPtr = off_8052244[mapNumber];
    initMapTilesState_803037c(mapGroup, mapNumber);
    decompressCoordEventData_8030aa4(mapGroup, mapNumber);
    camera_init_802FF4C(gGameState->playerX, gGameState->playerY, gGameState->playerZ, mapGroup, mapNumber);
    decompAndCopyMapTiles_8030472();
    initUncompSpriteState_80028d4(unk_2037800);
    uncompSprite_8002906(off_80526F4[mapNumber]);
    chatbox_uncompMapTextArchives_803FD08();
    CyberAcademy_SpawnMapObjectsForMap();
    gGameState->unk_64 = off_8052EE8[mapNumber];
    return gGameState->unk_64;
}
