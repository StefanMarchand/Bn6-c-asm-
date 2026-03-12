#include "mapgroup_spawn_helpers.h"

int CyberAcademy_SpawnMapObjectsForMap(void)
{
    return SpawnObjectsFromList(off_8052808[gToolkit->gameState->mapNumber]);
}
