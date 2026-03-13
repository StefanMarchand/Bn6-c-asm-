```c
#include "global.h"
#include "map_group.h"

// Function: ExpoSite_EnterMapGroup
// Address: 0x08062AB0
// Purpose: Map group entry loader for asm09 Expo Site area
static void ExpoSite_LoadTilesets(void);

void ExpoSite_EnterMapGroup(void)
{
    ExpoSite_LoadTilesets();
    SetMapGroupCallbacks(&ExpoSite_MapGroupCallbacks);
    LoadMapGroupEvents(ExpoSite_Events);
    SetMapGroupEncounters(&ExpoSite_Encounters);
}

static void ExpoSite_LoadTilesets(void)
{
    LoadPrimaryTileset(&gTileset_ExpoSite);
    LoadSecondaryTileset(&gTileset_ExpoSite_S);
    ApplyTilesetPalettes(&gTileset_ExpoSite);
}
```
