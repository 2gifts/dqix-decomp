#include <globaldefs.h>

class GameState {
public:
    static GameState* GetInstance();
};
struct Slots02083960;
unsigned char* GetCombatantWithFlag0x100(GameState*, int);
Slots02083960* GetFieldAt0x150(unsigned char*);
int CountPositiveSlots02083960(Slots02083960*);

// USA: func_02086d20
// JPN: func_02087640
ARM int SumSlotsWithFlag0x1000x150_02086d20(unsigned char* p) {
    short sum = 0;
    GameState* state = GameState::GetInstance();
    for (int i = 0; i < p[0xf7c]; i++) {
        unsigned char* combatant = GetCombatantWithFlag0x100(state, (p + i)[0xf78]);
        if (combatant != NULL) {
            Slots02083960* slots = GetFieldAt0x150(combatant);
            if (slots != NULL) sum += CountPositiveSlots02083960(slots);
        }
    }
    return sum;
}
