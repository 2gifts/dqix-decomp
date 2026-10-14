#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Pool02089ea0;

void AllocateArrayPool02089ea0(struct Pool02089ea0* out, SafeAllocator* alloc, int count);

struct ArrayPoolContext02108efc {
    struct Pool02089ea0* pool;
    int unk4;
    int unk8;
    SafeAllocator* alloc;
};
extern ArrayPoolContext02108efc data_02108efc;

// USA: func_02089b64
ARM int InitArrayPoolFromVariant(struct Variant02030b0c* variant) {
    AllocateArrayPool02089ea0(data_02108efc.pool, data_02108efc.alloc, (short)((Script::Parameter*)variant)->ToInt());
    return 1;
}
