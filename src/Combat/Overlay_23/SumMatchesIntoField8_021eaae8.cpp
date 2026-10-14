#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04_02010828(GameState* battleStruct);
extern "C" int func_ov017_021d60f4(void* obj);

struct Obj02086aec;
short SumCombatantKeyMatches02086aec(struct Obj02086aec* obj, int key);
extern "C" void func_ov017_021d6134(void* obj, int v);

// USA: func_ov023_021eaae8
ARM int SumMatchesIntoField8_021eaae8(void* obj) {
    struct Obj02086aec* p = (struct Obj02086aec*)GetPtrField0x2a04_02010828(GameState::GetInstance());
    short key = (short)func_ov017_021d60f4(obj);
    int v = SumCombatantKeyMatches02086aec(p, key);
    func_ov017_021d6134((char*)obj + 8, v);
    return 1;
}
