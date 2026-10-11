#include <globaldefs.h>
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

struct Struct0204a82c {
    int f0;
    short f4;
    short f6;
    short f8;
    char fa;
};

struct ScaledElementList0204aa48 {
    char* base;
    short index;
    char pad[4];
    unsigned char flag;
};

struct RebaseStruct {
    char pad[8];
    char* off8;
    char* offc;
};

struct Struct02094a24;

struct Field1c {
    char pad0[0x34];
    void* f34;
    char pad38[0x10];
    void* f48;
    void* f4c;
    void* f50;
    char pad54[8];
    void* f5c;
    void* f60;
    void* f64;
    char pad68[0x26c];
    void* f2d4;
};

struct Global02107800 {
    void* f0;
    void* f4;
    void* f8;
    void* fc;
    void* f10;
    void* f14;
    void* f18;
    struct Field1c* f1c;
    char pad20[4];
    void* f24;
    void* f28;
};

extern struct Global02107800 data_02107800;
extern SafeAllocator data_0210783c;
extern char data_020f000b;
extern char data_020f0023;
extern char data_020f003f;

extern "C" void _Z33RegisterFieldTableEntries02042944Pv(void*);
extern "C" void _Z19ClearStruct0204a82cP14Struct0204a82c(struct Struct0204a82c*);
int GetScaledElementOffset(struct ScaledElementList0204aa48*);
extern "C" void _Z18InitStruct02094a24P14Struct02094a24(struct Struct02094a24*);
extern "C" void _Z21BlankFunction02094a20v(void*, SafeAllocator*);
void StoreGlobal02109400(int);
void RebaseOffsets(struct RebaseStruct*);

// USA: func_020421c4
extern "C" ARM void func_020421c4(SafeAllocator* alloc) {
    unsigned int fileLen;
    struct Struct0204a82c entry;
    GPCReadPair pair;
    unsigned int decLen;
    unsigned int aligned;
    unsigned int old;
    unsigned int size;
    void* buf;
    void* p;
    struct Field1c* f1c;
    unsigned int off;
    unsigned char* base;
    unsigned int cap;

    p = alloc->Allocate(0x400);
    data_0210783c.CreateTypeA(p, 0x400);
    data_02107800.f1c = (struct Field1c*)alloc->Allocate(0x1e2c);
    data_02107800.f0 = alloc->Allocate(0xf99);
    data_02107800.f1c->f34 = alloc->Allocate(0xe0);
    data_02107800.f14 = alloc->Allocate(0x960);
    data_02107800.f8 = alloc->Allocate(0x280);
    data_02107800.f28 = alloc->Allocate(0x280);
    data_02107800.f24 = alloc->Allocate(0x960);
    data_02107800.f18 = alloc->Allocate(0x960);
    data_02107800.fc = alloc->Allocate(0x960);
    _Z33RegisterFieldTableEntries02042944Pv(alloc);
    BackgroundLoader::AddLockGlobal();

    fileLen = 0;
    buf = LoadFileIntoMemory(&data_020f000b, data_0211e33c, &fileLen);
    _Z19ClearStruct0204a82cP14Struct0204a82c(&entry);
    if (buf != 0) {
        memcpy(&entry, buf, 0xc);
    }
    size = GetScaledElementOffset((struct ScaledElementList0204aa48*)&entry);
    p = alloc->Allocate(size);
    data_02107800.f4 = p;
    memcpy(p, (void*)((int)data_0211e33c + 0x10), size);

    GPCReadPair* rp = &pair;
    off = 0;
    decLen = off;
    base = data_0211e33c;
    cap = 0x30000;
    ZeroInitGPCPointer(&rp->pGPCFile);
    rp->ZeroInitializeMachine();
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, &data_020f0023,
            base, decLen, cap, 0, 0)) {
        old = decLen;
        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, base + old, decLen,
            cap - old, &data_020f003f);
        cap = (decLen + 3) & ~3;
        pair.Reset();
        cap = off + (off + (off + cap));
        decLen = cap;
        memcpy((void*)0x01ff9740, base + old, cap);
    }

    BackgroundLoader::RemoveLockGlobal();
    data_0210783c.Reset();
    f1c = data_02107800.f1c;
    f1c->f2d4 = &data_0210783c;
    p = alloc->Allocate(0x68);
    _Z18InitStruct02094a24P14Struct02094a24((struct Struct02094a24*)p);
    _Z21BlankFunction02094a20v(p, alloc);
    StoreGlobal02109400((int)p);
    RebaseOffsets((struct RebaseStruct*)((char*)0x01ff9740 + off));
    if ((char*)0x01ff9740 + off != 0) {
        data_02107800.f10 = (void*)((char*)0x01ff9740 + off);
    }
    data_02107800.f1c->f48 = data_02107800.f14;
    data_02107800.f1c->f4c = data_02107800.f8;
    data_02107800.f1c->f50 = data_02107800.f28;
    data_02107800.f1c->f5c = data_02107800.f24;
    data_02107800.f1c->f60 = data_02107800.f18;
    data_02107800.f1c->f64 = data_02107800.fc;
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}
