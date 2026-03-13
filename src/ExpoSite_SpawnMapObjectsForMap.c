```c
#include "global.h"
#include "map.h"
#include "object.h"
#include "expo_site.h"

// Static prototype for internal spawning helper
static void ExpoSite_SpawnMapGroupObjects(u8 mapGroup);

void ExpoSite_SpawnMapObjectsForMap(u8 mapID) {
    u8 mapGroup;
    
    // Determine which map group this map belongs to
    if (mapID < 4) {
        mapGroup = 0;  // Main hall group
    } else if (mapID < 8) {
        mapGroup = 1;  // East wing group
    } else if (mapID < 12) {
        mapGroup = 2;  // West wing group
    } else {
        mapGroup = 3;  // Backstage group
    }
    
    // Spawn objects for the appropriate map group
    ExpoSite_SpawnMapGroupObjects(mapGroup);
}

static void ExpoSite_SpawnMapGroupObjects(u8 mapGroup) {
    // Map group object spawning implementation
    // Based on asm09 sketch from docs/decomp/asm09.c
    Object* obj;
    
    switch (mapGroup) {
        case 0:  // Main hall
            // Spawn reception desk
            obj = CreateObject(OBJ_RECEPTION_DESK, 0x180, 0x100);
            SetObjectAnim(obj, ANIM_RECEPTION_IDLE, 0);
            
            // Spawn info kiosks
            for (u8 i = 0; i < 3; i++) {
                obj = CreateObject(OBJ_INFO_KIOSK, 0x100 + (i * 0x40), 0x140);
                SetObjectAnim(obj, ANIM_KIOSK_IDLE, 0);
            }
            break;
            
        case 1:  // East wing
            // Spawn exhibition panels
            for (u8 i = 0; i < 4; i++) {
                obj = CreateObject(OBJ_EXHIBIT_PANEL, 0x80 + (i * 0x60), 0x180);
                SetObjectAnim(obj, ANIM_PANEL_STATIC, 0);
            }
            break;
            
        case 2:  // West wing
            // Spawn workshop tables
            for (u8 i = 0; i < 2; i++) {
                obj = CreateObject(OBJ_WORKSHOP_TABLE, 0xC0 + (i * 0x80), 0x120);
                SetObjectAnim(obj, ANIM_TABLE_IDLE, 0);
            }
            break;
            
        case 3:  // Backstage
            // Spawn equipment racks
            for (u8 i = 0; i < 2; i++) {
                obj = CreateObject(OBJ_EQUIPMENT_RACK, 0x140 + (i * 0x60), 0x100);
                SetObjectAnim(obj, ANIM_RACK_STATIC, 0);
            }
            break;
    }
    
    // Common spawning for all map groups
    // Spawn floor markers for navigation
    for (u8 i = 0; i < 8; i++) {
        obj = CreateObject(OBJ_FLOOR_MARKER, 0x40 + (i * 0x30), 0x200);
        SetObjectAnim(obj, ANIM_MARKER_GLOW, 0);
        SetObjectFlag(obj, OBJFLAG_INVISIBLE);
    }
}
```
