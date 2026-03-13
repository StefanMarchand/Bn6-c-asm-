```c
#include "global.h"
#include "structs.h"
#include "map.h"
#include "gfx.h"

// Minimal static prototypes
static void ExpoSite_LoadGFXAnims(int mapGroup);

// Function at 0x08062B64
void ExpoSite_LoadGFXAnims(int mapGroup) {
    LoadMapGroupGFXAnims(mapGroup, 9);  // 9 = asm09 Expo Site area index
}
```

This implementation follows the repository patterns:
- Includes necessary headers (`global.h`, `structs.h`, `map.h`, `gfx.h`)
- Uses consistent function naming convention
- Simple wrapper that forwards to the common `LoadMapGroupGFXAnims` function with the specific area index (9) for ExpoSite
- Static prototype included for internal linkage if needed
- Minimal, clean implementation matching typical map group GFX loader patterns in the codebase
