#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150_02053c6c(unsigned char* obj);
int TestBitInArray0x8ec_02083b00(unsigned char* obj, int index);

struct Sub130_02048350 {
    char pad[0x6];
    unsigned short count;
};

struct Obj02048350 {
    char pad0[0x4];
    short combatantId;
    char pad1[0x130 - 0x6];
    struct Sub130_02048350* sub;
};

// USA: func_02048350
ARM int ConsumeCounter02048350(struct Obj02048350* obj, int amount) {
    struct Sub130_02048350* sub = obj->sub;
    unsigned short count = sub->count;
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(bs, obj->combatantId);
    if (combatant != NULL && amount > 0) {
        unsigned char* ptr = (unsigned char*)GetFieldAt0x150_02053c6c((unsigned char*)combatant);
        if (ptr != NULL && TestBitInArray0x8ec_02083b00(ptr, 0x106)) {
            amount = (int)(0.75f + 0.75f * (float)amount);
            if (amount <= 0) {
                amount = 0;
            }
        }
    }
    if (count <= amount) {
        obj->sub->count = 0;
        return count;
    }
    obj->sub->count = count - amount;
    return amount;
}
