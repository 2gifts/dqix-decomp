#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "std_library_functions.h"

struct Context021b71d8 {
    unsigned char pad0[0x8e44];
    unsigned char pending[3];
    unsigned char pendingCount;
    unsigned char pad8e48[0x8eb4 - 0x8e48];
};

struct Holder021b71d8 {
    unsigned short id;
};

struct Self021b71d8 {
    unsigned char pad0[0x8];
    SafeAllocator allocator;
    unsigned char pad1c_fill[0x1c - 0x8 - sizeof(SafeAllocator)];
    unsigned short id;
    unsigned char pad1e[0x6b0 - 0x1e];
    Context021b71d8* context;
    unsigned char pad6b4[0x6c0 - 0x6b4];
    unsigned char pending[3];
    unsigned char pendingCount;
};

extern "C" Holder021b71d8* func_02012fe4(void);
extern "C" void _Z17EmptyStub02012de4v(AllocatorUnion* alloc);
extern "C" void func_020a0cc4(unsigned int size);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;
extern "C" void func_ov000_0215ce80(Context021b71d8* context);
extern "C" void func_ov000_0215fab0(Context021b71d8* context, unsigned char value);

// USA: func_ov017_021b71d8
extern "C" ARM void func_ov017_021b71d8(Self021b71d8* self) {
    GameState::GetInstance();
    Holder021b71d8* holder = func_02012fe4();
    _Z17EmptyStub02012de4v(&data_02114e20);
    func_020a0cc4(0x1f7dc);
    self->allocator.CreateTypeA(AllocateAligned4(&data_02114e20, 0x1f7dc), 0x1f7dc);
    self->id = holder->id;
    self->context = (Context021b71d8*)self->allocator.Allocate(sizeof(Context021b71d8));
    func_ov000_0215ce80(self->context);
    for (int i = 0; i < self->pendingCount; i++) {
        func_ov000_0215fab0(self->context, self->pending[i]);
    }
    memset(self->pending, 0, sizeof(self->pending));
    self->pendingCount = 0;
}
