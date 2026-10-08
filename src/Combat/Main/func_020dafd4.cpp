#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct InitStruct020dde3c;
extern "C" void _Z20InitAndClear020dde3cP18InitStruct020dde3c(InitStruct020dde3c* obj);
void SetField0x0Short(void* obj, short value);
void SetField0x2Short(void* obj, short value);
extern "C" void _Z28SetFieldsAt0x8And0xc020dde84Pcii(char* obj, int a, int b);
void SetField0x20(void* obj, int value);

struct Struct020db0c4;
extern "C" void _Z18InitStruct020db0c4P14Struct020db0c4(Struct020db0c4* p);

extern unsigned char data_020ee688[];
extern unsigned char data_020ee68b[];

struct Slot020dafd4 {
    unsigned short field0;
    unsigned short field2;
    char pad4[4];
    int field8;
    int fieldc;
    char pad10[0x10];
    int field20;
    char pad24[4];
};

struct Manager020dafd4 {
    SafeAllocator allocator;
    char pad3c[0x3c - sizeof(SafeAllocator)];
    unsigned char b3c;
    char pad3d[0x40 - 0x3d];
    void* charBuf;
    unsigned int charBufSize;
    void* plttBuf;
    unsigned int plttBufSize;
    char pad50[4];
    unsigned char b54;
    char pad55[0x5c - 0x55];
    int f5c;
    int f60;
    char pad64[2];
    short sh66;
    char pad68[4];
    unsigned char b6c;
    char pad6d;
    short sh6e;
    Slot020dafd4 slots[3];
};

// USA: func_020dafd4
extern "C" ARM void func_020dafd4(Manager020dafd4* mgr) {
    mgr->allocator.ResetAllocatorPointer();
    mgr->charBuf = 0;
    mgr->charBufSize = 0;
    mgr->plttBuf = 0;
    mgr->plttBufSize = 0;
    mgr->b3c = 0;
    mgr->f5c = 0;
    mgr->f60 = 0;
    mgr->sh66 = 0;
    mgr->b6c = 1;
    mgr->b54 = 0;
    for (int i = 0; i < 3; i++) {
        Slot020dafd4* slot = &mgr->slots[i];
        _Z20InitAndClear020dde3cP18InitStruct020dde3c((InitStruct020dde3c*)slot);
        SetField0x0Short(slot, data_020ee688[i]);
        SetField0x2Short(slot, data_020ee68b[i]);
        _Z28SetFieldsAt0x8And0xc020dde84Pcii((char*)slot, (i * 0x12 + 0xbc) & 0xff, 0xa4);
        SetField0x20(slot, (int)(((long long)(i << 12) * 0x28 + 0x800) >> 12) + 0x85 + 0x300);
    }
    mgr->sh6e = 0;
    _Z18InitStruct020db0c4P14Struct020db0c4((Struct020db0c4*)mgr);
}