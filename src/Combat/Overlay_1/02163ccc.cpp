#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" char* func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov017_021b621c(void* node, SafeAllocator* allocator, void* obj);
extern SafeAllocator* data_ov001_021658b8[8];

struct HeadList020469f8;
struct HeadNode020469f8;
void PrependNodeToHead(struct HeadList020469f8* list, struct HeadNode020469f8* node);

extern "C" void _ZN8Object3D11MakeVisibleEv(unsigned char* obj);
extern "C" void _ZN8Object3D10EnableFlagEi(unsigned char* obj, unsigned int mask);

struct Entry_02163ccc { int type; int val; int pad2; unsigned char* child; };
struct DataTable_02163ccc { char pad0[4]; Entry_02163ccc* table; };
extern struct DataTable_02163ccc data_ov001_02165880;

// USA: func_ov001_02163ccc
extern "C" ARM int func_ov001_02163ccc(char* self, int mode) {
    SafeAllocator* allocator;
    char* base;
    int slot;
    unsigned char* obj;
    char* list;
    char* node;
    int idx;

    allocator = data_ov001_021658b8[0];
    base = func_ov017_0218b5b0();
#if defined(jpn)
    list = *(char**)(base + 0x3000 + 0x4ec);
    node = *(char**)(base + 0x3000 + 0x93c);
#else
    list = *(char**)(base + 0x3000 + 0x6fc);
    node = *(char**)(base + 0x3000 + 0xb5c);
#endif

    if (mode < 1) {
        func_ov017_021b621c(node, allocator, 0);
        PrependNodeToHead((struct HeadList020469f8*)list, (struct HeadNode020469f8*)node);
    } else {
        idx = func_ov017_021d60f4(self);
        slot = -1;
        if (mode >= 2) {
            slot = func_ov017_021d60f4(self + 0x8);
        }
        obj = 0;
        if (idx > 0) {
            if (data_ov001_02165880.table[idx].type == 1) {
                obj = data_ov001_02165880.table[idx].child;
            }
            if (obj == 0) return 0;
            _ZN8Object3D11MakeVisibleEv(obj);
            _ZN8Object3D10EnableFlagEi(obj, 0x40000000);
        }
        func_ov017_021b621c(node, allocator, obj);
        *(short*)(node + 0xfe) = (short)slot;
        PrependNodeToHead((struct HeadList020469f8*)list, (struct HeadNode020469f8*)node);
    }
    node[8] = 0;
#if defined(jpn)
    (*(char**)(base + 0x3000 + 0x524))[0x96] = 1;
#else
    (*(char**)(base + 0x3000 + 0x734))[0x9a] = 1;
#endif
    return 1;
}
