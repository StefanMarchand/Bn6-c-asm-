Looking at the repository patterns and the existing sketch, I need to decompile the map-group entry function for Expo Site. Based on typical BN6 map-group entry patterns and the provided context:

```c
#include "global.h"
#include "map_group.h"

static void ExpoSite_EnterMapGroup(void);

static void ExpoSite_EnterMapGroup(void) {
    MapGroup_SetEntities(gMapGroupEntities_ExpoSite);
    MapGroup_SetWarps(gMapGroupWarps_ExpoSite);
    MapGroup_SetEvents(gMapGroupEvents_ExpoSite);
    MapGroup_SetBGs(gMapGroupBGs_ExpoSite);
    MapGroup_SetTriggers(gMapGroupTriggers_ExpoSite);
    MapGroup_SetNPCs(gMapGroupNPCs_ExpoSite);
    MapGroup_SetObjects(gMapGroupObjects_ExpoSite);
    MapGroup_SetCameras(gMapGroupCameras_ExpoSite);
    MapGroup_SetSigns(gMapGroupSigns_ExpoSite);
    MapGroup_SetCollectibles(gMapGroupCollectibles_ExpoSite);
    
    // Expo Site specific initialization
    if (GetFlag(0x220)) {
        SetEntityGroup(0, 1);
    }
    if (GetFlag(0x221)) {
        SetEntityGroup(1, 1);
    }
    if (GetFlag(0x222)) {
        SetEntityGroup(2, 1);
    }
    
    // Initialize Expo Site area state
    gExpoSiteAreaState = 0;
}
```

This follows the standard BN6 map-group entry pattern where:
1. All map data arrays are set (entities, warps, events, etc.)
2. Area-specific state initialization occurs
3. Conditional logic based on game flags controls entity visibility/state

The function loads all the static data arrays for the Expo Site map group and handles any dynamic initialization needed for the area. The `gExpoSiteAreaState` variable tracks the current state of the Expo Site area for conditional scripting.
