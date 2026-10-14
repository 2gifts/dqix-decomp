#pragma opt_vectorize_loops off
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"

void EncodeSignFlaggedHalfword_020c39a0(short* out, int value);

extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void func_ov020_0218c7bc(int, int, int, int, int);
struct List0204af64;
void ResetList0204af64(List0204af64*);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char*, int);
extern "C" void func_0204b5b4(void*, int);
struct AllocTarget0204b12c;
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c*, SafeAllocator*);
struct Foo0204af38;
void AllocateArray0204af38(Foo0204af38*, int, SafeAllocator*);
struct Obj0204b5e8;
void DispatchViaTable0204b5e8(Obj0204b5e8*, int, int);
extern "C" int DisableSubObjVRAMBanks();
extern "C" int DisableSubBGVRAMBanks();
void SetSubBgMode_020c3984(unsigned int);
extern "C" void MapVRAMBanksToSubObj(unsigned short value);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_ov020_0218cd64(int, int, int, int, int);
void LoadFileIntoMemory(const char*, void*, unsigned int*);
struct ActiveEntry02046900;
int CountActiveEntries(ActiveEntry02046900*);
struct Rec020467f0;
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
void DispatchByTag0204b2e0(void*, char*);
struct SelfTag0204b3a0;
void DispatchByTagLookup0204b3a0(SelfTag0204b3a0*, char*);
struct List0204b0e8;
void FlushAndDispatchList0204b0e8(List0204b0e8*, void*);
struct List0204afb4;
void ResetRecordList0204afb4(List0204afb4*);
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
    EncodeSignFlaggedHalfword_020c39a0((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword_020c39a0((short*)0x400106c, -16);
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0, 1, 1, 1, 0);

    ResetList0204af64((List0204af64*)(base + regionalOffset0 + 0x400));
    SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)(base + regionalOffset0 + 0x400), 0);
    struct List0218d32c* list = (struct List0218d32c*)(base + regionalOffset0 + 0x400);
    list->lowNibble = 0;
    list->highNibble = 1;
    func_0204b5b4(list, 1);
    AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)(base + regionalOffset0 + 0x400), (SafeAllocator*)&self->allocator);
    AllocateArray0204af38((Foo0204af38*)(base + regionalOffset0 + 0x400), 1, (SafeAllocator*)&self->allocator);
    DispatchViaTable0204b5e8((Obj0204b5e8*)(base + regionalOffset0 + 0x400), 0, 0);

    DisableSubObjVRAMBanks();
    DisableSubBGVRAMBanks();
    SetSubBgMode_020c3984(0);

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

    BackgroundLoader::AddLockGlobal();

    if (mode == 1) {
        LoadFileIntoMemory((const char*)&data_ov020_0218dce2, (void*)&data_0211e33c, &outLen);
    } else {
        LoadFileIntoMemory((const char*)&data_ov020_0218dcf8, (void*)&data_0211e33c, &outLen);
    }

    int count = CountActiveEntries((ActiveEntry02046900*)&data_0211e33c);

    for (int i = 0; i < count; i++) {
        resultsArray[i] = (char*)FindRecordByIndex((Rec020467f0*)&data_0211e33c, i, &recFieldScratch, &sizeArr[i]);
    }

    ResetList0204af64((List0204af64*)list3);
    list3[0x1c] = (list3[0x1c] & ~0xf) | 1;
    list3[0x1c] = list3[0x1c] & ~0xf0;
    func_0204b5b4(list3, 3);
    SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)list3, 0);
    DispatchViaTable0204b5e8((Obj0204b5e8*)list3, 0, 0);

    for (int j = 0; j < 3; j++) {
        DispatchByTag0204b2e0(list3, resultsArray[j]);
        DispatchByTagLookup0204b3a0((SelfTag0204b3a0*)list3, resultsArray[j]);
    }

    FlushAndDispatchList0204b0e8((List0204b0e8*)list3, (void*)0);
    ResetRecordList0204afb4((List0204afb4*)list3);
    BackgroundLoader::RemoveLockGlobal();

    *(volatile unsigned short*)0x4000050 = 0;
    *(volatile unsigned short*)0x4001050 = 0;
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 1, 2, 0xf, 0x1f);

    volatile unsigned int* reg0 = (volatile unsigned int*)0x4000000;
    *reg0 = (*reg0 & ~0x1f00) | 0x1300;

    EncodeSignFlaggedHalfword_020c39a0((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword_020c39a0((short*)0x400106c, -16);
}
