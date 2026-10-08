#include <globaldefs.h>
#include "System/Cache.h"

extern "C" int _Z21GetTableEntry0204a5e4ii(int a, int b);

struct Ref0204fbf8 {
    char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct Obj0204fbf8 {
    char pad0[0x4];
    struct Ref0204fbf8* field4;
    void* field8;
    char pad1[0xa0 - 0xc];
    int fieldA0;
    int fieldA4;
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0204fbf8
extern "C" ARM void _Z36InvokeHandlerAfterCacheFlush0204fbf8P11Obj0204fbf8(Obj0204fbf8* a) {
    unsigned char hi = a->field4->hi;
    unsigned char lo = a->field4->lo;
    unsigned char nib[2];
    nib[0] = lo;
    nib[1] = hi;
    void (*fp)(void*, int, unsigned int) = (void(*)(void*, int, unsigned int))_Z21GetTableEntry0204a5e4ii(nib[0], nib[1]);
    CleanInvalidateCacheRange(a->field8, a->fieldA4);
    fp(a->field8, a->fieldA0, a->fieldA4);
}