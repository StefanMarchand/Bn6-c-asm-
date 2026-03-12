#include "mapgroup_spawn_helpers.h"

int GreenTown_SpawnMapObjectsForMap(void)
{
    return SpawnObjectsFromList(pt_805E008[gToolkit->gameState->mapNumber]);
}
