```c
#include "types.h"
#include "postprocess.h"

// Forward declaration for the assembly routine in loader.s
extern void ExpoSite_asm09(u32 group, u32 map);

// 0x08062B64
void ExpoSite_LoadGFXAnims(u32 group, u32 map) {
    // Wrapper that calls the assembly routine for ExpoSite map-group GFX animations
    ExpoSite_asm09(group, map);
}
```
