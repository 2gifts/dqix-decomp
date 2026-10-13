#include <globaldefs.h>
#include "System/Cache.h"
#include <std_library_functions.h>

extern "C" int func_02050064(void* obj);
extern "C" void func_0204fa0c(void* obj, short a, short b);
int GetTableEntry0204a5e4(int a, int b);

struct FlagsRef0204ffc0 {
    char pad[0x1c];
    unsigned char nib_lo : 4;
    unsigned char nib_hi : 4;
};

struct Obj0204ffc0 {
    char pad0[0x4];
    FlagsRef0204ffc0* ref;      // 0x4
    void* buf;                  // 0x8
    char pad1[0xa0-0xc];
    int srcOff;                 // 0xa0
    int len;                    // 0xa4
    char pad2[0xbc-0xa8];
    short sa;                   // 0xbc
    short sb;                   // 0xbe
    char pad3[0xc5-0xc0];
    unsigned char flags;        // 0xc5
};

// USA: func_0204ffc0
ARM void ProcessRefAndDispatch0204ffc0(Obj0204ffc0* a, int) {
    if (a->ref == NULL || a->buf == NULL)
        return;
    unsigned char lo = a->ref->nib_lo;
    unsigned char hi = a->ref->nib_hi;
    int r3 = func_02050064(a);
    if (!r3)
        return;
    if (r3) {
        memcpy(a->buf, (void*)(r3 + a->srcOff), a->len);
    }
    a->flags |= 0x40;
    func_0204fa0c(a, a->sa, a->sb);
    void (*fp)(void*, int, unsigned int) = (void(*)(void*, int, unsigned int))GetTableEntry0204a5e4(lo, hi);
    CleanInvalidateCacheRange(a->buf, a->len);
    fp(a->buf, a->srcOff, a->len);
}
