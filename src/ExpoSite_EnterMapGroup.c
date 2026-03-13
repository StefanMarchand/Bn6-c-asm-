```c
#include "global.h"
#include "map.h"
#include "overworld.h"
#include "constants/map_groups.h"

static void ExpoSite_InitMap(void);
static void ExpoSite_SetupCamera(void);

void ExpoSite_EnterMapGroup(void) {
    gCurrentMapGroup = MAP_GROUP_EXPO_SITE;
    gCurrentMap = 0;
    ExpoSite_InitMap();
    ExpoSite_SetupCamera();
    gNPCGroupPtr = ExpoSite_NPCGroup;
    gWarpGroupPtr = ExpoSite_WarpGroup;
    gTriggerGroupPtr = ExpoSite_TriggerGroup;
    gMapConnectionGroupPtr = ExpoSite_MapConnectionGroup;
    gSignGroupPtr = ExpoSite_SignGroup;
}

static void ExpoSite_InitMap(void) {
    LoadMapTileset(&ExpoSite_Tileset);
    LoadMapPalette(&ExpoSite_Palette);
    LoadMapEvents(&ExpoSite_Events);
    gMapPixelOffsetX = 0;
    gMapPixelOffsetY = 0;
    gMapColumns = 32;
    gMapRows = 32;
    gMapLayoutPtr = ExpoSite_MapLayout;
}

static void ExpoSite_SetupCamera(void) {
    gCameraPixelX = 0;
    gCameraPixelY = 0;
    gCameraTargetX = 0;
    gCameraTargetY = 0;
    SetCameraBounds(0, 0, 512, 512);
}
```
