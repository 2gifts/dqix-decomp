#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" int func_ov017_021d60f4(void* a);
extern int AbsPlus159IfNegative0215ad2c(int x);
int GetFieldPtrA0_021bbbe4(void* p);
unsigned int LoadResourceIntoGlobalBuffer_0215a750(const char* path, void** outPtr);
extern SafeAllocator* data_ov001_021658b8[8];
extern char data_ov001_021657df[];
extern "C" void _ZN8Object3D10InitializeEv(void* obj);
extern "C" int _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(int a, int b);
void RegisterCombatantSlot(GameState* battleStruct, int id, GameObject* combatant);
struct Shorts5c_374e0;
extern "C" void _ZN8Object3D8SetScaleEiii(struct Shorts5c_374e0* obj, short a, short b, short c);
extern "C" void _ZN8Object3D21MaybeSetBCFGAnimationEii(void* self, int a, int b);

struct LockCtx0216066c {
    int unused0;
    void* dataPtr;
    unsigned int size;
    SafeAllocator* allocator;
    int flag;
    char pad[0xc];
};

// USA: func_ov001_0216066c  (semantic: AllocateAndInitCombatantResource_0216066c)
extern "C" ARM int func_ov001_0216066c(void* self) {
    char path[0x50];
    struct LockCtx0216066c ctx;
    void* outPtr;
    unsigned int size;
    GameState* bs;
    SafeAllocator* allocator;
    void* newObj;
    int base;
    int id;

    bs = GameState::GetInstance();
    (int)BackgroundLoader::GetInstance();
    allocator = data_ov001_021658b8[0];
    id = AbsPlus159IfNegative0215ad2c(func_ov017_021d60f4(self));
    base = ((int)func_ov017_0218b5b0());
#if defined(jpn)
    base = *(int*)((char*)base + 0x3000 + 0x524);
#else
    base = *(int*)((char*)base + 0x3000 + 0x734);
#endif
    base = GetFieldPtrA0_021bbbe4((void*)base);
    sprintf(path, data_ov001_021657df, base + 0x4);
    BackgroundLoader::AddLockGlobal();
    size = LoadResourceIntoGlobalBuffer_0215a750(path, &outPtr);
    if (size == 0) {
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    newObj = allocator->Allocate(0xac);
    _ZN8Object3D10InitializeEv(newObj);
    ctx.dataPtr = outPtr;
    ctx.allocator = allocator;
    ctx.size = size;
    ctx.flag = 1;
    _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo((int)newObj, (int)&ctx);
    BackgroundLoader::RemoveLockGlobal();
    RegisterCombatantSlot(bs, id, (GameObject*)newObj);
    _ZN8Object3D8SetScaleEiii((struct Shorts5c_374e0*)newObj, 0x10a, 0x10a, 0x10a);
    _ZN8Object3D21MaybeSetBCFGAnimationEii(newObj, 0, 0);
    return 1;
}
