#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
struct EntryArray0207f594;

extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
void AllocateEntryArray0207f594(struct EntryArray0207f594* obj, SafeAllocator* alloc, int count);

extern void* data_02108ee0[2];

#if defined(jpn)
#define AllocateEntryArrayFromVariant0207f12c func_0207feac
extern "C" ARM int func_0207feac(struct Variant02030b0c* p);
#endif

// USA: func_0207f12c
ARM int AllocateEntryArrayFromVariant0207f12c(struct Variant02030b0c* p) {
    AllocateEntryArray0207f594((struct EntryArray0207f594*)data_02108ee0[1], (SafeAllocator*)data_02108ee0[0], (short)_ZNK6Script9Parameter5ToIntEv(p));
    return 1;
}
