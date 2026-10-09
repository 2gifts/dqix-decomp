#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <System/Graphics.h>
#include <System/Memory.h>
#include <std_library_functions.h>

struct GlobalField0x1c {
    char pad0[0x5c];
    void* field_0x5c;
    char pad60[0x998 - 0x60];
    int field_0x998;
};

struct LoaderTask0215c650;

struct Obj0216bb70 {
    int field_0x0;
    short mode;
    short step;
    short field_0x8;
    short field_0xa;
    char padc[0x14 - 0xc];
    char loader[0x404 - 0x14];
    unsigned char field_0x404;
    unsigned char loadSucceeded;
    char pad406[0x12d4 - 0x406];
    SafeAllocator allocator;
    char pad12e8[0x13ec - 0x12e8];
    unsigned char flags;
};

extern "C" GlobalField0x1c* _Z26GetGlobalField0x1c020421a0v();
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);
extern AllocatorUnion data_02114e20;

extern "C" void func_ov003_0215c650(void* loader);
extern "C" void func_ov003_0215c568(void* loader, SafeAllocator* allocator);
extern "C" int func_ov003_0215c924(void* loader, unsigned int tick);
extern "C" void func_ov003_0215c800(void* loader);
extern "C" void func_ov003_0216d8d4(Obj0216bb70* obj, int key, int p3, int p4, int p5);

// USA: func_ov003_0216bb70
extern "C" ARM void func_ov003_0216bb70(Obj0216bb70* self)
{
    GameState* gameState = GameState::GetInstance();

    if (self->step == 0) {
        memset(_Z26GetGlobalField0x1c020421a0v()->field_0x5c, 0, 0x960);
        void* buffer = AllocateAligned4(&data_02114e20, 0x10000);
        VectorizedMemset(buffer, 0, 0x10000);
        self->allocator.CreateTypeA(buffer, 0x10000);
        self->allocator.Reset();
        func_ov003_0215c650(self->loader);
        func_ov003_0215c568(self->loader, &self->allocator);
        self->field_0x404 = 1;
        self->step = 1;
    }
    if (self->step == 1) {
        if (func_ov003_0215c924(self->loader, gameState->GetTickCount())) {
            self->step = 2;
        }
    }
    if (self->step == 2) {
        unsigned char succeeded = self->loadSucceeded;
        func_ov003_0215c800(self->loader);
        SignedAllocatorHeader* header = self->allocator.GetSignedAllocator();
        if (header != NULL) {
            self->allocator.Destroy();
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, header);
        }
        if (succeeded == 0) {
            self->mode = 7;
            self->step = 0;
            return;
        }
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        self->field_0xa = 3;
        _Z26GetGlobalField0x1c020421a0v()->field_0x998 = 1;
        func_ov003_0216d8d4(self, 0x29, -1, -1, -1);
        self->mode = 1;
        self->step = 0;
        self->field_0x8 = 0;
        self->flags |= 1;
    }
}
