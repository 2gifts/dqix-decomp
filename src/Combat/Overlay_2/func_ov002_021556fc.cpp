#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct S020466c8;
struct Struct02074bd0;
struct Cont0205d1e0;
struct Cont0205d274;
struct Obj0205d2bc;
struct Obj0205d048;

char *GetGlobalField0x1c020421a0();
void SetField0x38(S020466c8 *s, int v);
void *GetPtrField0x2a04(GameState *gameState);
extern "C" void func_ov017_021cff8c(int id, int a);
extern "C" void func_ov016_0218b5c0(int a, int b);
void *GetGlobal02109400();
extern "C" void func_02094ab0(void *p);
void ClearFlag0x10IfSet(Struct02074bd0 *s);
void ReinitController02043204(char *p);
void ClearBuffers0204b010OverList0x98(Cont0205d1e0 *c);
void CallFunc0204b04cOverList0x98(Cont0205d274 *c);
void InitEntries0205d2bc(Obj0205d2bc *o);
extern "C" void func_0205d048(struct Obj0205d048 *obj);
extern "C" void *memset(void *dst, int value, unsigned int length);
void CleanInvalidateCacheRange(const void *p, unsigned int len);
extern "C" void LoadToMainBG1CharacterData(const void *data, unsigned int offset, unsigned int length);
void ResetAllocatorsAndClearFields0215b428(unsigned char *self);
void PopStack1AndTrigger(int v);
extern "C" void func_ov023_021eb26c(void *guide);

// USA: func_ov002_021556fc
extern "C" ARM void func_ov002_021556fc(char *self) {
    SetField0x38((S020466c8 *) GetGlobalField0x1c020421a0(), 0);
    unsigned char *p = (unsigned char *) GetPtrField0x2a04(GameState::GetInstance());
    for (int i = 0; i < p[0xf7c]; i++) {
        func_ov017_021cff8c((p + i)[0xf78], 0);
    }
    func_ov016_0218b5c0(1, -1);
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    for (int j = 0; j < 5; j++) {
        if (((int *) (self + 0x1ba4))[j] >= 0) {
            loader->RemoveTask(((int *) (self + 0x1ba4))[j]);
        }
        ((int *) (self + 0x1ba4))[j] = -1;
    }
    if (*(int *) (self + 0x2458) >= 0) {
        loader->RemoveTask(*(int *) (self + 0x2458));
        *(int *) (self + 0x2458) = -1;
    }
    if (*(int *) (self + 0x1bc4) >= 0) {
        loader->RemoveTask(*(int *) (self + 0x1bc4));
        *(int *) (self + 0x1bc4) = -1;
    }
    func_02094ab0(GetGlobal02109400());
    *(volatile unsigned int *) 0x4000000   = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
    *(volatile unsigned short *) 0x4000050 = 0;
    ClearFlag0x10IfSet((Struct02074bd0 *) (self + 0x38));
    ReinitController02043204(GetGlobalField0x1c020421a0());
    *(void **) (self + 0x1bd0) = 0;
    ClearBuffers0204b010OverList0x98((Cont0205d1e0 *) (self + 0x2c8 + 0xc00));
    CallFunc0204b04cOverList0x98((Cont0205d274 *) (self + 0x2c8 + 0xc00));
    InitEntries0205d2bc((Obj0205d2bc *) (self + 0x2c8 + 0xc00));
    func_0205d048((struct Obj0205d048 *) (self + 0x2c8 + 0xc00));
    if (*(void **) (self + 0x1bd8) != 0) {
        memset(*(void **) (self + 0x1bd8), 0, 0x20);
        CleanInvalidateCacheRange(*(void **) (self + 0x1bd8), 0x20);
        LoadToMainBG1CharacterData(*(void **) (self + 0x1bd8), 0, 0x20);
    }
    *(void **) (self + 0x1bd8) = 0;
    ResetAllocatorsAndClearFields0215b428((unsigned char *) self);
    PopStack1AndTrigger(1);
    if (*(void **) (self + 0x2468) != 0) {
        func_ov023_021eb26c(*(void **) (self + 0x2468));
    }
    SafeAllocator *allocs[8] = {
        (SafeAllocator *) (self + 0x810), (SafeAllocator *) (self + 0x828), (SafeAllocator *) (self + 0x83c),
        (SafeAllocator *) (self + 0x850), (SafeAllocator *) (self + 0x864), (SafeAllocator *) (self + 0x878),
        (SafeAllocator *) (self + 0x88c), (SafeAllocator *) (self + 0x8a0),
    };
    *(void **) (self + 0x1bd4) = 0;
    for (int k = 0; k < 8; k++) {
        SafeAllocator *a = allocs[k];
        if (a->GetSignedAllocator() != 0) {
            a->Destroy();
        }
    }
}
