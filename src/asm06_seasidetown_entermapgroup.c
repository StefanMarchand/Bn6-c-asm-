#include "mapgroup_spawn_helpers.h"

void *SeasideTown_EnterMapGroup(void)
{
    int mapGroup = gGameState->mapGroup;
    int mapNumber = gGameState->mapNumber;

    gToolkit->warpState->warpDataPtr = off_8059294[mapNumber];
    initMapTilesState_803037c(mapGroup, mapNumber);
    decompressCoordEventData_8030aa4(mapGroup, mapNumber);
    camera_init_802FF4C(gGameState->playerX, gGameState->playerY, gGameState->playerZ, mapGroup, mapNumber);
    decompAndCopyMapTiles_8030472();
    initUncompSpriteState_80028d4(unk_2037800);
    uncompSprite_8002906(off_8059624[mapNumber]);
    chatbox_uncompMapTextArchives_803FD08();
    SeasideTown_SpawnMapObjectsForMap();
    gGameState->unk_64 = off_8059DE8[mapNumber];
    return gGameState->unk_64;
}
