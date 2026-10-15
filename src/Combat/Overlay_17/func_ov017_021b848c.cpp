#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj020397cc;
struct FlagWord020466f4;

struct Context021b848c {
    unsigned char pad0[0x8e49];
    unsigned char field_8e49;
};

struct Self021b848c {
    unsigned char pad0[0x1c];
    unsigned char info[2];
    unsigned short field_1e;
    unsigned char pad20[4];
    unsigned short id;
    unsigned char pad26[2];
    int field_28;
    unsigned char pad2c[0x46 - 0x2c];
    unsigned char member;
    unsigned char pad47;
    int field_48;
    unsigned char pad4c[0x51 - 0x4c];
    unsigned char field_51;
    unsigned char pad52[0x6b0 - 0x52];
    Context021b848c* context;
    unsigned short state;
    unsigned char pad6b6[2];
    int field_6b8;
    unsigned char pad6bc[0x6c6 - 0x6bc];
    unsigned char field_6c6;
};

int GetGlobalField0x1c020421a0();
int GetField0x3acValue_020100a8(GameState* battleStruct);
extern "C" void func_ov017_021c9c64(unsigned short a0, unsigned char a1);
void EnqueueEventTag122_021c8b78(unsigned short param);
void* GetDataPtr02114e04_020d6c00(void);
void ClearFlags020466f4(FlagWord020466f4* word, unsigned int mask);
void OrBitsIntoField0_020466e4(unsigned int* obj, unsigned int mask);
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
void SetBitInField0x34_020a35cc(unsigned char* obj, unsigned char index);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void func_020c9be0(void);
void EnqueueEventTag127ForParty_021c3f70(unsigned short tag);

// USA: func_ov017_021b848c
extern "C" ARM void func_ov017_021b848c(Self021b848c* self, signed char* present, int member, int arg3,
                                         unsigned short arg4, signed char arg5, int arg6, int arg7) {
    GameState* battle = GameState::GetInstance();
    GetGlobalField0x1c020421a0();
    unsigned short state = self->state;
    if (state == 4 || state == 6 || state == 0) return;
    if (present[GetField0x3acValue_020100a8(battle)] == 0) return;

    int valid = member >= 0 && member <= 3;
    if (!valid || present[member] == 0 || battle->GetGameObjectByIndex(member) == NULL) {
        func_ov017_021c9c64(self->id, 0);
        EnqueueEventTag122_021c8b78(self->id);
        self->state = 5;
        return;
    }

    void* flags = GetDataPtr02114e04_020d6c00();
    ClearFlags020466f4((FlagWord020466f4*)flags, 0x200);
    OrBitsIntoField0_020466e4((unsigned int*)flags, 0x40000);
    GameObject* actor = battle->GetUnknownGameObject();
    if (actor != NULL) {
        CancelPendingAction020397cc((struct Obj020397cc*)actor, 1);
        *(unsigned short*)((char*)actor + 0xb2) = 0;
    }
    if (present[0] != 0 && battle->GetGameObjectByIndex(0) != NULL) {
        SetBitInField0x34_020a35cc(self->info, 0);
    }
    if (present[1] != 0 && battle->GetGameObjectByIndex(1) != NULL) {
        SetBitInField0x34_020a35cc(self->info, 1);
    }
    if (present[2] != 0 && battle->GetGameObjectByIndex(2) != NULL) {
        SetBitInField0x34_020a35cc(self->info, 2);
    }
    if (present[3] != 0 && battle->GetGameObjectByIndex(3) != NULL) {
        SetBitInField0x34_020a35cc(self->info, 3);
    }
    self->member = member;
    if (TestBitAt0x34_020a35e0(self->info, self->member) == 0) func_020c9be0();
    if (arg3 == 0) GetField0x3acValue_020100a8(battle);
    self->field_48 = arg3;
    self->field_1e = arg4;
    if (arg7 >= 0) self->field_28 = arg7;
    if (arg5 > -1) {
        self->field_51 = arg5;
        if (self->context != NULL) self->context->field_8e49 = arg5;
    }
    EnqueueEventTag127ForParty_021c3f70(self->id);
    if (member != GetField0x3acValue_020100a8(battle)) {
        if (arg6 != 0) self->field_6c6 = 1;
        self->field_6b8 = 0;
        self->state = 4;
    } else {
        self->state = 6;
    }
}
