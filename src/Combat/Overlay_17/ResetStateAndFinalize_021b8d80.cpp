// JPN: func_ov017_021b9278
#if defined(jpn)
enum { RegionOffset8c = 0x4c };
#else
enum { RegionOffset8c = 0x8c };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern "C" int func_ov017_0218b5b0(void);
int GetGlobalField0x1c020421a0();
struct StructAllocGroup0208ba54;
void DestroyStructAllocGroup0208ba54(struct StructAllocGroup0208ba54* self);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern "C" void func_ov008_021845ac(void* p);
void SetCombatModeFromCase020dc2d0(int mode);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(int base, int a, int b);
struct Obj_021b994c;
void ResetFieldsToDefault_021b994c(struct Obj_021b994c* obj);
extern "C" void func_020a0c0c(void);

extern int data_02114e20;

// USA: func_ov017_021b8d80  (semantic: ResetStateAndFinalize_021b8d80)
extern "C" ARM void func_ov017_021b8d80(unsigned char* self) {
    int handle = func_ov017_0218b5b0();
    if (*(int*)(self + 0x120) > -1) {
        int field4 = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(field4))->RemoveTask((int)(*(int*)(self + 0x120)));
    }

    if (self[0x137] == 0) {
        *(int*)((char*)GetGlobalField0x1c020421a0() + RegionOffset8c) = 0;
        DestroyStructAllocGroup0208ba54((struct StructAllocGroup0208ba54*)(self + 0x30));
        SafeAllocator* allocA = (SafeAllocator*)(self + 0x8);
        void* pA = allocA->GetSignedAllocator();
        if (pA) {
            allocA->Destroy();
            TailForward02012da4((AllocatorUnion*)&data_02114e20, pA);
        }
    }

    if (self[0x128] != 0) {
        func_ov008_021845ac(*(void**)(self + 0x118));
        SafeAllocator* allocB = (SafeAllocator*)(self + 0x1c);
        void* pB = allocB->GetSignedAllocator();
        if (pB) {
            allocB->Destroy();
            TailForward02012da4((AllocatorUnion*)&data_02114e20, pB);
        }
        *(int*)(self + 0x118) = 0;

        volatile unsigned short* reg = (volatile unsigned short*)0x4001008;
        reg[0] = (reg[0] & ~3) | 1;
        reg[1] = (reg[1] & ~3) | 2;
        reg[2] = reg[2] & ~3;

        SetCombatModeFromCase020dc2d0(0);
        _Z16SetSubBrightnessP13GameResourcesii(handle, 0, 0xf);
    }

    ResetFieldsToDefault_021b994c((struct Obj_021b994c*)self);
    func_020a0c0c();
}
