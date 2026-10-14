#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

int GetGlobal02109400_02094a00(void);
struct Obj02094ab0;
extern "C" void func_02094ab0(struct Obj02094ab0* obj);

struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);

struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0*);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(struct Cont0205d274*);
struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc*);
extern "C" void func_0205d048(void*);

void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToMainBG1CharacterData(int, int, unsigned int);

// USA: func_ov008_021894b8
extern "C" ARM void func_ov008_021894b8(unsigned char* self) {
    func_02094ab0((struct Obj02094ab0*)GetGlobal02109400_02094a00());

    volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(volatile unsigned short*)((char*)reg + 0x50) = 0;

    ClearFlag0x10IfSet((struct Struct02074bd0*)self);

    ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)(self + 0x18));
    CallFunc0204b04cOverList0x98((struct Cont0205d274*)(self + 0x18));
    InitEntries0205d2bc((struct Obj0205d2bc*)(self + 0x18));
    func_0205d048((void*)(self + 0x18));

    if (*(void**)(self + 0x2a4) != 0) {
        memset(*(void**)(self + 0x2a4), 0, 0x20);
        CleanInvalidateCacheRange(*(void**)(self + 0x2a4), 0x20);
        LoadToMainBG1CharacterData((int)*(void**)(self + 0x2a4), 0, 0x20);
    }

    *(int*)(self + 0x2a0) = 0;
    *(int*)(self + 0x2a4) = 0;

    void* ptrs[4];
    ptrs[0] = self + 0x200;
    ptrs[1] = self + 0x214;
    ptrs[2] = self + 0x228;
    ptrs[3] = self + 0x23c;

    for (int i = 0; i < 4; i++) {
        SafeAllocator* p = (SafeAllocator*)ptrs[i];
        if (p->GetSignedAllocator()) {
            p->Destroy();
        }
    }
}
