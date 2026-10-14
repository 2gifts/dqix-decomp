#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantChecked_0200ff94(GameState*, int);

struct Entry021710ac {
    char pad0[0x8];
    unsigned short field8;
    unsigned short fieldA;
    unsigned short fieldC;
    unsigned short fieldE;
    char pad10[0x24 - 0x10];
    unsigned char field24;
    char pad25[0x4c - 0x25];
    int field4c;
};

// USA: func_ov000_021710ac  (semantic: SetCombatantIdAndSyncStats_021710ac)
extern "C" ARM void func_ov000_021710ac(struct Entry021710ac* obj, int combatantId, int flag) {
    obj->field4c = combatantId;
    obj->field24 = flag ? (obj->field24 | 0x2) : (obj->field24 & ~0x2);
    int ok = (combatantId >= 0) && (combatantId <= 3);
    if (!ok) {
        return;
    }
    GameObject* c = GetCombatantChecked_0200ff94(GameState::GetInstance(), combatantId);
    if (c == 0) {
        return;
    }
    obj->field8 = c->baseStats_->primaryStats.maxHP;
    obj->fieldA = c->baseStats_->primaryStats.maxMP;
    obj->fieldC = *(unsigned short*)(*(char**)((char*)c + 0x130) + 4);
    obj->fieldE = *(unsigned short*)(*(char**)((char*)c + 0x130) + 6);
}
