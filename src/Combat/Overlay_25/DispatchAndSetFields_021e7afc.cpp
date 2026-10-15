#include <globaldefs.h>
#include "GameState/GameState.h"

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);

struct ShortPair0xba0xbc;
void SetFields0xbaAnd0xbc_02032fd0(ShortPair0xba0xbc*, short, unsigned short);

struct S021e7afc { char pad[8]; unsigned short field8; short fieldA; unsigned short fieldC; };

// USA: func_ov025_021e7afc  (semantic: DispatchAndSetFields_021e7afc)
extern "C" ARM int func_ov025_021e7afc(struct S021e7afc* obj, int b, int unused, int c) {
    GameState* battle = GameState::GetInstance();
    int ids[12];
    int count = DispatchByIndex021820bc((void*)c, b, obj->field8, (int)ids);
    int i;
    for (i = 0; i < count; i++) {
        GameObject* combatant = battle->GetMaybeWanderingMonsterByIndex(ids[i]);
        if (combatant) {
            SetFields0xbaAnd0xbc_02032fd0((struct ShortPair0xba0xbc*)combatant, obj->fieldA, obj->fieldC);
        }
    }
    return 1;
}
