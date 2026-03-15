#include "mapgroup_spawn_helpers.h"

int ExpoSite_SpawnMapObjectsForMap(void)
{
    return SpawnObjectsFromList(pt_8062BE4[gToolkit->gameState->mapNumber]);
}
