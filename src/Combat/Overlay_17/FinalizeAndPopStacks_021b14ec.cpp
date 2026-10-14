#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "GameState/GameState.h"

struct Obj020979c0;
void InitStructWithZeroId020979f4(struct Obj020979c0* p);
void PopStack0AndTrigger_020a1e54(int flag);
void PopStack1AndTrigger_020a1f4c(int flag);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
int GetFieldIfFlag4_020100f8(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);

extern int data_02114e20;
extern int data_ov017_021d83ec;

struct Obj021b14ec {
    char pad0[0x8];
    SafeAllocator allocator;
    struct Obj020979c0* field1c;
};

// USA: func_ov017_021b14ec  (semantic: FinalizeAndPopStacks_021b14ec)
extern "C" ARM void func_ov017_021b14ec(struct Obj021b14ec* self) {
    if (self->field1c != NULL) InitStructWithZeroId020979f4(self->field1c);
    data_ov017_021d83ec = 0;

    void* p = self->allocator.GetSignedAllocator();
    if (p) {
        self->allocator.Destroy();
        TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
    }

    PopStack0AndTrigger_020a1e54(1);
    PopStack1AndTrigger_020a1f4c(1);
    int field = GetFieldIfFlag4_020100f8((char*)GameState::GetInstance());
    if (field != 0) SetField0x23cTrue_020a27ac((void*)field);
}
