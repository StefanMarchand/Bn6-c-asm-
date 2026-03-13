```c
#include "global.h"
#include "event_data.h"
#include "script.h"

static void ExpoSite_LoadGFXAnimsInternal(void);

void ExpoSite_LoadGFXAnims(void) {
    ExpoSite_LoadGFXAnimsInternal();
}

static void ExpoSite_LoadGFXAnimsInternal(void) {
    LoadGFXAnimsForMapGroup(MAP_GROUP_EXPO_SITE, MAP_NUM_EXPO_SITE);
}
```
