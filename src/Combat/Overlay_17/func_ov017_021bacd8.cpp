#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

#if defined(jpn)
enum { Fieldf43c = 0xf454, Field3fc = 0x414 };
#else
enum { Fieldf43c = 0xf43c, Field3fc = 0x3fc };
#endif

int GetFieldIfFlag4_020100f8(char* obj);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void SetByteField0x253_020397c0(void* obj);
void PushInputLogA_020a1df8(int id);

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

struct Obj021bac8c;
extern "C" void func_ov017_021bac8c(struct Obj021bac8c* self);

extern "C" void func_020a0cc4(unsigned int);
extern "C" void func_020a0c0c(void);
extern "C" int func_ov017_021959b4(void);

extern "C" void func_ov003_0215c650(void* p);
extern "C" void func_ov003_0215c568(void* p, void* alloc);
extern "C" void func_ov003_0215caa4(void* p);
extern "C" int func_ov003_0215c924(void* p, int scale);
extern "C" void func_ov003_0215c800(void* p);

void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;

struct Obj021bacd8 {
    char pad0;
    unsigned char flag1;
    char pad2[6];
    int state;
    SafeAllocator alloc;
    void* field20;
};

// USA: func_ov017_021bacd8  (semantic: AdvanceAllocatorSetup_021bacd8)
extern "C" ARM void func_ov017_021bacd8(Obj021bacd8* self) {
    GameState* battle = GameState::GetInstance();
    unsigned int* ov = ((unsigned int*)func_ov017_0218b5b0());
    GameObject* c = battle->GetUnknownGameObject();
    int flagResult = GetFieldIfFlag4_020100f8((char*)battle);
    SetBitsInField4_0203b4d8(ov, 0xc0);
    CancelPendingAction020397cc((struct Obj020397cc*)c, 1);
    SetFlagsAt0x244_020a28a0((unsigned char*)flagResult, 3);
    int scale = (int)battle->GetTickCount();
    if (scale < 0) {
        scale = 1;
    }
    int state = self->state;
    if (state == 0) {
        func_020a0cc4(Fieldf43c);
        void* buf = AllocateAligned4_02012d88(&data_02114e20, Fieldf43c);
        if (buf == NULL) {
            func_020a0c0c();
            self->flag1 = 1;
            return;
        }
        self->alloc.CreateTypeA(buf, Fieldf43c);
        self->alloc.Reset();
        void* mem = self->alloc.Allocate(Field3fc);
        self->field20 = mem;
        if (mem == NULL) {
            func_020a0c0c();
            self->flag1 = 1;
            return;
        }
        PushInputLogA_020a1df8(3);
        func_ov003_0215c650(self->field20);
        func_ov003_0215c568(self->field20, &self->alloc);
        self->state += 1;
        return;
    }
    if (state == 1) {
        if (func_ov017_021959b4() != 0) {
            func_ov003_0215caa4(self->field20);
        }
        if (func_ov003_0215c924(self->field20, scale) != 0) {
            self->state += 1;
        }
        return;
    }
    if (state == 2) {
        func_ov003_0215c800(self->field20);
        self->state += 1;
        return;
    }
    if (state != 3) {
        return;
    }
    func_ov017_021bac8c((struct Obj021bac8c*)self);
    ClearBitsInField4_0203b4e8(ov, 0xc0);
    SetByteField0x253_020397c0(c);
    ClearFlagBits_020a28b0((unsigned char*)flagResult, 3);
    func_020a0c0c();
    self->flag1 = 1;
}
