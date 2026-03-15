#include "mapgroup_spawn_helpers.h"

void *ExpoSite_EnterMapGroup(void)
{
    int mapGroup = gGameState->mapGroup;
    int mapNumber = gGameState->mapNumber;

    gToolkit->warpState->warpDataPtr = off_8062728[mapNumber];
    initMapTilesState_803037c(mapGroup, mapNumber);
    decompressCoordEventData_8030aa4(mapGroup, mapNumber);
    camera_init_802FF4C(gGameState->playerX, gGameState->playerY, gGameState->playerZ, mapGroup, mapNumber);
    decompAndCopyMapTiles_8030472();
    initUncompSpriteState_80028d4(unk_2037800);
    uncompSprite_8002906(off_8062B1C[mapNumber]);
    chatbox_uncompMapTextArchives_803FD08();
    ExpoSite_SpawnMapObjectsForMap();
    gGameState->unk_64 = off_8063008[mapNumber];
    return gGameState->unk_64;
}
