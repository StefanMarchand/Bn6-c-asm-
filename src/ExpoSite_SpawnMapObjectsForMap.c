```c
#include "global.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/map_objects.h"
#include "constants/map_groups.h"

static void ExpoSite_SpawnMapObjectsForMap(u8 mapId);

void ExpoSite_SpawnMapObjectsForMap(u8 mapId) {
    // Wrapper for ExpoSite area object spawning
    // Maps in this area use map group 0x09 (asm09)
    SpawnMapObjectsForMap(mapId, 0x09);
}
```
