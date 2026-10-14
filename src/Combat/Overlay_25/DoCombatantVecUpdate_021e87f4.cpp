#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vector3i;
int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
struct Obj02033874;
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);

struct In021e87f4 {
    char pad[8];
    unsigned char idx;
    char pad2[3];
    int val;
};

struct Inner021e87f4 {
    unsigned int v[3];
};

struct CombatantVec021e87f4 {
    char pad[0x50];
    struct Inner021e87f4 mid;
};

struct Local021e87f4 {
    struct Inner021e87f4 mid;
    int id;
    char pad[0x1c];
};

// USA: func_ov025_021e87f4
ARM int DoCombatantVecUpdate_021e87f4(struct In021e87f4* a, int b, int unused, void* c) {
    GameState* bs = GameState::GetInstance();
    struct Local021e87f4 local;
    if (!DispatchByIndex021820bc(c, b, a->idx, (int)&local.id)) {
        return 1;
    }
    GameObject* combatant = bs->GetMaybeWanderingMonsterByIndex(local.id);
    if (combatant) {
        SetVecYFromValue02033874((struct Obj02033874*)combatant, a->val);
    } else {
        combatant = bs->GetGameObjectByIndex(local.id);
        if (!combatant) {
            return 1;
        }
        struct CombatantVec021e87f4* cv = (struct CombatantVec021e87f4*)combatant;
        local.mid = cv->mid;
        local.mid.v[1] = a->val;
        *(Vector3i*)((int*)&cv->mid) = *(Vector3i const*)((int*)&local.mid);
    }
    return 1;
}
