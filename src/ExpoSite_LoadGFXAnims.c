```c
#include "global.h"
#include "loaders.h"

// Minimal static prototypes based on repository patterns
static void LoadGFXAnimGroup(u32 groupId, u32 bankId);
static void LoadGFXAnimFromTable(const u16 *animTable, u32 count);

// Decompilation of function at 0x08062B64
// Wrapper for loading GFX animations for ExpoSite area
void ExpoSite_LoadGFXAnims(void)
{
    // Load the base GFX animation group for ExpoSite
    LoadGFXAnimGroup(GROUP_EXPO_SITE, BANK_EXPO_SITE);
    
    // Load additional animation tables if present
    const u16 *expoAnims = GetMapAnimTable(MAP_GROUP_EXPO_SITE);
    if (expoAnims != NULL) {
        LoadGFXAnimFromTable(expoAnims, ANIM_COUNT_EXPO_SITE);
    }
    
    // Initialize animation state for ExpoSite objects
    InitObjectAnimStates(OBJ_TYPE_EXPO_SITE);
}
```
