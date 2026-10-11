#pragma opt_vectorize_loops off
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

void EncodeSignFlaggedHalfword(short* out, int value);

extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void func_ov020_0218c7bc(int, int, int, int, int);
extern "C" void _Z17ResetList0204af64P12List0204af64(void*);
extern "C" void _Z24SetWord0x18ClearByte0x1fPhi(void*, int);
extern "C" void func_0204b5b4(void*, int);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(void*, void*);
extern "C" void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(void*, int, void*);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void*, int, int);
extern "C" int DisableSubObjVRAMBanks();
extern "C" int DisableSubBGVRAMBanks();
extern "C" void _Z12SetSubBgModej(unsigned int);
extern "C" void MapVRAMBanksToSubObj(unsigned short value);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_ov020_0218cd64(int, int, int, int, int);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _Z18LoadFileIntoMemoryPKcPvPj(const char*, void*, unsigned int*);
extern "C" int _Z18CountActiveEntriesP19ActiveEntry02046900(void*);
extern "C" void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void*, int, void**, int*);
extern "C" void _Z21DispatchByTag0204b2e0PvPc(void*, char*);
extern "C" void _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc(void*, char*);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(void*, void*);
extern "C" void _Z23ResetRecordList0204afb4P12List0204afb4(void*);
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);

extern char data_ov020_0218dce2;
extern char data_ov020_0218dcf8;
extern int data_0211e33c;

struct List0218d32c {
    unsigned char pad[0x1c];
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
    unsigned char pad2[3];
};

struct SetupContext0218d32c {
#if defined(jpn)
    char pad0[0x400];
#else
    char pad0[0x470];
#endif

    SafeAllocator allocator;
};

// JPN: func_ov020_0218db7c
// USA: func_ov020_0218d32c  (semantic: InitializeAndDispatchSingleList_0218d32c)
extern "C" ARM void func_ov020_0218d32c(struct SetupContext0218d32c* self, int mode) {
#if defined(jpn)
 enum {regionalOffset0=0x2c};
#else
 enum {regionalOffset0=0x9c};
#endif
    unsigned char* base = (unsigned char*)self;
    unsigned int outLen;
    void* recFieldScratch;
    char* volatile resultsArray[3];
    int sizeArr[3];
    unsigned char list3[0x20];

    self->allocator.Reset();
    EncodeSignFlaggedHalfword((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword((short*)0x400106c, -16);
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0, 1, 1, 1, 0);

    _Z17ResetList0204af64P12List0204af64(base + regionalOffset0 + 0x400);
    _Z24SetWord0x18ClearByte0x1fPhi(base + regionalOffset0 + 0x400, 0);
    struct List0218d32c* list = (struct List0218d32c*)(base + regionalOffset0 + 0x400);
    list->lowNibble = 0;
    list->highNibble = 1;
    func_0204b5b4(list, 1);
    _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(base + regionalOffset0 + 0x400, &self->allocator);
    _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(base + regionalOffset0 + 0x400, 1, &self->allocator);
    _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(base + regionalOffset0 + 0x400, 0, 0);

    DisableSubObjVRAMBanks();
    DisableSubBGVRAMBanks();
    _Z12SetSubBgModej(0);

    volatile unsigned int* reg1000 = (volatile unsigned int*)0x4001000;
    *reg1000 = (*reg1000 & ~0x1f00) | 0x100;
    MapVRAMBanksToSubObj(0x100);

    *reg1000 = (*reg1000 & 0xffcfffef) | 0x10;
    MapVRAMBanksToSubBG(0x80);

    func_ov020_0218cd64(0, 0, 0xe, 0, 0);
    func_ov020_0218cd64(0, 0, 0xf, 0, 0);

    volatile unsigned short* reg1008 = (volatile unsigned short*)0x4001008;
    reg1008[0] = (reg1008[0] & ~3) | 1;
    reg1008[1] = (reg1008[1] & ~3) | 2;
    reg1008[2] = reg1008[2] & ~3;
    reg1008[3] = (reg1008[3] & ~3) | 3;

    _ZN16BackgroundLoader13AddLockGlobalEv();

    if (mode == 1) {
        _Z18LoadFileIntoMemoryPKcPvPj((const char*)&data_ov020_0218dce2, (void*)&data_0211e33c, &outLen);
    } else {
        _Z18LoadFileIntoMemoryPKcPvPj((const char*)&data_ov020_0218dcf8, (void*)&data_0211e33c, &outLen);
    }

    int count = _Z18CountActiveEntriesP19ActiveEntry02046900((void*)&data_0211e33c);

    for (int i = 0; i < count; i++) {
        resultsArray[i] = (char*)_Z17FindRecordByIndexP11Rec020467f0iPPvPi((void*)&data_0211e33c, i, &recFieldScratch, &sizeArr[i]);
    }

    _Z17ResetList0204af64P12List0204af64(list3);
    list3[0x1c] = (list3[0x1c] & ~0xf) | 1;
    list3[0x1c] = list3[0x1c] & ~0xf0;
    func_0204b5b4(list3, 3);
    _Z24SetWord0x18ClearByte0x1fPhi(list3, 0);
    _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(list3, 0, 0);

    for (int j = 0; j < 3; j++) {
        _Z21DispatchByTag0204b2e0PvPc(list3, resultsArray[j]);
        _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc(list3, resultsArray[j]);
    }

    _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(list3, (void*)0);
    _Z23ResetRecordList0204afb4P12List0204afb4(list3);
    _ZN16BackgroundLoader16RemoveLockGlobalEv();

    *(volatile unsigned short*)0x4000050 = 0;
    *(volatile unsigned short*)0x4001050 = 0;
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 1, 2, 0xf, 0x1f);

    volatile unsigned int* reg0 = (volatile unsigned int*)0x4000000;
    *reg0 = (*reg0 & ~0x1f00) | 0x1300;

    EncodeSignFlaggedHalfword((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword((short*)0x400106c, -16);
}
