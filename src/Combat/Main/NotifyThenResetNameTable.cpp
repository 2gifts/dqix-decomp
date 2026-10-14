#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

// USA: func_0201c108
ARM void* NotifyThenResetNameTable_0201c108(void* obj)
{
    Foo02048004* block = static_cast<Foo02048004*>(obj);
    MaybeInvoke0204719c_02047230(block);
    ClearNameTable(&block->nameTable);
    block->~Foo02048004();
    return obj;
}
