#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04_02010828(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
struct KeyMap020a095c;
int AddKeyValueClamped020a095c(struct KeyMap020a095c* map, int key, int amount);

// USA: func_ov017_021b6bb8
ARM void AddPositiveField150EntriesToMap_021b6bb8(int combatantId) {
    GameState* bs = GameState::GetInstance();
    void* keymap = GetPtrField0x2a04_02010828(bs);
    GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, combatantId);
    if (c == NULL) {
        return;
    }

    char* base = (char*)GetFieldAt0x150_02053c6c((unsigned char*)c);
    unsigned char i = 0;
    while (i < 8) {
        char* p = base + i * 2 + 0x400;
        short v = *(short*)(p + 0x54);
        if (v > 0) {
            AddKeyValueClamped020a095c((struct KeyMap020a095c*)keymap, v, 1);
        }
        i = (i + 1) & 0xff;
    }
}
