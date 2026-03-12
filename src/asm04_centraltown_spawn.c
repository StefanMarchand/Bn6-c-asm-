#include "mapgroup_spawn_helpers.h"

int CentralTown_SpawnMapObjectsForMap(void)
{
    return SpawnObjectsFromList(off_804E738[gToolkit->gameState->mapNumber]);
}
