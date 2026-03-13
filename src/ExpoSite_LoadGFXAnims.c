```c
#include "global.h"
#include "map.h"

// External assembly function from maps/ExpoSite/loader.s
extern void asm09_ExpoSite_LoadGFXAnims(void);

static void ExpoSite_LoadGFXAnims(void) {
    // Wrapper function for loading ExpoSite GFX animations
    // Calls the assembly implementation in loader.s
    asm09_ExpoSite_LoadGFXAnims();
}
```
