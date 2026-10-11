#include <globaldefs.h>

#if defined(jpn)
enum { entryOffset = 0x1d0, argumentOffset = 0x190, payloadDOffset = 0x194, payloadEOffset = 0x198, payloadFOffset = 0x19c, payloadGOffset = 0x189, payloadHOffset = 0x18a, activeFlagOffset = 0x184, secondFlagOffset = 0x185 };
#else
enum { entryOffset = 0x450, argumentOffset = 0x3f0, payloadDOffset = 0x3f4, payloadEOffset = 0x3f8, payloadFOffset = 0x3fc, payloadGOffset = 0x3e9, payloadHOffset = 0x3ea, activeFlagOffset = 0x3e4, secondFlagOffset = 0x3e5 };
#endif
#include "System/Memory.h"

struct Payload0201165c {
    int d;
    int e;
    int f;
    unsigned char g;
    char pad1[3];
    unsigned char h;
};

// USA: func_0201165c
ARM void InitTreasureMapEntry0201165c(char* obj, const void* src, int c, struct Payload0201165c p) {
    VectorizedInvertedMemcpy(src, obj + entryOffset + 0x6000, 0x1c);
    *(int*)(obj + 0x6000 + argumentOffset) = c;
    *(int*)(obj + 0x6000 + payloadDOffset) = p.d;
    *(int*)(obj + 0x6000 + payloadEOffset) = p.e;
    *(int*)(obj + 0x6000 + payloadFOffset) = p.f;
    *(unsigned char*)(obj + 0x6000 + payloadGOffset) = p.g;
    *(unsigned char*)(obj + 0x6000 + payloadHOffset) = p.h;
    *(unsigned char*)(obj + 0x6000 + activeFlagOffset) = 1;
    *(unsigned char*)(obj + 0x6000 + secondFlagOffset) = 1;
}
