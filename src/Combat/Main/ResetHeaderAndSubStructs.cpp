#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include "Memory/PlacementNew.h"

// USA: func_020133cc
ARM void ResetHeaderAndSubStructs(char* base)
{
    ZoneLootableRecord* record = new (static_cast<void*>(base)) ZoneLootableRecord;
    record->id = 0;
    record->field2 = -1;
    record->field4 = 0;
    func_0204719c(&record->blocks[0]);
    func_0204719c(&record->blocks[1]);
}
