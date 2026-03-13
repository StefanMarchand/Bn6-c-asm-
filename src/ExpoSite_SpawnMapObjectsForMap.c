```c
#include "global.h"
#include "map.h"

// Static prototypes for helper functions referenced in the existing sketch
static void SpawnMapObjectsForExpoSite(u16 mapId);

void ExpoSite_SpawnMapObjectsForMap(u16 mapId) {
    SpawnMapObjectsForExpoSite(mapId);
}

static void SpawnMapObjectsForExpoSite(u16 mapId) {
    // Map-group object spawning logic for the asm09 Expo Site area
    // This wrapper handles the specific initialization for this zone
    switch (mapId) {
        case MAP_GROUP_EXPO_SITE_0:
            SpawnMapObjectsForMapGroup(MAP_GROUP_EXPO_SITE_0);
            break;
        case MAP_GROUP_EXPO_SITE_1:
            SpawnMapObjectsForMapGroup(MAP_GROUP_EXPO_SITE_1);
            break;
        case MAP_GROUP_EXPO_SITE_2:
            SpawnMapObjectsForMapGroup(MAP_GROUP_EXPO_SITE_2);
            break;
        default:
            SpawnMapObjectsForMapGroup(mapId);
            break;
    }
}
```
