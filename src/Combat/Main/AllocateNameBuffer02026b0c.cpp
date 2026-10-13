#include <globaldefs.h>

#include "Resource/GameResources.h"

struct NameEntry02026b0c {
    short id;
    char name[24];
};

struct Obj02026b0c {
    #if defined(jpn)
    char pad[0x6ce];
#else
    char pad[0x77a];
#endif
    unsigned char count;
    unsigned char pad2;
    NameEntry02026b0c* entries;
};

// USA: func_02026b0c
ARM void AllocateNameBuffer02026b0c(struct Obj02026b0c* p, int n) {
    GameResources* resources = func_ov017_0218b5b0();
    SafeAllocator* alloc = &resources->allocator_array_38[12];
    p->count = n;
    p->entries = static_cast<NameEntry02026b0c*>(alloc->Allocate((n & 0xff) * sizeof(NameEntry02026b0c)));
}
