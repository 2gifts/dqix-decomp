#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj0205a148;
void Dispatch0205a148(struct Obj0205a148* obj);

struct Elem020d7638 {
    unsigned char pad0[0xd0];
    int field_d0;
    unsigned char pad1[4];
};

struct Field41_020d7638 {
    unsigned char pad0[0x41];
    unsigned char lo5 : 5;
    unsigned char bit5 : 1;
    unsigned char hi2 : 2;
};

// USA: func_020d7638
ARM void DispatchReadyCombatantSlots(struct Elem020d7638* obj) {
    GameState* bs = GameState::GetInstance();
    int i;
    for (i = 0; i < 0xc; i++) {
        GameObject* combatant;
        int id;
        if (obj[i].field_d0 < 0) continue;
        id = i;
        if (i > 3) id = i + 0xbc;
        combatant = bs->GetGameObjectByIndex(id);
        if (!combatant) continue;
        if (!((Object3D*)((unsigned char*)combatant))->IsVisible()) continue;
        if (!((struct Field41_020d7638*)combatant)->bit5) continue;
        Dispatch0205a148((struct Obj0205a148*)&obj[i]);
    }
}
