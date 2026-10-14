#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; int u; };
void* GetElementStride0x18_0207f100(unsigned char* obj, short index);

struct Elem0207eef8 {
    unsigned char pad0[4];
    unsigned short* data;
    unsigned char pad1[0xc];
    unsigned char firstCount;
};
struct Arr0207eef8 {
    struct Elem0207eef8* base;
    short count;
    short capacity;
};
extern void* data_02108ed8[2];

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0207eef8
ARM int PopulateEntrySlotB0207eef8(struct Variant02030b0c* p) {
    struct Arr0207eef8* arr = (struct Arr0207eef8*)data_02108ed8[1];
    struct Elem0207eef8* e = (struct Elem0207eef8*)GetElementStride0x18_0207f100((unsigned char*)arr, (short)(arr->count - 1));
    unsigned short* buf = e->data;
    unsigned char i = 0;
    while (i < e->firstCount) {
        buf[i] = (unsigned short)((Script::Parameter*)p)->ToInt();
        p++;
        i++;
    }
    return 1;
}
