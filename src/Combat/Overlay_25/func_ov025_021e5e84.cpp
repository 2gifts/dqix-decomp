#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int _Z23DispatchByIndex021820bcPviii(void* obj, int unused, int index, int arg);
struct Obj02046574;
extern "C" struct Obj02046574* _Z26GetGlobalField0x1c020421a0v(void);
void* GetActiveCombatWork(void);
GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
GameObject* GetCombatantWithFlag0x400(GameState* battleStruct, int combatantId);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(struct Obj02046574* obj, int index, char* str);

struct Param021e5e84 {
    char pad0[8];
    unsigned char nameIndex;
    unsigned char targetIndex;
};

// USA: func_ov025_021e5e84
extern "C" ARM int func_ov025_021e5e84(struct Param021e5e84* p, int b, int unused, void* obj) {
    int ids[8];
    if (_Z23DispatchByIndex021820bcPviii(obj, b, p->targetIndex, (int)&ids[0]) != 1) {
        return 1;
    }

    GameState* bs = GameState::GetInstance();
    struct Obj02046574* names = _Z26GetGlobalField0x1c020421a0v();
    int id = ids[0];
    GetActiveCombatWork();
    bs->GetCombatantByIndex(id);

    int isPartyMember = (id >= 0 && id <= 3) ? 1 : 0;
    if (isPartyMember) {
        GameObject* c = GetCombatantWithFlag0x100(bs, id);
        if (c != NULL) {
            _Z22SetIndexedName02046574P11Obj02046574iPc(names, p->nameIndex, (char*)c->baseStats_);
        }
    } else {
        GameObject* c = GetCombatantWithFlag0x400(bs, id);
        if (c != NULL) {
            _Z22SetIndexedName02046574P11Obj02046574iPc(names, p->nameIndex, (char*)c + 0x14c);
        }
    }
    return 1;
}
