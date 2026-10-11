#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue4D4_4D0 = 0x4d0 };
enum { kRegionValue7000_8000 = 0x8000 };
enum { kRegionValue1000_400 = 0x400 };
enum { kRegionValue280_140 = 0x140 };
enum { kRegionValue5C_28 = 0x28 };
#else
enum { kRegionValue4D4_4D0 = 0x4d4 };
enum { kRegionValue7000_8000 = 0x7000 };
enum { kRegionValue1000_400 = 0x1000 };
enum { kRegionValue280_140 = 0x280 };
enum { kRegionValue5C_28 = 0x5c };
#endif


extern "C" void _Z12Init0205a198P14Struct0205a198(void* p);
extern "C" void _Z23ClearField0And40205a234P19ClearTarget0205a234(void* p);
extern "C" int _Z26GetGlobalField0x1c020421a0v();

struct Obj021680d4 {
    SafeAllocator alloc0;
    SafeAllocator alloc14;
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    SafeAllocator alloc50;
    char pad64[0x7c - 0x64];
    int field7c;
    char pad80[kRegionValue4D4_4D0 - 0x80];
    void* field4d4;
    void* field4d8;
};

// USA: func_ov003_021680d4
// JPN: func_ov003_02167f58
extern "C" ARM void func_ov003_021680d4(struct Obj021680d4* obj, SafeAllocator* alloc) {
    if (alloc == 0) return;
    void* p1 = alloc->Allocate(0x4000);
    obj->alloc0.CreateTypeA(p1, 0x4000);
    void* p2 = alloc->Allocate(0x8000);
    obj->alloc14.CreateTypeA(p2, 0x8000);
    void* p3 = alloc->Allocate(kRegionValue7000_8000);
    obj->alloc28.CreateTypeA(p3, kRegionValue7000_8000);
    void* p4 = alloc->Allocate(kRegionValue1000_400);
    obj->alloc3c.CreateTypeA(p4, kRegionValue1000_400);
    void* p5 = alloc->Allocate(0x400);
    obj->alloc50.CreateTypeA(p5, 0x400);
    void* p6 = alloc->Allocate(kRegionValue280_140);
    obj->field4d4 = p6;

    int i;
#if defined(jpn)
    for (i = 0; i < 8; i++) {
#else
    for (i = 0; i < 0x10; i++) {
#endif
        _Z12Init0205a198P14Struct0205a198((char*)obj->field4d4 + i * 0x28);
    }

    void* p7 = alloc->Allocate(8);
    obj->field4d8 = p7;
    _Z23ClearField0And40205a234P19ClearTarget0205a234(p7);

    obj->field7c = *(int*)(_Z26GetGlobalField0x1c020421a0v() + kRegionValue5C_28);
}
