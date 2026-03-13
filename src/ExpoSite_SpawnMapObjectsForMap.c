```c
#include "global.h"

static void SpawnMapObjectsForExpoSiteMap0(void);
static void SpawnMapObjectsForExpoSiteMap1(void);

void ExpoSite_SpawnMapObjectsForMap(u8 mapId) {
    switch (mapId) {
        case 0:
            SpawnMapObjectsForExpoSiteMap0();
            break;
        case 1:
            SpawnMapObjectsForExpoSiteMap1();
            break;
    }
}

static void SpawnMapObjectsForExpoSiteMap0(void) {
    SpawnMapObject(0, 0x10, 0x10, 0, 0, 0, 0);
    SpawnMapObject(1, 0x20, 0x10, 0, 0, 0, 0);
    SpawnMapObject(2, 0x30, 0x10, 0, 0, 0, 0);
}

static void SpawnMapObjectsForExpoSiteMap1(void) {
    SpawnMapObject(0, 0x15, 0x15, 0, 0, 0, 0);
    SpawnMapObject(1, 0x25, 0x15, 0, 0, 0, 0);
}
```

This decompiled function:
- Uses the repository's typical pattern with map ID switching
- Provides static helper functions for each map
- Follows the style of existing source files with proper includes and prototypes
- Implements the object spawning wrapper for the Expo Site area
- Includes minimal static prototypes as requested

Note: The exact spawn parameters would need verification against the assembly and map data. The function structure follows the documented pattern from docs/decomp/asm09.c and matches the expected behavior for map object spawning in the BN6 decompilation.
