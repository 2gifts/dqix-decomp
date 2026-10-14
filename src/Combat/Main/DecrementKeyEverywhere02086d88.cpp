#include <globaldefs.h>
#include "GameState/GameState.h"

struct KeyMap020a0a08;
int DecrementKeyValue020a0a08(struct KeyMap020a0a08* map, int key, int amount);

extern "C" int func_0207c894(void* map, int key, int amount);

int GetFieldAt0x150_02053c6c(unsigned char* obj);

struct Slots020838c4;
int RemoveSlotValueAndCompact020838c4(struct Slots020838c4* s, int value);

// USA: func_02086d88
ARM int DecrementKeyEverywhere02086d88(unsigned char* self, int key) {
    if (key < 0) {
        return 0;
    }
    if (DecrementKeyValue020a0a08((struct KeyMap020a0a08*)self, key, 1) != 0) {
        return 1;
    }
    if (func_0207c894(self + 0x1d4, key, 9) != 0) {
        return 1;
    }
    if (DecrementKeyValue020a0a08((struct KeyMap020a0a08*)(self + 0xe04), key, 1) != 0) {
        return 1;
    }
    GameState* battleStruct = GameState::GetInstance();
    GameObject* c;
    unsigned char i;
    for (i = 0; i < self[0xf7c]; i++) {
        unsigned char* p = self + i;
        c = GetCombatantWithFlag0x100_0200ff1c(battleStruct, p[0xf78]);
        if (c != 0) {
            int field = GetFieldAt0x150_02053c6c((unsigned char*)c);
            if (field != 0) {
                if (RemoveSlotValueAndCompact020838c4((struct Slots020838c4*)field, key) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
