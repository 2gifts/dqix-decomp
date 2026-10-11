#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantByID(int unused, int id);

struct FlagObj_021e47dc;
int IsFlagBit22Set_021e47dc(struct FlagObj_021e47dc* obj);

extern short data_ov024_021fe6e0[];

struct Wrapper_021ea78c {
    char unk[0x10];
    int field0x10;
};

struct Obj3_021ea78c {
    char unk0[0x4];
    int field4;
};

// USA: func_ov024_021ea78c
ARM int CheckCombatantInTable_021ea78c(struct Wrapper_021ea78c* a, int id, struct Obj3_021ea78c* c) {
    GameObject* combatant = GetCombatantByID(a->field0x10, id);
    if (!combatant) return 0;
    if (!IsFlagBit22Set_021e47dc((struct FlagObj_021e47dc*)combatant)) return 0;
    int idx = 0;
    short v;
    goto test;
body:
    if (v == (int)((unsigned int)(c->field4 << 20) >> 20)) return 1;
    idx++;
test:
    v = data_ov024_021fe6e0[idx];
    if (v != -1) goto body;
    return 0;
}
