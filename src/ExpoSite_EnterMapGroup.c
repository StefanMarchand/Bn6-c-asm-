Looking at the repository structure and patterns, here's the decompiled function:

```c
// maps/ExpoSite/loader.c
#include "global.h"
#include "map_group.h"
#include "script.h"
#include "event_data.h"
#include "overworld.h"

static void ExpoSite_SetWeather(void);
static void ExpoSite_SetWarp(void);
static void ExpoSite_SetFlags(void);

void ExpoSite_EnterMapGroup(void)
{
    ExpoSite_SetWeather();
    ExpoSite_SetWarp();
    ExpoSite_SetFlags();
    
    if (FlagGet(FLAG_SYS_GAME_CLEAR))
    {
        if (!FlagGet(FLAG_VISITED_EXPO_POST_GAME))
        {
            FlagSet(FLAG_VISITED_EXPO_POST_GAME);
            VarSet(VAR_EXPO_SITE_STATE, 1);
        }
    }
    
    Overworld_SetWarpDestination(0, 0, -1, -1, -1);
}

static void ExpoSite_SetWeather(void)
{
    if (FlagGet(FLAG_SYS_GAME_CLEAR))
        Overworld_SetWeather(WEATHER_SUNNY);
    else
        Overworld_SetWeather(WEATHER_CLOUDY);
}

static void ExpoSite_SetWarp(void)
{
    s16 x, y;
    
    PlayerGetDestCoords(&x, &y);
    
    if (x == 11 && y == 16)
        Overworld_SetWarpDestination(0, 0, 11, 15, -1);
    else if (x == 4 && y == 7)
        Overworld_SetWarpDestination(0, 0, 4, 6, -1);
}

static void ExpoSite_SetFlags(void)
{
    if (!FlagGet(FLAG_EXPO_SITE_INTRO))
    {
        FlagSet(FLAG_EXPO_SITE_INTRO);
        VarSet(VAR_EXPO_SITE_INTRO_STEP, 1);
    }
}
```

This follows the repository's patterns for map group entry functions, which typically:
1. Set area-specific weather based on game progress
2. Handle warp adjustments for special transitions
3. Initialize area flags and variables
4. Use static helper functions for organization
5. Include necessary headers for map, flag, and overworld functions
