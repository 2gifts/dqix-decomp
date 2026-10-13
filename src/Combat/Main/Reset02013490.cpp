#include <globaldefs.h>
#include "World/BmdjScriptNode.h"
#include "std_library_functions.h"

// USA: func_02013490
ARM void Reset02013490(GrottoTileMapRecord* record) {
    record->node = NULL;
    record->angle = 0;
    record->info.tileID = 0;
    memset(record->info.directionBitmasks, 0, sizeof(record->info.directionBitmasks));
    memset(record->info.tilename, 0, sizeof(record->info.tilename));
    Mat3x3_WriteIdentity(&record->rotation);
    record->position.x = 0;
    record->position.y = 0;
    record->position.z = 0;
}
