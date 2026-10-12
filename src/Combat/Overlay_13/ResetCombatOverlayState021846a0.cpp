#if defined(jpn)
#define func_ov013_021846a0 func_ov013_021856dc
#endif

#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

int GetGlobalField0x1c020421a0(void);

struct Struct02074bf4;
void ClearFlag0x11IfSet(struct Struct02074bf4*);
struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0*);

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0*, int);
struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0*);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(struct Cont0205d274*);
struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc*);
extern "C" void func_0205d048(void*);

void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" int LoadToMainBG1CharacterData(int, int, unsigned int);

// USA: func_ov013_021846a0  (semantic: ResetCombatOverlayState021846a0)
extern "C" ARM void func_ov013_021846a0(void* obj) {
    unsigned char* o = (unsigned char*)obj;

    int data4 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(o + LOW_REGION(0x5d8, 0x650)) >= 0) {
        ((BackgroundLoader*)(data4))->RemoveTask((int)(*(int*)(o + LOW_REGION(0x5d8, 0x650))));
        *(int*)(o + LOW_REGION(0x5d8, 0x650)) = -1;
    }

    ((unsigned char*)GetGlobalField0x1c020421a0())[0x1000 + LOW_REGION(0x7ee, 0x9be)] = 0;

    if (o[LOW_REGION(0x5cc, 0x640)]) {
        ClearFlag0x11IfSet((struct Struct02074bf4*)(o + LOW_REGION(0x1e, 0x20)));
        ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + LOW_REGION(0x34, 0x38)), 1);
        ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)(o + LOW_REGION(0x34, 0x38)));
        CallFunc0204b04cOverList0x98((struct Cont0205d274*)(o + LOW_REGION(0x34, 0x38)));
        InitEntries0205d2bc((struct Obj0205d2bc*)(o + LOW_REGION(0x34, 0x38)));
    } else {
        ClearFlag0x10IfSet((struct Struct02074bd0*)(o + LOW_REGION(0x1e, 0x20)));
        ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)(o + LOW_REGION(0x34, 0x38)));
        CallFunc0204b04cOverList0x98((struct Cont0205d274*)(o + LOW_REGION(0x34, 0x38)));
        InitEntries0205d2bc((struct Obj0205d2bc*)(o + LOW_REGION(0x34, 0x38)));
        func_0205d048((void*)(o + LOW_REGION(0x34, 0x38)));

        if (*(void**)(o + LOW_REGION(0x5dc, 0x654))) {
            memset(*(void**)(o + LOW_REGION(0x5dc, 0x654)), 0, 0x20);
            CleanInvalidateCacheRange(*(void**)(o + LOW_REGION(0x5dc, 0x654)), 0x20);
            LoadToMainBG1CharacterData((int)*(void**)(o + LOW_REGION(0x5dc, 0x654)), 0, 0x20);
        }

        volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
        *reg = (*reg & ~0x1f00) | (*(int*)(o + LOW_REGION(0x30, 0x34)) << 8);
    }

    if (((SafeAllocator*)(o + LOW_REGION(0x598, 0x60c)))->GetSignedAllocator()) {
        ((SafeAllocator*)(o + LOW_REGION(0x598, 0x60c)))->Destroy();
    }
    if (((SafeAllocator*)o)->GetSignedAllocator()) {
        ((SafeAllocator*)o)->Destroy();
    }

    o[LOW_REGION(0x5c8, 0x63c)] = 6;
}
