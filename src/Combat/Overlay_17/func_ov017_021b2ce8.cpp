#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "System/Graphics.h"

struct Obj020397cc;
struct Obj021b2c88;

GameResources* GetWord0x0_0200fb8c(int* gameState);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);
void SetBitsInWord_0203b4a0(unsigned int* obj, unsigned int mask);
void ClearBitsInWord_0203b4b0(unsigned int* obj, unsigned int mask);
void CancelPendingAction020397cc(Obj020397cc* obj, int arg1);
int GetFieldIfFlag4_020100f8(char* obj);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void PushInputLogA_020a1df8(int id);
void PushInputLogB_020a1ef0(int id);
void SetByteField0x253_020397c0(void* obj);
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
    GameResources* res = GetWord0x0_0200fb8c((int*)gs);
    SetBitsInField4_0203b4d8((unsigned int*)res, 0xc0);
    GameObject* leader = gs->GetUnknownGameObject();
    CancelPendingAction020397cc((Obj020397cc*)leader, 1);
    unsigned char* camera = (unsigned char*)GetFieldIfFlag4_020100f8((char*)gs);
    SetFlagsAt0x244_020a28a0(camera, 3);
    int ticks = gs->GetTickCount();
    if (ticks < 0) {
        ticks = 1;
    }

    if (self->state == 0) {
        func_020a0cc4(0x33820, ticks);
        void* buffer = AllocateAligned4_02012d88(&data_02114e20, 0x32000);
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
        PushInputLogA_020a1df8(3);
        PushInputLogB_020a1ef0(1);
        func_ov003_02174114(data_ov017_021d840c);
        func_ov003_02173f70(data_ov017_021d840c, &self->allocator);
        SetBitsInWord_0203b4a0((unsigned int*)res, 0x6000);
        self->state++;
    } else if (self->state == 1) {
        if (func_ov003_021745fc(data_ov017_021d840c)) {
            FontBankLoader* g = GetGlobal02109400_02094a00();
            BlankFunction02094b40(g);
            func_02094ab0(g);
            BlankFunction02094b34(g, 0x6f, 5000, 1, 1);
            self->state++;
        }
    } else if (self->state == 2) {
        if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00())) {
            func_ov003_02174454(data_ov017_021d840c);
            self->state++;
        }
    } else {
        ClearBitsInField4_0203b4e8((unsigned int*)res, 0xc0);
        DISPCNT = (data_ov017_021d840c->bgMode << 8) | (DISPCNT & ~0x1f00);
        ClearFlagBits_020a28b0(camera, 3);
        func_ov017_021b2c88((Obj021b2c88*)self);
        func_020a0c0c();
        self->done = 1;
        ClearBitsInWord_0203b4b0((unsigned int*)res, 0x6000);
        SetByteField0x253_020397c0(leader);
    }
}
