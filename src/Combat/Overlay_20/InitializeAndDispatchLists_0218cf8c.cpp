#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void EncodeSignFlaggedHalfword(short* out, int value);

extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void func_ov020_0218c7bc(int, int, int, int, int);
extern "C" void _Z17ResetList0204af64P12List0204af64(void*);
extern "C" void _Z24SetWord0x18ClearByte0x1fPhi(void*, int);
extern "C" void func_0204b5b4(void*, int);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(void*, void*);
extern "C" void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(void*, int, void*);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void*, int, int);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_ov020_0218cd64(int, int, int, int, int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10MaybeResetEv(void*);
extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*, const char*, void*);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(void*, int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*, int, void**, unsigned int*);
extern "C" int _Z18CountActiveEntriesP19ActiveEntry02046900(void*);
extern "C" void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void*, int, void**, int*);
extern "C" void func_0204b174(void*, void*, void*, int);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(void*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(void*, void*);
extern "C" void _ZN16BackgroundLoader14RemoveAllLocksEv(void*);

extern char data_ov020_0218dcca;

struct Triple3 { unsigned int a, b, c; };
extern Triple3 data_ov020_0218d950;
extern Triple3 data_ov020_0218d944;

struct SetupContext0218cf8c {
#if defined(jpn)
    char pad0[0x400];
#else
    char pad0[0x470];
#endif

    SafeAllocator allocator;
};

// JPN: func_ov020_0218d7dc
// USA: func_ov020_0218cf8c  (semantic: InitializeAndDispatchLists_0218cf8c)
extern "C" ARM void func_ov020_0218cf8c(struct SetupContext0218cf8c* self) {
#if defined(jpn)
 enum {regionalOffset0=0x2c, regionalOffset1=0x448, regionalOffset2=0x468, regionalOffset3=0x4c};
#else
 enum {regionalOffset0=0x9c, regionalOffset1=0x4b8, regionalOffset2=0x4d8, regionalOffset3=0xbc};
#endif
    unsigned char* base = (unsigned char*)self;

    self->allocator.Reset();
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0, 0, 0x1f, 2, 0);

    _Z17ResetList0204af64P12List0204af64(base + regionalOffset0 + 0x400);
    _Z24SetWord0x18ClearByte0x1fPhi(base + regionalOffset0 + 0x400, 0);
    base[regionalOffset1] = base[regionalOffset1] & ~0xf;
    base[regionalOffset1] = (base[regionalOffset1] & ~0xf0) | 0x10;
    func_0204b5b4(base + regionalOffset0 + 0x400, 0);
    _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(base + regionalOffset0 + 0x400, &self->allocator);
    _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(base + regionalOffset0 + 0x400, 1, &self->allocator);
    _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(base + regionalOffset0 + 0x400, 0, 0);

    MapVRAMBanksToSubBG(4);
    func_ov020_0218cd64(0, 0, 1, 1, 0);

    _Z17ResetList0204af64P12List0204af64(base + regionalOffset3 + 0x400);
    _Z24SetWord0x18ClearByte0x1fPhi(base + regionalOffset3 + 0x400, 0);
    base[regionalOffset2] = (base[regionalOffset2] & ~0xf) | 1;
    base[regionalOffset2] = base[regionalOffset2] & ~0xf0;
    func_0204b5b4(base + regionalOffset3 + 0x400, 0);
    _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(base + regionalOffset3 + 0x400, &self->allocator);
    _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(base + regionalOffset3 + 0x400, 1, &self->allocator);
    _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(base + regionalOffset3 + 0x400, 0, 0);

    int taskId;
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    _ZN16BackgroundLoader10MaybeResetEv(loader);
    taskId = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader, &data_ov020_0218dcca, (void*)0);

  retryLoop:
    if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, taskId) == 0) goto waitForLoad;

    void* recFieldScratch;
    void* fileData;
    unsigned int fileLen;
    _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, taskId, &fileData, &fileLen);
    int count = _Z18CountActiveEntriesP19ActiveEntry02046900(fileData);

    void* resultsArray[6];
    int recSizeArray[6];
    for (int idx = 0; idx < count; idx++) {
        resultsArray[idx] = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(fileData, idx, &recFieldScratch, &recSizeArray[idx]);
    }

    Triple3 table1 = data_ov020_0218d950;
    Triple3 table2 = data_ov020_0218d944;

    int matchCount1 = 0;
    int matchCount2 = 0;

    for (int idx2 = 0; idx2 < count; idx2++) {
        if (idx2 == (&table1.a)[matchCount1]) {
            func_0204b174(base + regionalOffset0 + 0x400, resultsArray[idx2], &self->allocator, recSizeArray[idx2]);
            matchCount1++;
        }
        if (idx2 == (&table2.a)[matchCount2]) {
            func_0204b174(base + regionalOffset3 + 0x400, resultsArray[idx2], &self->allocator, recSizeArray[idx2]);
            matchCount2++;
        }
    }

    _ZN16BackgroundLoader10RemoveTaskEi(loader, taskId);

    _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(base + regionalOffset0 + 0x400, 0, 0, 0, 0, 0, 0x20, 0x19, 0);
    _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(base + regionalOffset3 + 0x400, 0, 0, 0, 0, 0, 0x20, 0x19, 0);
    _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(base + regionalOffset0 + 0x400, (void*)0);
    _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(base + regionalOffset3 + 0x400, (void*)0);
    goto afterLoop;
  waitForLoad:
    _ZN16BackgroundLoader14RemoveAllLocksEv(loader);
    goto retryLoop;
  afterLoop:

    *(volatile unsigned short*)0x4000050 = 0;
    *(volatile unsigned short*)0x4001050 = 0;
    volatile unsigned int* reg0 = (volatile unsigned int*)0x4000000;
    *reg0 = (*reg0 & ~0x1f00) | 0x200;
    volatile unsigned int* reg1000 = (volatile unsigned int*)0x4001000;
    *reg1000 = (*reg1000 & ~0x1f00) | 0x100;

    EncodeSignFlaggedHalfword((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword((short*)0x400106c, -16);
}
