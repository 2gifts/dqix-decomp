#include <globaldefs.h>
#if defined(jpn)
enum { kRegion32c = 0x328 };
enum { kRegion1f7 = 0x1f3 };
enum { kRegion280 = 0x27c };
#else
enum { kRegion32c = 0x32c };
enum { kRegion1f7 = 0x1f7 };
enum { kRegion280 = 0x280 };
#endif

#include "GameState/GameState.h"

struct Target02059f38;
struct Vec3_02059f38;
void CopyVec3ToField0x44(struct Target02059f38* dst, struct Vec3_02059f38* src);
extern "C" void _ZN8Object3D14AdvanceEffectsEv(void* obj);
extern "C" void _ZN8Object3D4DrawEb(void* p, int flag);

// JPN: func_ov003_02156668
// USA: func_ov003_02154f80  (semantic: UpdateVecFromCombatant_02154f80)
extern "C" ARM void func_ov003_02154f80(char* obj) {
    if (*(int*)(obj + kRegion32c) == 0) return;
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(*(signed char*)(obj + kRegion1f7));
    if (combatant != 0) {
        CopyVec3ToField0x44((struct Target02059f38*)(obj + kRegion280), (struct Vec3_02059f38*)((char*)combatant + 0x44));
    }
    _ZN8Object3D14AdvanceEffectsEv(obj + kRegion280);
    _ZN8Object3D4DrawEb(obj + kRegion280, 1);
}
