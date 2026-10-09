#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include "Memory/PlacementNew.h"

// USA: func_0201c0e8
ARM void* ResetNameTableThenNotify(void* obj)
{
    Foo02048004* block = new (obj) Foo02048004;
    ClearNameTable(&block->nameTable);
    func_0204719c(block);
    return obj;
}
