#include "mapgroup_spawn_helpers.h"

int SeasideTown_SpawnMapObjectsForMap(void)
{
    return SpawnObjectsFromList(off_80596E0[gToolkit->gameState->mapNumber]);
}
