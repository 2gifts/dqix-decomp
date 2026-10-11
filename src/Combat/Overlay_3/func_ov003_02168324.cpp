#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { kRegionValueCC_C8 = 0xc8 };
enum { kRegionValueE4_E0 = 0xe0 };
enum { kRegionValue2D8_228 = 0x228 };
enum { kRegionValue2DC_22C = 0x22c };
enum { kRegionValue2E0_230 = 0x230 };
enum { kRegionValue4E4_4E0 = 0x4e0 };
#else
enum { kRegionValueCC_C8 = 0xcc };
enum { kRegionValueE4_E0 = 0xe4 };
enum { kRegionValue2D8_228 = 0x2d8 };
enum { kRegionValue2DC_22C = 0x2dc };
enum { kRegionValue2E0_230 = 0x2e0 };
enum { kRegionValue4E4_4E0 = 0x4e4 };
#endif


int GetGlobal02109400(void);
extern "C" void func_02094ab0(void);
struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
extern "C" void _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0(void* obj);
extern "C" void _Z28CallFunc0204b04cOverList0x98P12Cont0205d274(void* obj);
extern "C" void _Z19InitEntries0205d2bcP11Obj0205d2bc(void* obj);
extern "C" void func_0205d048(void* obj);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
int GetGlobalField0x1c020421a0(void);
extern "C" void func_02043124(void* self);
void ReinitController02043204(char* obj);
extern "C" void* __clear(void* dst, int count);

// USA: func_ov003_02168324  (semantic: TeardownControllerAndDestroyAllocators_02168324)
// JPN: func_ov003_021681ac
extern "C" ARM void func_ov003_02168324(char* obj) {
    GetGlobal02109400();
    func_02094ab0();

    int* reg = (int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(short*)((char*)reg + 0x50) = 0;
    ClearFlag0x10IfSet((struct Struct02074bd0*)(obj + kRegionValueCC_C8));

    _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0(obj + kRegionValueE4_E0);
    _Z28CallFunc0204b04cOverList0x98P12Cont0205d274(obj + kRegionValueE4_E0);
    _Z19InitEntries0205d2bcP11Obj0205d2bc(obj + kRegionValueE4_E0);
    func_0205d048(obj + kRegionValueE4_E0);

    memset(*(void**)(obj + 0x7c), 0, 0x20);
    CleanInvalidateCacheRange(*(void**)(obj + 0x7c), 0x20);
    LoadToMainBG1CharacterData((int)*(void**)(obj + 0x7c), 0, 0x20);

    void* g = (void*)GetGlobalField0x1c020421a0();
    func_02043124(g);
    ReinitController02043204((char*)g);
    *(int*)((char*)g + kRegionValue2D8_228) = 0;
    *(int*)((char*)g + kRegionValue2DC_22C) = 0;
    *(int*)((char*)g + kRegionValue2E0_230) = 0;
    *(int*)(obj + kRegionValue4E4_4E0) = 0;

    SafeAllocator* arr[6];
    __clear(arr, sizeof(arr));
    arr[0] = (SafeAllocator*)(obj + 0x50);
    arr[1] = (SafeAllocator*)(obj + 0x3c);
    arr[2] = (SafeAllocator*)(obj + 0x28);
    arr[3] = (SafeAllocator*)(obj + 0x14);
    arr[4] = (SafeAllocator*)obj;

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i]->GetSignedAllocator() != NULL) {
            arr[i]->Destroy();
        }
    }
}
