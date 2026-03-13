```c
#include "global.h"
#include "map_group.h"

static void ExpoSite_EnterMapGroup(void) {
    // Map group entry loader for asm09 Expo Site area
    // Address: 0x08062AB0
    
    LoadMapGroup(0x09);  // MAP_GROUP_EXPO_SITE = 0x09
    SetCurrentMapGroup(0x09);
}
```
