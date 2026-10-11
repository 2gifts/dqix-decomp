#include <globaldefs.h>
#if defined(jpn)
enum { kRegion4c = 0x48 };
#else
enum { kRegion4c = 0x4c };
#endif
#include "Memory/SafeAllocator.h"

struct InitTarget0205cfd4;
struct Struct020dfc40;

struct List0204af64 {
    unsigned char data[0x20];
};

extern "C" void func_02074af4(void* obj);
extern "C" void _Z18InitStruct0205cfd4P18InitTarget0205cfd4(struct InitTarget0205cfd4* s);
extern "C" void _Z17ResetList0204af64P12List0204af64(struct List0204af64* obj);
extern "C" void func_0204c684(void* obj);
extern "C" void _Z18InitStruct0205a444Pc(char* obj);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(struct Struct020dfc40* p);
extern "C" void _Z20ClearFields_021e20c0Pv(void* p);
extern "C" void _Z24ClearFlagFields_02169658Pv(void* obj);

struct CanvasSlot021681c8 {
    unsigned char data[0xe0];
};

struct BattleView021681c8 {
    SafeAllocator allocs[5];
    unsigned char field_0x64[0x1c];
    unsigned char field_0x80[kRegion4c];
    unsigned char field_0xcc[0x10];
    unsigned char field_0xdc;
    unsigned char field_0xdd;
    unsigned char pad_0xde[2];
    int savedBgMode;
    unsigned char field_0xe4[0xbc];
    List0204af64 lists[2];
    CanvasSlot021681c8 canvases[3];
    char field_0x480[0x54];
    int field_0x4d4;
    int field_0x4d8;
    int field_0x4dc;
    unsigned char pad_0x4e0[8];
    unsigned char field_0x4e8;
    unsigned char field_0x4e9;
    unsigned char field_0x4ea;
    unsigned char field_0x4eb;
    unsigned char field_0x4ec;
    unsigned char field_0x4ed;
    unsigned char field_0x4ee;
    unsigned char field_0x4ef[4];
    unsigned char field_0x4f3[4];
    unsigned char pad_0x4f7;
    int field_0x4f8;
    unsigned char pad_0x4fc[0xa3];
    unsigned char field_0x59f;
    int field_0x5a0;
    unsigned char field_0x5a4;
    unsigned char field_0x5a5;
};

// JPN: func_ov003_0216804c
// USA: func_ov003_021681c8
extern "C" ARM void func_ov003_021681c8(BattleView021681c8* view) {
    view->field_0xdc = 0;
    view->field_0xdd = 0;
    func_02074af4(view->field_0xcc);

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    view->savedBgMode = (*dispcnt & 0x1f00) >> 8;
    *dispcnt = (*dispcnt & ~0x1f00) | 0x100;

    view->allocs[4].ResetAllocatorPointer();
    view->allocs[3].ResetAllocatorPointer();
    view->allocs[2].ResetAllocatorPointer();
    view->allocs[1].ResetAllocatorPointer();
    view->allocs[0].ResetAllocatorPointer();

    _Z18InitStruct0205cfd4P18InitTarget0205cfd4((struct InitTarget0205cfd4*)view->field_0xe4);
    for (int i = 0; i < 2; i++) {
        _Z17ResetList0204af64P12List0204af64(&view->lists[i]);
    }
    for (int i = 0; i < 3; i++) {
        func_0204c684(&view->canvases[i]);
    }
    _Z18InitStruct0205a444Pc(view->field_0x480);
    view->field_0x4d4 = 0;
    view->field_0x4d8 = 0;
    _Z19ResetStruct020dfc40P14Struct020dfc40((struct Struct020dfc40*)view->field_0x64);
    _Z20ClearFields_021e20c0Pv(view->field_0x80);

    view->field_0x4dc = 0;
    view->field_0x4ec = 0;
    view->field_0x4e8 = 0;
    view->field_0x4e9 = 0;
    view->field_0x4ea = 0;
    view->field_0x4eb = 0;
    view->field_0x4ed = 0;
    view->field_0x4ee = 0;
    for (int i = 0; i < 4; i++) {
        view->field_0x4ef[i] = 0;
    }
    for (int i = 0; i < 4; i++) {
        view->field_0x4f3[i] = 0;
    }
    view->field_0x4f8 = 0;
    view->field_0x5a0 = 0;
    view->field_0x5a4 = 0;
    view->field_0x5a5 = 0;
    view->field_0x59f = 0;
    _Z24ClearFlagFields_02169658Pv(view);
}
