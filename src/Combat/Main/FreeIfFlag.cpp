#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

// USA: func_02012dbc
ARM void FreeIfFlag_02012dbc(AllocatorUnion* alloc, void* data, int flag) {
    if (flag == 0)
        return;
    alloc->Free(data);
}
