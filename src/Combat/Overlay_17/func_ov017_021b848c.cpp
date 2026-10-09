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

extern "C" int _Z26GetGlobalField0x1c020421a0v();
int GetField0x3acValue(GameState* battleStruct);
extern "C" void func_ov017_021c9c64(unsigned short a0, unsigned char a1);
extern "C" void _Z27EnqueueEventTag122_021c8b78t(unsigned short param);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(FlagWord020466f4* word, unsigned int mask);
void OrBitsIntoField0(unsigned int* obj, unsigned int mask);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(struct Obj020397cc* obj, int arg1);
void SetBitInField0x34(unsigned char* obj, int index);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
extern "C" void func_020c9be0(void);
extern "C" void _Z35EnqueueEventTag127ForParty_021c3f70t(unsigned short tag);

// USA: func_ov017_021b848c
extern "C" ARM void func_ov017_021b848c(Self021b848c* self, signed char* present, int member, int arg3,
                                         unsigned short arg4, signed char arg5, int arg6, int arg7) {
    GameState* battle = GameState::GetInstance();
    _Z26GetGlobalField0x1c020421a0v();
    unsigned short state = self->state;
    if (state == 4 || state == 6 || state == 0) return;
    if (present[GetField0x3acValue(battle)] == 0) return;

    int valid = member >= 0 && member <= 3;
    if (!valid || present[member] == 0 || battle->GetGameObjectByIndex(member) == NULL) {
        func_ov017_021c9c64(self->id, 0);
        _Z27EnqueueEventTag122_021c8b78t(self->id);
        self->state = 5;
        return;
    }

    void* flags = _Z27GetDataPtr02114e04_020d6c00v();
    _Z18ClearFlags020466f4P16FlagWord020466f4j((FlagWord020466f4*)flags, 0x200);
    OrBitsIntoField0((unsigned int*)flags, 0x40000);
    GameObject* actor = battle->GetUnknownGameObject();
    if (actor != NULL) {
        _Z27CancelPendingAction020397ccP11Obj020397cci((struct Obj020397cc*)actor, 1);
        *(unsigned short*)((char*)actor + 0xb2) = 0;
    }
    if (present[0] != 0 && battle->GetGameObjectByIndex(0) != NULL) {
        SetBitInField0x34(self->info, 0);
    }
    if (present[1] != 0 && battle->GetGameObjectByIndex(1) != NULL) {
        SetBitInField0x34(self->info, 1);
    }
    if (present[2] != 0 && battle->GetGameObjectByIndex(2) != NULL) {
        SetBitInField0x34(self->info, 2);
    }
    if (present[3] != 0 && battle->GetGameObjectByIndex(3) != NULL) {
        SetBitInField0x34(self->info, 3);
    }
    self->member = member;
    if (TestBitAt0x34(self->info, self->member) == 0) func_020c9be0();
    if (arg3 == 0) GetField0x3acValue(battle);
    self->field_48 = arg3;
    self->field_1e = arg4;
    if (arg7 >= 0) self->field_28 = arg7;
    if (arg5 > -1) {
        self->field_51 = arg5;
        if (self->context != NULL) self->context->field_8e49 = arg5;
    }
    _Z35EnqueueEventTag127ForParty_021c3f70t(self->id);
    if (member != GetField0x3acValue(battle)) {
        if (arg6 != 0) self->field_6c6 = 1;
        self->field_6b8 = 0;
        self->state = 4;
    } else {
        self->state = 6;
    }
}
