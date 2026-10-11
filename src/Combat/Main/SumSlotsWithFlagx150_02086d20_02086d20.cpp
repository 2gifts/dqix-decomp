#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150(unsigned char* obj);

struct Slots02083960;
extern "C" int _Z26CountPositiveSlots02083960P13Slots02083960(struct Slots02083960* s);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02086d20
extern "C" ARM int _Z35SumSlotsWithFlag0x1000x150_02086d20Ph(unsigned char* self) {
    short total = 0;
    GameState* battleStruct = GameState::GetInstance();
    int i = 0;
    while (i < self[0xf7c]) {
        unsigned char* p = self + i;
        GameObject* c = GetCombatantWithFlag0x100(battleStruct, p[0xf78]);
        if (c != 0) {
            int field = GetFieldAt0x150((unsigned char*)c);
            if (field != 0) {
                total = total + _Z26CountPositiveSlots02083960P13Slots02083960((struct Slots02083960*)field);
            }
        }
        i++;
    }
    return total;
}
