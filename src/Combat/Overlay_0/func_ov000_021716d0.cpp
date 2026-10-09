#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;
struct Obj0203c108;

struct SpellData_021716d0 {
    char pad0[4];
    unsigned int id : 12;
    unsigned int rest4 : 20;
    unsigned int mpCost : 8;
    unsigned int rest8 : 24;
    char padC[0x2c - 0xc];
    unsigned int pad2c : 10;
    unsigned int kind : 4;
    unsigned int rest2c : 18;
    char pad30[2];
    short goldCost;
};

struct MenuState_021716d0 {
    char pad0[6];
    short mp;
    signed char stack[8];
    signed char depth;
    char pad11[0x15 - 0x11];
    unsigned char field15;
    short selected;
    char pad18[0x1e - 0x18];
    unsigned short actionId;
};

struct PartyInfo_021716d0 {
    char pad0[0xf6c];
    int gold;
};

struct MenuEntry_021716d0 {
    char pad0[4];
    struct Container020e0310* strings;
    MenuState_021716d0 state;
    char pad28[0x4c - 0x28];
    int memberIndex;
    char message[0x1a4 - 0x50];
    SpellData_021716d0* spells[1];
};

extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" void _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(struct Obj0203c108* obj, char* text);
int IsFlag0x18Bit0x200Set(GameObject* obj);
int AdjustValueByFieldFlag(void* obj, unsigned int value);
extern "C" int func_ov000_02171210(void* a, void* b);
extern "C" int* func_ov000_02170cf8(void* obj, int id);
extern "C" void __clear(void* dst, int size);
extern "C" void func_020e4864(int a, char* b, int c, int d, int e, int f);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char* src, char* dst, int flag);

// USA: func_ov000_021716d0
extern "C" ARM void func_ov000_021716d0(MenuEntry_021716d0* self) {
    MenuState_021716d0* state = &self->state;
    int sel = state->selected;
    if (self->spells[sel] == NULL) {
        state->depth++;
        state->stack[self->state.depth] = 0xe;
        state->field15 = 0;
        _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc((struct Obj0203c108*)self->message, (char*)_Z21GetFieldByKey020e0434P17Container020e0310i(self->strings, 5));
        return;
    }

    GameState* gs = GameState::GetInstance();
    GameObject* actor = GetCombatantWithFlag0x100(gs, self->memberIndex);
    int cost = self->spells[sel]->mpCost;
    int have = self->state.mp;
    if (actor != NULL && IsFlag0x18Bit0x200Set(actor)) {
        cost = 0;
    } else if (self->spells[sel]->mpCost >= 0xff) {
        cost = 1;
    } else {
        cost = AdjustValueByFieldFlag(actor, cost);
    }
    if (self->spells[sel]->kind == 6) {
        PartyInfo_021716d0* party = (PartyInfo_021716d0*)GetPtrField0x2a04(gs);
        have = party->gold;
        cost = self->spells[sel]->goldCost;
    }
    if (have < cost) {
        state->depth++;
        state->stack[self->state.depth] = 0x1a;
        return;
    }

    state->actionId = self->spells[sel]->id;
    state->depth++;
    state->stack[state->depth] = func_ov000_02171210(self->spells[sel], self);
    int* entry = func_ov000_02170cf8(self, state->actionId);
    if (entry == NULL) return;

    char text[0x80];
    __clear(text, 0x80);
    char upper[0x80];
    __clear(upper, 0x80);
    func_020e4864(*entry, text, 1, 0, 0, 0);
    _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(text, upper, 0);
    _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc((struct Obj0203c108*)self->message, upper);
}
