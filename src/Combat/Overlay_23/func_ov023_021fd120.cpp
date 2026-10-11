#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
void* FindNodeById0218466c(void* obj, unsigned short id);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
extern "C" void _ZN8Object3D10InitializeEv(void* obj);
extern "C" int _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(int a, int b);
extern "C" void _ZN8Object3D21MaybeSetBCFGAnimationEii(void*, int, int);
struct Shorts5c_374e0;
extern "C" void _ZN8Object3D8SetScaleEiii(struct Shorts5c_374e0* obj, short a, short b, short c);

struct Obj021fd120 { char pad[8]; unsigned short half8; unsigned short halfA; };

// USA: func_ov023_021fd120
extern "C" ARM void func_ov023_021fd120(struct Obj021fd120* obj, void* ctx, int p2, int p3) {
    if (p2 == 0 || p3 == 0) return;
    void* base = func_ov011_021845f8(ctx, obj->half8);
    void* node = FindNodeById0218466c(ctx, obj->halfA);
    if (base == NULL || node == NULL) return;
    SafeAllocator* alloc = (SafeAllocator*)((char*)base + 4);
    alloc->GetSizeWithLargestBlockRemoved();
    RestorePairTables0207df90((char*)node + 4);
    _ZN8Object3D10InitializeEv((char*)obj + 0x20);
    struct RunCtx021fd120 { int f0; int f4; int f8; void* fc; int f10; int f14; int f18; int f1c; } local;
    local.f4 = p2;
    local.f8 = p3;
    local.fc = alloc;
    _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo((int)((char*)obj + 0x20), (int)&local);
    _ZN8Object3D21MaybeSetBCFGAnimationEii((char*)obj + 0x20, 0, 0);
    _ZN8Object3D8SetScaleEiii((struct Shorts5c_374e0*)((char*)obj + 0x20), 0x10a, 0x10a, 0x10a);
    BackupPairTables0207dfac((char*)node + 4);
    alloc->GetSizeWithLargestBlockRemoved();
}
