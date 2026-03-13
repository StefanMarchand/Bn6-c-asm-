```c
#include "global.h"
#include "map.h"
#include "map_object.h"
#include "map_tileset.h"

static void ExpoSite_LoadGFXAnims(void);

static void ExpoSite_LoadGFXAnims(void)
{
    LoadMapGroupGfxAnims(MAP_GROUP_EXPO_SITE, MAP_ID_EXPO_SITE);
}
```
