```c
#include "common.h"
#include "gfx_anims.h"
#include "map.h"

static void LoadExpoSiteGFXAnims(u32 animID);

void ExpoSite_LoadGFXAnims(void) {
    u32 i;
    
    // Initialize ExpoSite-specific GFX animation loading
    for (i = 0; i < EXPO_SITE_GFX_ANIM_COUNT; i++) {
        LoadExpoSiteGFXAnims(i);
    }
}

static void LoadExpoSiteGFXAnims(u32 animID) {
    // Load individual GFX animation data for ExpoSite map group
    // This wrapper delegates to the asm09 loader in maps/ExpoSite/loader.s
    extern void asm09_LoadExpoSiteGFXAnim(u32);
    asm09_LoadExpoSiteGFXAnim(animID);
}
```
