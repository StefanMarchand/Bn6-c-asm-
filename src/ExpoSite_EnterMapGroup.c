```c
#include "global.h"
#include "map.h"

static void ExpoSite_MapInit(void);
static void ExpoSite_MapExit(void);

void ExpoSite_EnterMapGroup(void) {
    gCurrentMapGroup = MAP_GROUP_EXPO_SITE;
    gMapInit = ExpoSite_MapInit;
    gMapExit = ExpoSite_MapExit;
}
```
