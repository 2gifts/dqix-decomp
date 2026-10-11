#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct S_10088;
int IsFlag10088Set(struct S_10088* obj);
extern "C" int _Z30HasFlaggedSlotBit20Set020854e8Ph(unsigned char* actor);
extern "C" short _Z20ApplyMPDelta0215a1d4PviiPs(void* unused, int id, int delta, short* outApplied);
extern "C" void func_ov000_0215acb8(void* world, int id, int applied, int result);

struct Cost_021e556c {
    unsigned int cost : 8;
    unsigned int pair : 2;
    unsigned int rest : 22;
};

struct Kind_021e556c {
    unsigned int gap : 5;
    unsigned int kind : 7;
    unsigned int sub : 4;
    unsigned int rest : 16;
};

struct Rec_021e556c {
    char pad0[8];
    struct Cost_021e556c f8;
    char padC[4];
    unsigned int f10;
    char pad14[4];
    struct Kind_021e556c f18;
};

struct Act_021e556c {
    char pad0[0x10];
    void* world;
    char pad14[0x75 - 0x14];
    unsigned char f75;
};

struct Fighter_021e556c {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    unsigned char* f150;
};

// JPN: func_ov024_021e5e04
// USA: func_ov024_021e556c
extern "C" ARM void func_ov024_021e556c(struct Act_021e556c* obj, int sourceId, int targetId, struct Rec_021e556c* rec, int damage) {
    GameState* gs = GameState::GetInstance();
    if (GetCombatantByID((int)obj->world, targetId) == 0) return;
    if (!(rec->f10 & 1)) return;
    if (rec->f8.pair != 1) return;
    int valid = (targetId >= 0 && targetId <= 3) ? 1 : 0;
    if (!valid) return;
    int sourceValid = (sourceId >= 0 && sourceId <= 3) ? 1 : 0;
    if (sourceValid) return;
    if (rec->f8.cost == 0) return;
    if (rec->f18.kind == 1) {
        if (damage <= 0) return;
    }
    if (rec->f18.sub != 2) return;
    if (obj->f75 == 0) return;
    struct Fighter_021e556c* target = (struct Fighter_021e556c*)GetCombatantWithFlag0x100(gs, targetId);
    if (target == 0) return;
    if (IsFlag10088Set((struct S_10088*)target)) return;
    if (!_Z30HasFlaggedSlotBit20Set020854e8Ph(target->f150)) return;
    short applied = 0;
    short result = _Z20ApplyMPDelta0215a1d4PviiPs(obj->world, targetId, rec->f8.cost, &applied);
    func_ov000_0215acb8(obj->world, targetId, applied, result);
}
