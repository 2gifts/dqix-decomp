#if defined(jpn)
#define R(j,u) (j)
#define _Z27ConfigureSubsystem_021889f8P11Obj021889f8 func_ov008_0218973c
#define data_ov005_0215cd20 data_ov005_0215e100
#define data_ov014_021894b8 data_ov014_0218a2f8
#define data_ov015_02193cfc data_ov015_0219482c
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_02194129 data_ov015_02194c69
#define func_ov008_02188730 func_ov008_02189444
#define func_ov014_02185c90 func_ov014_02186d00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

int GetGlobal02109400(void);
void BlankFunction02094b40(void);
extern "C" void func_02094ab0(int obj);
void ClearFirstWordThen0xC020972c8(int* p);
extern "C" void func_ov014_021845ec(void* self);

struct Obj_02186b30 {
    char pad0[0xa4];
    int fieldA4;
    char pad1[0xb4 - 0xa8];
    SafeAllocator* allocators;
    char pad2[0x168 - 0xb8];
    volatile int field168;
};

// USA: func_ov014_02186b30  (semantic: ResetLoaderAndAllocators_02186b30)
extern "C" ARM void func_ov014_02186b30(struct Obj_02186b30* self) {
    if (self->field168 >= 0) {
        BackgroundLoader::GetInstance()->RemoveTask(self->field168);
        self->field168 = -1;
    }
    int g = GetGlobal02109400();
    BlankFunction02094b40();
    func_02094ab0(g);
    ClearFirstWordThen0xC020972c8(&self->fieldA4);
    func_ov014_021845ec(self);
    if (self->allocators == 0) {
        return;
    }
    int i;
    for (i = 0; i < 5; i++) {
        if (self->allocators[i].GetSignedAllocator()) {
            self->allocators[i].Destroy();
        }
    }
}
