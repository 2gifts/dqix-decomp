#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue31C_204 = 0x204 };
#else
enum { kRegionValue31C_204 = 0x31c };
#endif


int GetField0x3acValue(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void func_02032fdc(void* a, int b, int c);

struct Struct31c_021600b8 { char pad[kRegionValue31C_204]; int field31c; void* field320; };

// USA: func_ov003_021600b8  (semantic: SyncPositionAndFlags_021600b8)
// JPN: func_ov003_02160264
extern "C" ARM void func_ov003_021600b8(Struct31c_021600b8* obj) {
    GameState* battleStruct = GameState::GetInstance();
    if (obj->field31c == 0 || obj->field320 == 0) return;
    int val = GetField0x3acValue(battleStruct);
    GameObject* combatant = GetCombatantWithFlag0x100(battleStruct, val);
    if (combatant == 0) return;
    _ZN8Vector3iaSERKS_((int*)((char*)obj->field320 + 0x44), (int*)((char*)combatant + 0x44));
    *(int*)0x4000444 = 0;
    func_02032fdc(obj->field320, 0, 0);
    *(int*)0x4000448 = 1;
}
