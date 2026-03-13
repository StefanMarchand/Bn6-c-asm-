```c
#include "global.h"
#include "map.h"

// From ExpoSite/loader.s - map object list for the area
extern const MapObjectList ExpoSite_MapObjectList;

/**
 * @brief Spawn map objects for the ExpoSite area
 * @param mapId Current map identifier
 * 
 * Wrapper function that sets up map object spawning for the
 * asm09 Expo Site area. Delegates to generic map object spawning
 * with the area-specific object list.
 */
void ExpoSite_SpawnMapObjectsForMap(u32 mapId)
{
    SpawnMapObjectsForMap(mapId, &ExpoSite_MapObjectList, 0);
}
```
