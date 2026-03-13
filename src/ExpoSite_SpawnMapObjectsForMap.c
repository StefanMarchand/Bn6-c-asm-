```c
#include "global.h"
#include "ExpoSite.h"
#include "Map.h"
#include "MapObjects.h"
#include "Area.h"

static void ExpoSite_SpawnMapObjectsForMap(int mapID) {
    SpawnMapObjectsForMapGroup(mapID, AREA_EXPO_SITE);
}
```
