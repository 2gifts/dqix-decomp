#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Trans_021d98b8 {
    float scale;
    unsigned int unk4;
    unsigned short unk8;
    unsigned short unkA;
};

struct Obj020979c0 {
    unsigned int data[8];
};

struct Trans_021d8b90 {
    Trans_021d98b8 trans;
    unsigned char unkC[0x10];
    unsigned char unk1c;
    unsigned char unk1d;
    Obj020979c0 unk20;
    unsigned int unk40;
    SafeAllocator allocator;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned short unk6c;
    unsigned char unk6e;
    int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned char unk80;
    unsigned char unk81;
};

void InitStruct020979c0(Obj020979c0* obj, unsigned char flag);
extern "C" Trans_021d98b8* func_ov028_021d98b8(Trans_021d98b8* self);

static inline unsigned int GX_GetVisiblePlane(void) {
    return (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
}

static inline unsigned int GXS_GetVisiblePlane(void) {
    return (*(volatile unsigned int*)0x4001000 & 0x1f00) >> 8;
}

// USA: func_ov028_021d8b90  (semantic: Trans_021d8b90)
extern "C" ARM void func_ov028_021d8b90(Trans_021d8b90* self) {
    func_ov028_021d98b8(&self->trans);
    self->unk1c = 0;
    self->unk1d = 0;
    InitStruct020979c0(&self->unk20, 0);
    self->unk40 = 0;
    self->allocator.ResetAllocatorPointer();
    self->unk58 = GX_GetVisiblePlane();
    self->unk5c = GXS_GetVisiblePlane();
    self->unk60 = 0;
    self->unk64 = 0;
    self->unk6c = 0;
    self->unk68 = 0;
    self->unk6e = 0;
    self->unk70 = -1;
    self->unk74 = 0;
    self->unk78 = 0;
    self->unk7c = 0;
    self->unk80 = 0;
    self->unk81 = 0;
}
