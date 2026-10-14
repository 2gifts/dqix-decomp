#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "GameState/GameState.h"

extern "C" void func_02094ab0(void);
int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(void* self);
int GetGlobal02109400_02094a00(void);
void SetByteField0x253_020397c0(void* obj);
int GetFieldIfFlag4_020100f8(char* obj);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern "C" void func_020a0c0c(void);

extern int data_02114e20;

struct Obj021ac32c {
    char pad0[0xc];
    int field0xc;
    SafeAllocator allocator;
};

// USA: func_ov017_021ac32c
extern "C" ARM void func_ov017_021ac32c(struct Obj021ac32c* self) {
    void* ctrl = (void*)GetGlobalField0x1c020421a0();
    ReinitController02043204((char*)ctrl);
    func_02043124(ctrl);
    GetGlobal02109400_02094a00();
    func_02094ab0();
    GameState* battle = GameState::GetInstance();
    SetByteField0x253_020397c0(battle->GetUnknownGameObject());

    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
        func_020a0c0c();
    }
    self->field0xc = 0;
    int flag = GetFieldIfFlag4_020100f8((char*)battle);
    if (flag == 0) return;
    ClearFlagBits_020a28b0((unsigned char*)flag, 3);
}
