#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

void EncodeSignFlaggedHalfword(short* out, int value);

extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_ov020_0218cd64(int, int, int, int, int);
extern "C" void _Z17ResetList0204af64P12List0204af64(void*);
extern "C" void _Z24SetWord0x18ClearByte0x1fPhi(void*, int);
extern "C" void func_0204b5b4(void*, int, void*, int);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(void*, void*);
extern "C" void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(void*, int, void*);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void*, int, int);
void LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" int _Z18CountActiveEntriesP19ActiveEntry02046900(void*);
extern "C" void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void*, int, void**, int*);
extern "C" void func_0204b174(void*, void*, void*, int);
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(void*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(void*, void*);

extern char data_ov020_0218dcb3;
extern int data_0211e33c;

struct ResetContext0218cd98 {
    char pad0[0x470];
    SafeAllocator allocator;
};

// USA: func_ov020_0218cd98  (semantic: ResetAndReloadContext_0218cd98)
extern "C" ARM void func_ov020_0218cd98(struct ResetContext0218cd98* self) {
    unsigned char* base = (unsigned char*)self;

    EncodeSignFlaggedHalfword((short*)0x400106c, -16);
    self->allocator.Reset();
    MapVRAMBanksToSubBG(4);
    func_ov020_0218cd64(0, 1, 1, 1, 0);

    _Z17ResetList0204af64P12List0204af64(base + 0xbc + 0x400);
    _Z24SetWord0x18ClearByte0x1fPhi(base + 0xbc + 0x400, 0);

    unsigned char* obj = base + 0xbc;
    unsigned char* list = obj + 0x400;
    list[0x1c] = (list[0x1c] & ~0xf) | 1;
    int v2 = list[0x1c] & ~0xf0;
    list[0x1c] = v2;
    func_0204b5b4(list, 0, obj, v2);

    _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(base + 0xbc + 0x400, &self->allocator);
    _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(base + 0xbc + 0x400, 1, &self->allocator);
    _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(base + 0xbc + 0x400, 0, 0);
    BackgroundLoader::AddLockGlobal();

    unsigned int local1c = 0;
    LoadFileIntoMemory((const char*)&data_ov020_0218dcb3, (void*)&data_0211e33c, &local1c);
    int count = _Z18CountActiveEntriesP19ActiveEntry02046900(&data_0211e33c);

    for (int i = 0; i < count; i++) {
        int recSize;
        void* recField;
        void* rec = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(&data_0211e33c, i, &recField, &recSize);
        if (rec != 0) {
            func_0204b174(base + 0xbc + 0x400, rec, &self->allocator, recSize);
        }
    }

    _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(base + 0xbc + 0x400, 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
    _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(base + 0xbc + 0x400, (void*)0);
    BackgroundLoader::RemoveLockGlobal();

    *(volatile unsigned short*)0x4000050 = 0;
    *(volatile unsigned short*)0x4001050 = 0;
    volatile unsigned int* reg0 = (volatile unsigned int*)0x4000000;
    *reg0 = (*reg0 & ~0x1f00) | 0x1300;
    volatile unsigned int* reg1000 = (volatile unsigned int*)0x4001000;
    *reg1000 = (*reg1000 & ~0x1f00) | 0x100;

    EncodeSignFlaggedHalfword((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword((short*)0x400106c, -16);
}
