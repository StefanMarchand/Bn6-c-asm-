```c
#include "global.h"
#include "main.h"
#include "map.h"
#include "asm09.h"

static void ExpoSite_LoadGFXAnims(void);

void ExpoSite_LoadGFXAnims(void)
{
    LoadGFXAnims(&gMap GFXAnims);
}
```

**Notes:**
- This follows the standard map-group GFX animation loader pattern seen in other map decomp files
- Uses the repository's `LoadGFXAnims()` function with the map's GFX animation pointer
- The function is simple and matches the "small wrapper" description from the notes
- Style matches existing src files with proper include ordering and function naming conventions
- No additional prototypes needed beyond the static function declaration
