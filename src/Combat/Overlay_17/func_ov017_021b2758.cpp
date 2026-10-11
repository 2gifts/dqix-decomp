// JPN: func_ov017_021b2e68
#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Field105 = 0x125, Field10c = 0x12c };
#else
enum { Field105 = 0x105, Field10c = 0x10c };
#endif

void SetField0x3b0Value(GameState* battleStruct, int value);
void* GetField0x3f8Address(GameState* battleStruct);
int GetFieldIfFlag4(char* obj);
void ClearFlagBits(unsigned char* obj, int mask);
void SetFlagsAt0x244(unsigned char* obj, unsigned char mask);
void SetField0x23cTrue(void* obj);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);
void CallHelperFourTimesWithSelf_0218f758(void* self);

struct Obj_021849bc;
int GetField114Masked_021849bc(struct Obj_021849bc* obj, int mask);

struct Obj021b2200;
void ClearPendingAndDestroyAllocator_021b2200(struct Obj021b2200* self);

extern "C" void* func_02012fe4(void);
extern "C" void func_020a0c0c(void);
extern "C" void func_ov017_0219bd1c(int, int, int, int);

struct GlobalSlot_021b2758 { unsigned int field0; int slot; };
extern GlobalSlot_021b2758 data_ov017_021d83f0;

struct Data02107930_021b2758 { unsigned char pad[0x90]; int f90; unsigned char pad2[4]; int f98; };

union Flags38_021b2758 {
    unsigned int raw;
    struct {
        unsigned int bit0 : 1;
        unsigned int bit1 : 1;
        unsigned int bit2 : 1;
        unsigned int : 2;
        unsigned int bit5 : 1;
        unsigned int : 26;
    } b;
};

struct SelfState_021b2758 {
    unsigned char pad0[0x38];
    Flags38_021b2758 field0x38;
    unsigned char pad1[2];
    unsigned char field0x3e;
    unsigned char pad2[1];
    int field0x40;
    int field0x44;
    unsigned char field0x48;
};

// USA: func_ov017_021b2758
extern "C" ARM int func_ov017_021b2758(SelfState_021b2758* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameResources* ov = func_ov017_0218b5b0();
    SetField0x3b0Value(battleStruct, self->field0x44);

    if (data_ov017_021d83f0.slot != 0) {
        if (GetField114Masked_021849bc((struct Obj_021849bc*)data_ov017_021d83f0.slot, 1)) self->field0x38.b.bit0 = 1;
        if (GetField114Masked_021849bc((struct Obj_021849bc*)data_ov017_021d83f0.slot, 2)) self->field0x38.raw |= 2;
        if (GetField114Masked_021849bc((struct Obj_021849bc*)data_ov017_021d83f0.slot, 4)) self->field0x38.raw |= 4;
        ClearPendingAndDestroyAllocator_021b2200((struct Obj021b2200*)self);
        func_020a0c0c();
    }

    ClearBitsInWord((unsigned int*)ov, 0x10);
    if (self->field0x38.b.bit0) {
        func_02012fe4();
        ClearBitsInWord((unsigned int*)ov, 4);
        func_ov017_0219bd1c(1, 0, 0, 0);
        self->field0x38.raw &= ~2;
        void* p = GetField0x3f8Address(battleStruct);
        if (self->field0x48 != 0) ((char*)p)[0x67] = 1;
        return 5;
    }
    if (self->field0x38.b.bit1) return 6;
    if (self->field0x38.b.bit2) return 7;

    battleStruct->GetUnknownGameObject();
    int flagVal = GetFieldIfFlag4((char*)battleStruct);
    unsigned char* ctx = (unsigned char*)func_02012fe4();
    if (flagVal != 0) {
        ClearFlagBits((unsigned char*)flagVal, 2);
        if (self->field0x3e != 0) {
            SetFlagsAt0x244((unsigned char*)flagVal, 2);
        }
        SetField0x23cTrue((void*)flagVal);
    }
    if (ctx != 0) {
        ctx[Field105] &= ~1;
    }

    if (!self->field0x38.b.bit5) {
        ClearBitsInField4((unsigned int*)ov, 0x609fe);
        SetBitsInField4((unsigned int*)ov, self->field0x40);
    }

    Data02107930_021b2758* d = (Data02107930_021b2758*)LightingManager::GetInstance();
    int f90 = d->f90;
    int idx = d->f98;
    unsigned char* base = ctx + Field10c;
    if (f90 != 0) idx = f90;
    unsigned short color;
    if (*(int*)(base + 0x304) == 1) {
        color = *(unsigned short*)(base + idx * 2 + 0x8c);
    } else {
        color = *(unsigned short*)(base + idx * 2 + 0x126);
    }
    Set3DClearColor(color, 0x10, 0x7fff, 0, 0);
    CallHelperFourTimesWithSelf_0218f758(ov);
    return 4;
}
