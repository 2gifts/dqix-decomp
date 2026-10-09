#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "World/Object3D.h"

extern "C" void NSBXX_Model_SetPolygonID(void* obj, unsigned int value);

struct Fields020407b4;
void SetFields0x44(struct Fields020407b4* obj, int a, int b, int c);

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;

// USA: func_02046e70
extern "C" ARM void func_02046e70(void* self, void* a1, Object3D* a2) {
    *(int*)((char*)self + 0x4) = *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x20) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xc) = 0x41700000;
    *(int*)((char*)self + 0xec) = -1;
    *(unsigned char*)((char*)self + 0x1c) = 1;
    *(unsigned char*)((char*)self + 0x1d) = 1;

    GameState::GetInstance();
    ((Object3D*)((char*)self + 0x3c))->Initialize();
    ((SafeAllocator*)((char*)self + 0x24))->ResetAllocatorPointer();

    *(Object3D**)((char*)self + 0xe8) = a2;
    if (a2 != NULL) {
        NSBXX_Model_SetPolygonID(*(void**)(*(char**)((char*)a2 + 8) + 0x54), 0x3d);
        Object3D* o1 = *(Object3D**)((char*)self + 0xe8);
        o1->SetScale(0x1000, 0x1000, 0x1000);
        Object3D* o2 = *(Object3D**)((char*)self + 0xe8);
        SetFields0x44((struct Fields020407b4*)o2, 0, -0xa000, 0x1000);
        Object3D* o3 = *(Object3D**)((char*)self + 0xe8);
        o3->MaybeSetBCFGAnimation(0, 0);
    }

    *(void**)((char*)self + 0x38) = a1;
    if (a1 != NULL) {
        return;
    }
    void* buf = AllocateAligned4(&data_02114e20, 0x301c);
    if (buf != NULL) {
        SafeAllocator* alloc = (SafeAllocator*)((char*)self + 0x24);
        alloc->ResetAllocatorPointer();
        alloc->CreateTypeA(buf, 0x301c);
        alloc->Reset();
        return;
    }

    *(unsigned char*)((char*)self + 0x1d) = 0;
    ((SafeAllocator*)((char*)self + 0x24))->ResetAllocatorPointer();
    *(int*)((char*)self + 0x0) = -1;
}