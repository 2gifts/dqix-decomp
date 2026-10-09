#include <globaldefs.h>
#include "GameState/GameState.h"

struct ResetHalfwordPair0208977c;
void ResetHalfwordPairAt0x2a(struct ResetHalfwordPair0208977c* p);

struct Combatant0215d588 {
    char pad0[0x138];
    struct ResetHalfwordPair0208977c* stats;
};

struct Slot0215d588 {
    char pad0[0xf];
    unsigned char active;
    char pad10[0x18 - 0x10];
};

struct Battle0215d588 {
    char pad0[0x81b0];
    struct Slot0215d588 slots[3];
};

struct IdList { short v[16]; };
extern IdList data_ov000_02182d14;

extern "C" void func_ov000_0215d090(struct Battle0215d588* self);
extern "C" int func_ov000_02153e40(void* obj, short* buf, int max, int start);

// USA: func_ov000_0215d588
extern "C" ARM void func_ov000_0215d588(struct Battle0215d588* self) {
    func_ov000_0215d090(self);
    for (int i = 0; i < 3; i++) {
        self->slots[i].active = 0;
    }
    IdList ids = data_ov000_02182d14;
    int count = func_ov000_02153e40(self, ids.v, 0x10, 0);
    for (int i = 0; i < count; i++) {
        int id = ids.v[i];
        GameState* gs = GameState::GetInstance();
        Combatant0215d588* c = (Combatant0215d588*)gs->GetCombatantByIndex(id);
        if (c != NULL) {
            ResetHalfwordPairAt0x2a(c->stats);
        }
    }
}
