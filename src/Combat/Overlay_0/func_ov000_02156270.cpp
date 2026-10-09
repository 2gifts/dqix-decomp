#include <globaldefs.h>
#include "GameState/GameState.h"

int ClassifyField0x81fe(char* base);
int GetFieldAt0x150(unsigned char* obj);
extern "C" float _Z30AccumulateMagicalMight02084f58Pv(void* actor);
extern "C" int _Z26AccumulateSlotBits02085c08Ph(unsigned char* actor);
int TestBitInArray0x8ec(unsigned char* obj, int index);
extern "C" float func_ov000_02155a04(GameObject* combatant);
GameObject* GetCombatantChecked(GameState* battleStruct, int combatantId);
int IsFlag0x14Bit0x2000000Set(GameObject* combatant);
int IsFlag0x18Bit0x400Set(GameObject* combatant);

struct Element02070e60 {
    char pad0[0x10];
    unsigned int key : 13;
    unsigned int rank : 3;
};
struct Container02070e60;
extern "C" struct Element02070e60* _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(struct Container02070e60* container, int key);
extern "C" float _Z27GetTableEntryOrZero02074988i(int i);

struct Battle02156270 {
    char pad0[0x8e18];
    char* field8e18;
};

// USA: func_ov000_02156270
extern "C" ARM float func_ov000_02156270(struct Battle02156270* battle, int combatantId) {
    float rate;
    if (ClassifyField0x81fe((char*)battle) != 0) {
        return 0.0f;
    }
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = GameState::GetInstance()->GetCombatantByIndex(combatantId);
    if (combatant == NULL) {
        return 0.0f;
    }
    int isParty = (combatantId >= 0 && combatantId <= 3) ? 1 : 0;
    if (isParty) {
        GameObject* member = GetCombatantWithFlag0x100(bs, combatantId);
        if (member == NULL) {
            return 0.0f;
        }
        unsigned char* actor = (unsigned char*)GetFieldAt0x150((unsigned char*)member);
        if (actor == NULL) {
            return 0.0f;
        }
        float scale = 2.0f;
        float might = _Z30AccumulateMagicalMight02084f58Pv(actor);
        float slots = _Z26AccumulateSlotBits02085c08Ph(actor);
        rate = slots + (scale + might);
        if (TestBitInArray0x8ec(actor, 0xa6) && func_ov000_02155a04(combatant) < 0.08f) {
            rate = rate * scale;
        }
    } else {
        GameObject* monster = GetCombatantChecked(bs, combatantId);
        if (monster == NULL) {
            return 0.0f;
        }
        struct Element02070e60* e = _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(
            (struct Container02070e60*)(battle->field8e18 + 0x684), monster->obj3D_.unknown_2_);
        rate = _Z27GetTableEntryOrZero02074988i((signed char)e->rank);
    }
    if (IsFlag0x14Bit0x2000000Set(combatant)) {
        rate = 2.0f * rate;
    }
    if (IsFlag0x18Bit0x400Set(combatant)) {
        return 50.0f;
    }
    return rate;
}
