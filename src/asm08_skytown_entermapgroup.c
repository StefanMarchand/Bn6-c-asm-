#include "mapgroup_spawn_helpers.h"

void *SkyTown_EnterMapGroup(void)
{
    int mapGroup = gGameState->mapGroup;
    int mapNumber = gGameState->mapNumber;

    gToolkit->warpState->warpDataPtr = off_8060184[mapNumber];
    initMapTilesState_803037c(mapGroup, mapNumber);
    decompressCoordEventData_8030aa4(mapGroup, mapNumber);
    camera_init_802FF4C(gGameState->playerX, gGameState->playerY, gGameState->playerZ, mapGroup, mapNumber);
    decompAndCopyMapTiles_8030472();
    initUncompSpriteState_80028d4(unk_2037800);
    uncompSprite_8002906(off_80603D8[mapNumber]);
    chatbox_uncompMapTextArchives_803FD08();
    SkyTown_SpawnMapObjectsForMap();
    gGameState->unk_64 = off_80606BC[mapNumber];
    return gGameState->unk_64;
}
