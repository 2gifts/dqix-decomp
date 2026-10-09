#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

struct Foo02048004;
extern void MaybeInvoke0204719c(struct Foo02048004* obj);
extern void InitEightSubStructs(char* obj);
extern void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern AllocatorUnion data_02114e20;

// USA: func_0202f1dc
ARM void ReinitEightSubStructsAndAllocator(char* obj) {
    char* p;
    int i;
    p = obj;
    for (i = 0; i < 8; i++) {
        MaybeInvoke0204719c((struct Foo02048004*)p);
        p += 0x88;
    }

    if (*(SafeAllocator**)(obj + 0x444) != NULL) {
        SignedAllocatorHeader* header = (*(SafeAllocator**)(obj + 0x444))->GetSignedAllocator();
        (*(SafeAllocator**)(obj + 0x444))->Destroy();
        TailForward02012da4(&data_02114e20, header);
        TailForward02012da4(&data_02114e20, *(SafeAllocator**)(obj + 0x444));
    }

    InitEightSubStructs(obj);
}
