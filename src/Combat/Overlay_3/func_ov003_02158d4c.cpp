#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "System/Cache.h"
#include "std_library_functions.h"

int GetGlobal02109400(void);
extern "C" void func_02094ab0(void);
struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
struct Obj020e25e8;
void ResetSelectionState020e25e8(struct Obj020e25e8* obj);
struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0* obj);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(struct Cont0205d274* obj);
struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc* obj);
extern "C" void func_0205d048(void* obj);
extern "C" int LoadToMainBG1CharacterData(int src, int offset, unsigned int size);
extern "C" int LoadToMainBG1ScreenData(int src, int offset, unsigned int size);
int GetGlobalField0x1c020421a0(void);
extern "C" void func_02043124(void* self);
void ReinitController02043204(char* obj);
extern "C" void* __clear(void* dst, int count);

struct Screen02158d4c {
    SafeAllocator alloc0;
    SafeAllocator alloc14;
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    char pad50[0x7c - 0x50];
    int field_0x7c;
    char flags80[0xf4 - 0x80];
    char list0f4[0x570 - 0xf4];
    struct Obj020e25e8* selection;
    char pad574[0x57c - 0x574];
    int field_0x57c;
};

// USA: func_ov003_02158d4c
extern "C" ARM void func_ov003_02158d4c(Screen02158d4c* self) {
    GetGlobal02109400();
    func_02094ab0();

    if (self->selection != NULL && GetInnerFlagBit0020e28dc((struct Outer020e28dc*)self->selection)) {
        ResetSelectionState020e25e8(self->selection);
    }

    unsigned int* reg = (unsigned int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(unsigned short*)0x4000050 = 0;
    ClearFlag0x10IfSet((struct Struct02074bd0*)self->flags80);

    ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)self->list0f4);
    CallFunc0204b04cOverList0x98((struct Cont0205d274*)self->list0f4);
    InitEntries0205d2bc((struct Obj0205d2bc*)self->list0f4);
    func_0205d048(self->list0f4);

    self->alloc28.Reset();
    void* buf = self->alloc28.Allocate(0x800);
    memset(buf, 0, 0x800);
    CleanInvalidateCacheRange(buf, 0x20);
    LoadToMainBG1CharacterData((int)buf, 0, 0x20);
    LoadToMainBG1ScreenData((int)buf, 0, 0x800);

    void* g = (void*)GetGlobalField0x1c020421a0();
    func_02043124(g);
    ReinitController02043204((char*)g);

    self->field_0x7c = 0;
    self->field_0x57c = 0;

    SafeAllocator* arr[5];
    __clear(arr, sizeof(arr));
    arr[0] = &self->alloc3c;
    arr[1] = &self->alloc28;
    arr[2] = &self->alloc14;
    arr[3] = &self->alloc0;

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i]->GetSignedAllocator() != NULL) {
            arr[i]->Destroy();
        }
    }
}
