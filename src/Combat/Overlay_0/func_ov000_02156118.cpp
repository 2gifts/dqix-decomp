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
float AccumulateCharm02084ee8(void* actor);
int AccumulateSlotBits02085b88(unsigned char* actor);
MonsterEntry* SearchWithLow15Comparator02070fd0(Container02070e60* container, int key);
float GetTableEntryOrZero02074988(int i);
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
        float charm = AccumulateCharm02084ee8(actor);
        int slots = AccumulateSlotBits02085b88(actor);
        value = slots + (sum + charm);
    } else {
        GameObject* monster = GetCombatantChecked(gs, combatantId);
        if (monster == 0) {
            return 0;
        }
        MonsterEntry* entry = SearchWithLow15Comparator02070fd0((Container02070e60*)(ctx->data + 0x684), *(short*)((char*)monster + 2));
        signed char rank = entry->rank;
        value = GetTableEntryOrZero02074988(rank);
    }
    if (IsFlag0x18Bit0x1Set(combatant) != 0) {
        value = 2.0f * value;
    }
    return value;
}
