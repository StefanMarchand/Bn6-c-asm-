Looking at the existing decompilation sketch in `docs/decomp/asm09.c` and examining the assembly at 0x08062AB0, I can see this follows the standard map group entry pattern used throughout the codebase.

```c
#include "global.h"
#include "maps.h"

static void ExpoSite_LoadMapGroup(void);

void ExpoSite_EnterMapGroup(void) {
    gMapGroup = 9;
    ExpoSite_LoadMapGroup();
}

static void ExpoSite_LoadMapGroup(void) {
    switch (gCurrentMap) {
        case 0:
            SetCurrentMapHeader(&gExpoSite_0);
            break;
        case 1:
            SetCurrentMapHeader(&gExpoSite_1);
            break;
        case 2:
            SetCurrentMapHeader(&gExpoSite_2);
            break;
        case 3:
            SetCurrentMapHeader(&gExpoSite_3);
            break;
        case 4:
            SetCurrentMapHeader(&gExpoSite_4);
            break;
        case 5:
            SetCurrentMapHeader(&gExpoSite_5);
            break;
        case 6:
            SetCurrentMapHeader(&gExpoSite_6);
            break;
        case 7:
            SetCurrentMapHeader(&gExpoSite_7);
            break;
        case 8:
            SetCurrentMapHeader(&gExpoSite_8);
            break;
        case 9:
            SetCurrentMapHeader(&gExpoSite_9);
            break;
        case 10:
            SetCurrentMapHeader(&gExpoSite_10);
            break;
        case 11:
            SetCurrentMapHeader(&gExpoSite_11);
            break;
        case 12:
            SetCurrentMapHeader(&gExpoSite_12);
            break;
        case 13:
            SetCurrentMapHeader(&gExpoSite_13);
            break;
        case 14:
            SetCurrentMapHeader(&gExpoSite_14);
            break;
        case 15:
            SetCurrentMapHeader(&gExpoSite_15);
            break;
        case 16:
            SetCurrentMapHeader(&gExpoSite_16);
            break;
        case 17:
            SetCurrentMapHeader(&gExpoSite_17);
            break;
        case 18:
            SetCurrentMapHeader(&gExpoSite_18);
            break;
        case 19:
            SetCurrentMapHeader(&gExpoSite_19);
            break;
        case 20:
            SetCurrentMapHeader(&gExpoSite_20);
            break;
        case 21:
            SetCurrentMapHeader(&gExpoSite_21);
            break;
        case 22:
            SetCurrentMapHeader(&gExpoSite_22);
            break;
        case 23:
            SetCurrentMapHeader(&gExpoSite_23);
            break;
        case 24:
            SetCurrentMapHeader(&gExpoSite_24);
            break;
        case 25:
            SetCurrentMapHeader(&gExpoSite_25);
            break;
        case 26:
            SetCurrentMapHeader(&gExpoSite_26);
            break;
        case 27:
            SetCurrentMapHeader(&gExpoSite_27);
            break;
        case 28:
            SetCurrentMapHeader(&gExpoSite_28);
            break;
        case 29:
            SetCurrentMapHeader(&gExpoSite_29);
            break;
        case 30:
            SetCurrentMapHeader(&gExpoSite_30);
            break;
        case 31:
            SetCurrentMapHeader(&gExpoSite_31);
            break;
    }
}
```

This function follows the exact pattern seen in other map group entry loaders in the codebase:
1. `ExpoSite_EnterMapGroup()` sets `gMapGroup = 9` (for the asm09 area)
2. Calls the static `ExpoSite_LoadMapGroup()` helper
3. The helper uses a switch statement on `gCurrentMap` to select the appropriate map header from the `gExpoSite_*` array
4. The switch covers all 32 maps (0-31) in the ExpoSite map group
5. Uses `SetCurrentMapHeader()` to configure the current map's header, consistent with other map group loaders

The style matches the repository's conventions with proper static function prototypes, consistent spacing, and following the same structural pattern as other map group loaders in the codebase.
