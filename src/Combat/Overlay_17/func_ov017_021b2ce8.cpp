#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "System/Graphics.h"

struct Obj020397cc;
struct Obj021b2c88;

GameResources* GetWord0x0(int* gameState);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
void CancelPendingAction020397cc(Obj020397cc* obj, int arg1);
int GetFieldIfFlag4(char* obj);
void SetFlagsAt0x244(unsigned char* obj, unsigned char mask);
void ClearFlagBits(unsigned char* obj, int mask);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
void PushInputLogA(int id);
void PushInputLogB(int id);
void SetByteField0x253(void* obj);
extern "C" void func_020a0cc4(unsigned int size, int ticks);
extern "C" void func_020a0c0c(void);
extern "C" void func_ov003_02174114(void* obj);
extern "C" void func_ov003_02173f70(void* obj, SafeAllocator* alloc);
extern "C" int func_ov003_021745fc(void* obj);
extern "C" void func_ov003_02174454(void* obj);
extern "C" void func_ov017_021b2c88(Obj021b2c88* self);

struct Screen_021b2ce8 {
    char pad0[0x38];
    int bgMode;
};

struct Task_021b2ce8 {
    unsigned char byte0;
    unsigned char done;
    char pad2[6];
    int state;
    SafeAllocator allocator;
};

extern AllocatorUnion data_02114e20;
extern Screen_021b2ce8* data_ov017_021d840c;

// USA: func_ov017_021b2ce8
extern "C" ARM void func_ov017_021b2ce8(Task_021b2ce8* self) {
#if defined(jpn)
 enum { regionalSize = 0xfcc };
#else
 enum { regionalSize = 0x1050 };
#endif
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetWord0x0((int*)gs);
    SetBitsInField4((unsigned int*)res, 0xc0);
    GameObject* leader = gs->GetUnknownGameObject();
    CancelPendingAction020397cc((Obj020397cc*)leader, 1);
    unsigned char* camera = (unsigned char*)GetFieldIfFlag4((char*)gs);
    SetFlagsAt0x244(camera, 3);
    int ticks = gs->GetTickCount();
    if (ticks < 0) {
        ticks = 1;
    }

    if (self->state == 0) {
        func_020a0cc4(0x33820, ticks);
        void* buffer = AllocateAligned4(&data_02114e20, 0x32000);
        if (buffer == NULL) {
            func_020a0c0c();
            self->done = 1;
            return;
        }
        self->allocator.CreateTypeA(buffer, 0x32000);
        self->allocator.Reset();
        data_ov017_021d840c = (Screen_021b2ce8*)self->allocator.Allocate(regionalSize);
        if (data_ov017_021d840c == NULL) {
            func_020a0c0c();
            self->done = 1;
            return;
        }
        PushInputLogA(3);
        PushInputLogB(1);
        func_ov003_02174114(data_ov017_021d840c);
        func_ov003_02173f70(data_ov017_021d840c, &self->allocator);
        SetBitsInWord((unsigned int*)res, 0x6000);
        self->state++;
    } else if (self->state == 1) {
        if (func_ov003_021745fc(data_ov017_021d840c)) {
            FontBankLoader* g = GetGlobal02109400();
            BlankFunction02094b40(g);
            func_02094ab0(g);
            BlankFunction02094b34(g, 0x6f, 5000, 1, 1);
            self->state++;
        }
    } else if (self->state == 2) {
        if (AlwaysTrue02094b4c(GetGlobal02109400())) {
            func_ov003_02174454(data_ov017_021d840c);
            self->state++;
        }
    } else {
        ClearBitsInField4((unsigned int*)res, 0xc0);
        DISPCNT = (data_ov017_021d840c->bgMode << 8) | (DISPCNT & ~0x1f00);
        ClearFlagBits(camera, 3);
        func_ov017_021b2c88((Obj021b2c88*)self);
        func_020a0c0c();
        self->done = 1;
        ClearBitsInWord((unsigned int*)res, 0x6000);
        SetByteField0x253(leader);
    }
}
