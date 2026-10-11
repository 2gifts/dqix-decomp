#include <globaldefs.h>
#if defined(jpn)
enum { kRegion400 = 0x200 };
enum { kRegion82 = 0xaa };
#else
enum { kRegion400 = 0x400 };
enum { kRegion82 = 0x82 };
#endif
#include "GameState/GameState.h"

void AddPositiveField150EntriesToMap_021b6bb8(int combatantId);
int GetSignedField6Bit_021b6c2c(int a, int d);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

// JPN: func_ov003_02166e20
// USA: func_ov003_02166f40  (semantic: CancelCombatantAction_02166f40)
extern "C" ARM void func_ov003_02166f40(char* obj) {
    AddPositiveField150EntriesToMap_021b6bb8(*(short*)(obj + kRegion400 + kRegion82));
    GetSignedField6Bit_021b6c2c(*(short*)(obj + kRegion400 + kRegion82), 0);
    GameObject* c = GameState::GetInstance()->GetProtagonist();
    if (c == NULL) return;
    CancelPendingAction020397cc((struct Obj020397cc*)c, 1);
}
