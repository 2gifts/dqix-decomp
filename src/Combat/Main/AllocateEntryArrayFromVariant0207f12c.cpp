#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
struct EntryArray0207f594;

void AllocateEntryArray0207f594(struct EntryArray0207f594* obj, SafeAllocator* alloc, int count);

extern void* data_02108ee0[2];

// USA: func_0207f12c
ARM int AllocateEntryArrayFromVariant0207f12c(struct Variant02030b0c* p) {
    const Script::Parameter* parameters = reinterpret_cast<const Script::Parameter*>(p);
    AllocateEntryArray0207f594((struct EntryArray0207f594*)data_02108ee0[1], (SafeAllocator*)data_02108ee0[0], (short)parameters[0].ToInt());
    return 1;
}
