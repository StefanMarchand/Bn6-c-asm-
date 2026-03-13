```c
#include "global.h"
#include "overworld.h"
#include "task.h"

// Forward declarations from expo_site.h
extern struct ExpoSiteData* gExpoSiteData;
void ExpoSite_SetupMapLayout(void);
void ExpoSite_LoadTilesets(void);
void ExpoSite_LoadPalettes(void);
void ExpoSite_SetupEvents(void);
void ExpoSite_LoadSprites(void);

void ExpoSite_EnterMapGroup(void)
{
    if (gOverworld.state == 0)
    {
        if (gExpoSiteData->flags == 0)
        {
            ExpoSite_SetupMapLayout();
            ExpoSite_LoadTilesets();
            ExpoSite_LoadPalettes();
            ExpoSite_SetupEvents();
            ExpoSite_LoadSprites();
            gOverworld.state++;
        }
    }
}
```
