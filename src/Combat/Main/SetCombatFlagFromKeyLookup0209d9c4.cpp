#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04_02010828(GameState* battleStruct);
struct KeyMap020a0b3c;
signed char LookupValueByKey020a0b3c(struct KeyMap020a0b3c* map, int key);

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_0209d9c4
ARM int SetCombatFlagFromKeyLookup_0209d9c4(void* p) {
    GameState* battleStruct = GameState::GetInstance();
    void* result = GetPtrField0x2a04_02010828(battleStruct);
    int raw = func_ov017_021d60f4(p);
    struct KeyMap020a0b3c* map = (struct KeyMap020a0b3c*)((char*)result + 0x204 + 0xc00);
    signed char val = LookupValueByKey020a0b3c(map, (short)raw);
    func_ov017_021d6134((char*)p + 0x8, val);
    return 1;
}
