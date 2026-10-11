#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
void* FindNodeById0218466c(void* obj, unsigned short id);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
extern "C" void func_0204719c(void* obj);
void Forward02047b30(void* a, int b, int c, int d);

struct Obj021f7290 { char pad[8]; unsigned short half8; unsigned short halfA; };

// USA: func_ov023_021f7290  (semantic: DispatchIfBothFound_021f7290)
extern "C" ARM void func_ov023_021f7290(struct Obj021f7290* obj, void* ctx, int p2, int p3) {
    if (p2 == 0 || p3 == 0) return;
    void* base = func_ov011_021845f8(ctx, obj->half8);
    void* node = FindNodeById0218466c(ctx, obj->halfA);
    if (base == NULL || node == NULL) return;
    SafeAllocator* alloc = (SafeAllocator*)((char*)base + 4);
    alloc->GetSizeWithLargestBlockRemoved();
    RestorePairTables0207df90((char*)node + 4);
    func_0204719c((char*)obj + 0x20);
    Forward02047b30((char*)obj + 0x20, p2, p3, (int)((char*)base + 4));
    BackupPairTables0207dfac((char*)node + 4);
    alloc->GetSizeWithLargestBlockRemoved();
}
