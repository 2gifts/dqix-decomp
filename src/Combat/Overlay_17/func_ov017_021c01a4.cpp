#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

struct Obj020397cc;
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(struct Obj020397cc* obj, int arg1);
unsigned char* GetFieldIfFlag4(char* obj);
void SetFlagsAt0x244(unsigned char* obj, unsigned char mask);
void ClearFlagBits(unsigned char* obj, int mask);
void SetByteField0x253(void* obj);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
struct Obj02092aa4;
extern "C" void _Z15InitObj02092aa4P11Obj02092aa4h(struct Obj02092aa4* obj, int param);
void CreateTypeAFromAllocator(SafeAllocator* self, SafeAllocator* src);
extern "C" int func_020a0cc4(int id);
extern "C" void func_020a0c0c();
extern "C" int func_02092bcc(struct Obj02092aa4* obj, int delta);
extern "C" void func_02092b34(struct Obj02092aa4* obj);

extern AllocatorUnion data_02114e20;
extern struct Obj02092aa4* data_ov017_021d8474;

struct Obj021c01a4 {
    unsigned char byte0;
    unsigned char done;
    unsigned char pad2[6];
    SafeAllocator alloc;
    int state;
    signed char b20;
};

extern "C" void func_ov017_021c0160(struct Obj021c01a4* self);

// USA: func_ov017_021c01a4
extern "C" ARM void func_ov017_021c01a4(struct Obj021c01a4* self) {
    GameState* gs = GameState::GetInstance();
    GameObject* obj = gs->GetUnknownGameObject();
    _Z27CancelPendingAction020397ccP11Obj020397cci((struct Obj020397cc*)obj, 1);
    unsigned char* flags = GetFieldIfFlag4((char*)gs);
    SetFlagsAt0x244(flags, 1);

    if (self->state == 0) {
        func_020a0cc4(0xc3c);
        void* buf = AllocateAligned4(&data_02114e20, 0xc3c);
        if (buf == NULL) {
            func_020a0c0c();
            self->done = 1;
            return;
        }
        self->alloc.CreateTypeA(buf, 0xc3c);
        self->alloc.Reset();
        data_ov017_021d8474 = (struct Obj02092aa4*)self->alloc.Allocate(0x3c);
        if (data_ov017_021d8474 == NULL) {
            func_020a0c0c();
            self->done = 1;
            return;
        }
        _Z15InitObj02092aa4P11Obj02092aa4h(data_ov017_021d8474, self->b20);
        CreateTypeAFromAllocator((SafeAllocator*)data_ov017_021d8474, &self->alloc);
        self->state++;
    } else if (self->state == 1) {
        if (func_02092bcc(data_ov017_021d8474, GameState::GetInstance()->GetTickCount())) {
            self->state++;
        }
    } else if (self->state == 2) {
        func_02092b34(data_ov017_021d8474);
        self->state++;
    } else if (self->state == 3) {
        func_ov017_021c0160(self);
        ClearFlagBits(flags, 1);
        SetByteField0x253(obj);
        self->state++;
        self->done = 1;
        func_020a0c0c();
    }
}
