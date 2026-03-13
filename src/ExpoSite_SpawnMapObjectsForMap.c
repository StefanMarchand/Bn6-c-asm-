```c
#include "global.h"
#include "map/object.h"
#include "asm09.h"

static void ExpoSite_SpawnMapObjectsForMap(int mapId) {
    // Spawn map objects for the ExpoSite area based on map group
    SpawnMapObjectsForMapGroup(mapId, EXPO_SITE_MAP_GROUP);
}

// Minimal static prototype if needed elsewhere in translation unit
static void ExpoSite_SpawnMapObjectsForMap(int mapId);
```
