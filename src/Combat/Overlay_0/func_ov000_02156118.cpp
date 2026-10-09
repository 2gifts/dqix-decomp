#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container02070e60;

struct MonsterEntry {
    char unk_0[0x10];
    unsigned int unk_10_0 : 16;
    unsigned int rank : 3;
};

struct BattleContext {
    char unk_0[0x8e18];
    char* data;
};

int ClassifyField0x81fe(char* base);
GameObject* GetCombatantWithFlag0x100(GameState* gameState, int combatantId);
GameObject* GetCombatantChecked(GameState* gameState, int combatantId);
unsigned char* GetFieldAt0x150(unsigned char* obj);
extern "C" float _Z23AccumulateCharm02084ee8Pv(void* actor);
extern "C" int _Z26AccumulateSlotBits02085b88Ph(unsigned char* actor);
extern "C" MonsterEntry* _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(Container02070e60* container, int key);
extern "C" float _Z27GetTableEntryOrZero02074988i(int i);
int IsFlag0x18Bit0x1Set(GameObject* combatant);

// USA: func_ov000_02156118
extern "C" ARM float func_ov000_02156118(BattleContext* ctx, int combatantId) {
    if (ClassifyField0x81fe((char*)ctx) != 0) {
        return 0;
    }
    GameState* gs = GameState::GetInstance();
    GameObject* combatant = GameState::GetInstance()->GetCombatantByIndex(combatantId);
    if (combatant == 0) {
        return 0;
    }
    float value;
    int isParty = (combatantId >= 0 && combatantId <= 3) ? 1 : 0;
    if (isParty) {
        GameObject* member = GetCombatantWithFlag0x100(gs, combatantId);
        if (member == 0) {
            return 0;
        }
        unsigned char* actor = GetFieldAt0x150((unsigned char*)member);
        if (actor == 0) {
            return 0;
        }
        if (*(short*)(actor + 0x2cc) <= 0) {
            return 0;
        }
        float sum = 0.0f;
        float charm = _Z23AccumulateCharm02084ee8Pv(actor);
        int slots = _Z26AccumulateSlotBits02085b88Ph(actor);
        value = slots + (sum + charm);
    } else {
        GameObject* monster = GetCombatantChecked(gs, combatantId);
        if (monster == 0) {
            return 0;
        }
        MonsterEntry* entry = _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i((Container02070e60*)(ctx->data + 0x684), *(short*)((char*)monster + 2));
        signed char rank = entry->rank;
        value = _Z27GetTableEntryOrZero02074988i(rank);
    }
    if (IsFlag0x18Bit0x1Set(combatant) != 0) {
        value = 2.0f * value;
    }
    return value;
}
