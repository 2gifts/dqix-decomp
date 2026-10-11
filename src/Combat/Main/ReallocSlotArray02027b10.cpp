#include <globaldefs.h>

#if defined(jpn)
enum { slotArrayOffset = 0x9cc };
#else
enum { slotArrayOffset = 0xa98 };
#endif
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_0218b5b0(void);

struct S02027b10 {
    char pad0[slotArrayOffset];
    unsigned char f0xa98;
    unsigned char f0xa99;
    char pad1[2];
    void* f0xa9c;
};

// USA: func_02027b10  (semantic: ReallocSlotArray02027b10)
extern "C" ARM void func_02027b10(struct S02027b10* obj, unsigned int count) {
    int base = func_ov017_0218b5b0();
    SafeAllocator* alloc;
    if (obj->f0xa9c != 0) {
        alloc = (SafeAllocator*)(base + 0x128);
        alloc->Free(obj->f0xa9c);
    } else {
        alloc = (SafeAllocator*)(base + 0x128);
    }
    obj->f0xa9c = alloc->Allocate(count * 0xc);
    obj->f0xa98 = count;
    obj->f0xa99 = 0;
}
