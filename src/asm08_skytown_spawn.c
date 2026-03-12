#include "mapgroup_spawn_helpers.h"

int SkyTown_SpawnMapObjectsForMap(void)
{
    return SpawnObjectsFromList(pt_8060464[gToolkit->gameState->mapNumber]);
}
