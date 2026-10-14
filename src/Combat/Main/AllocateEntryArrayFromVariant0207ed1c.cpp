#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct EntryArray0207efdc;

void AllocateEntryArray0207efdc(struct EntryArray0207efdc* obj, SafeAllocator* alloc, int count);

extern void* data_02108ed8[2];

// USA: func_0207ed1c
ARM int AllocateEntryArrayFromVariant0207ed1c(struct Variant02030b0c* p) {
    AllocateEntryArray0207efdc((struct EntryArray0207efdc*)data_02108ed8[1], (SafeAllocator*)data_02108ed8[0], (short)((Script::Parameter*)p)->ToInt());
    return 1;
}
