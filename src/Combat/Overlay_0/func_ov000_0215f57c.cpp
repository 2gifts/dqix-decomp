#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct ToggleBits3c_891b0 {
    unsigned char pad[0x3c];
    unsigned char bit0 : 1;
};

struct Inner0215f57c {
    char pad[0x10];
    unsigned int skip : 8;
    unsigned int slot : 3;
    unsigned int rest : 21;
};

struct Combatant0215f57c {
    char pad0[0x138];
    struct ToggleBits3c_891b0* field138;
    char pad1[0x148 - 0x13c];
    struct Inner0215f57c* field148;
};

struct ByteTable8_0215f57c {
    signed char v[8];
};

GameObject* GetCombatantWithFlag0x400(GameState* battleStruct, int combatantId);
void ToggleBit0AtByte0x3c(struct ToggleBits3c_891b0* obj);

extern struct ByteTable8_0215f57c data_ov000_02182a6c;

static inline int InRange(int i) { return i >= 0 && i <= 3; }

// USA: func_ov000_0215f57c
extern "C" ARM int func_ov000_0215f57c(struct Random* rng, int id) {
    if (InRange(id)) {
        return 0;
    }
    struct Combatant0215f57c* c = (struct Combatant0215f57c*)GetCombatantWithFlag0x400(GameState::GetInstance(), id);
    struct Inner0215f57c* inner = c->field148;
    int flag = c->field138->bit0 ? 1 : 0;
    int r = NextRandomMax(rng, 2);
    struct ByteTable8_0215f57c t = data_ov000_02182a6c;
    t.v[1] = r != 0;
    t.v[4] = flag != 0 ? 1 : 0;
    t.v[5] = flag == 0 ? 0 : 2;
    t.v[6] = flag != 0 ? 0 : 1;
    t.v[7] = flag == 0 ? 2 : 0;
    int result = t.v[inner->slot];
    ToggleBit0AtByte0x3c(c->field138);
    return result;
}
