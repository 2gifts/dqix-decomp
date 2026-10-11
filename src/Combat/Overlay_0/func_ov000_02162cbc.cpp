#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02049efc;

struct CombatantStatus02162cbc {
    char pad0[0x14];
    unsigned int flags;
    char pad18[0x22 - 0x18];
    unsigned short b1e : 2;
    unsigned short b1d : 4;

    unsigned int GetFlags() { unsigned int f = flags; return f; }
    unsigned char GetB1d() { unsigned char v = b1d; return v; }
    unsigned char GetB1e() { unsigned char v = b1e; return v; }
};

struct Combatant02162cbc {
    char pad0[0xc1];
    unsigned char fieldC1;
    char padC2[0x138 - 0xc2];
    CombatantStatus02162cbc* status;
};

struct Battle02162cbc {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    void* field29c;
};

extern "C" int func_ov000_02153e40(void* obj, short* buf, int max, int start);
extern "C" void _Z30ClearSubFlag56IfActive02049efcP11Obj02049efc(struct Obj02049efc* obj);
extern "C" void func_ov000_02162dc4(Battle02162cbc* self, GameObject* lead, Combatant02162cbc* actor, unsigned int flags,
                                    int b1d, int b1e, unsigned long long mask, int zero);

// USA: func_ov000_02162cbc
extern "C" ARM void func_ov000_02162cbc(Battle02162cbc* self) {
    GameState* bs = GameState::GetInstance();
    short ids[12];
    int count = func_ov000_02153e40(self->field29c, ids, 0xc, 0);
    for (int i = 0; i < count; i++) {
        Combatant02162cbc* c = (Combatant02162cbc*)bs->GetCombatantByIndex(ids[i]);
        if (!c) continue;
        _Z30ClearSubFlag56IfActive02049efcP11Obj02049efc((struct Obj02049efc*)c);
        if (c->status->flags & 1) continue;
        c->fieldC1 &= ~0xf0;
        CombatantStatus02162cbc* st = c->status;
        func_ov000_02162dc4(self, NULL, c, st->GetFlags(), st->GetB1d(), st->GetB1e(), 0, 0);
    }
}
