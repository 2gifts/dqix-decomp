#if defined(jpn)
#define R(j,u) (j)
#define func_ov013_021846a0 func_ov013_021856dc
#define func_ov013_02184d80 func_ov013_02185db4
#define func_ov013_02186160 func_ov013_02187178
#define func_ov013_021864f0 func_ov013_02187820
#define func_ov013_02186590 func_ov013_021878c0
#define func_ov013_0218678c func_ov013_02187ab8
#define func_ov013_0218683c func_ov013_02187b68
#define func_ov013_02186bd4 func_ov013_02187f00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

int GetGlobal02109400(void);
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

// USA: func_ov012_02185af0
extern "C" ARM void func_ov012_02185af0(unsigned char* self) {
    func_02094ab0((struct Obj02094ab0*)GetGlobal02109400());

    volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(volatile unsigned short*)((char*)reg + 0x50) = 0;

    ClearFlag0x10IfSet((struct Struct02074bd0*)(self + R(0,8)));

    ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)(self + R(0x90,0xac)));
    CallFunc0204b04cOverList0x98((struct Cont0205d274*)(self + R(0x90,0xac)));
    InitEntries0205d2bc((struct Obj0205d2bc*)(self + R(0x90,0xac)));
    func_0205d048((void*)(self + R(0x90,0xac)));

    memset(*(void**)(self + R(0x134c,0x137c)), 0, 0x20);
    CleanInvalidateCacheRange(*(void**)(self + R(0x134c,0x137c)), 0x20);
    LoadToMainBG1CharacterData((int)*(void**)(self + R(0x134c,0x137c)), 0, 0x20);

    *(int*)(self + R(0x1344,0x1374)) = 0;
    *(int*)(self + R(0x134c,0x137c)) = 0;

    void* ptrs[5];
    ptrs[0] = self + R(0x18,0x20);
    ptrs[1] = self + R(0x2c,0x34);
    ptrs[2] = self + R(0x40,0x48);
    ptrs[3] = self + R(0x54,0x5c);
    ptrs[4] = self + R(0x68,0x70);

    for (int i = 0; i < 5; i++) {
        SafeAllocator* p = (SafeAllocator*)ptrs[i];
        if (p->GetSignedAllocator()) {
            p->Destroy();
        }
    }
}
