#include <globaldefs.h>
#include "GameState/GameState.h"

struct S886b0;
struct S886f8;
struct Obj02088740;
struct Obj02088788;
struct Obj020887d0;

struct CombatantResistances {
    char pad0[0x3e];
    unsigned char resist[21];
};

int IsFlag0x18Bit0x8Set(GameObject* combatant);
int IsFlag0x18Bit0x10Set(GameObject* combatant);
int CheckFlag0x80AndKind1(struct S886b0* obj);
int CheckFlag0x80AndKind2(struct S886f8* obj);
int IsFlag0x80SetAndStateEquals3(struct Obj02088740* obj);
int IsFlag0x80SetAndStateEquals4(struct Obj02088788* obj);
int IsFlag0x80SetAndStateEquals5(struct Obj020887d0* obj);

static inline unsigned char* GetResists(ModifiableCombatStats* stats) {
    return ((struct CombatantResistances*)stats)->resist;
}

// USA: func_ov000_02156b38
extern "C" ARM float func_ov000_02156b38(void* self, int combatantIndex, int element) {
    float ward1, ward2, ward3, ward4, ward5;
    float bonus;
    GameObject* combatant = GameState::GetInstance()->GetCombatantByIndex(combatantIndex);
    if (combatant == NULL) {
        return 1.0f;
    }

    bonus = 0.0f;
    if (IsFlag0x18Bit0x8Set(combatant)) {
        bonus = -25.0f;
    } else if (IsFlag0x18Bit0x10Set(combatant)) {
        bonus = 25.0f;
    }

    ward1 = 0.0f;
    if (CheckFlag0x80AndKind1((struct S886b0*)combatant->currentStats_)) {
        ward1 = -50.0f;
    }
    ward2 = 0.0f;
    if (CheckFlag0x80AndKind2((struct S886f8*)combatant->currentStats_)) {
        ward2 = -50.0f;
    }
    ward3 = 0.0f;
    if (IsFlag0x80SetAndStateEquals3((struct Obj02088740*)combatant->currentStats_)) {
        ward3 = -50.0f;
    }
    ward4 = 0.0f;
    if (IsFlag0x80SetAndStateEquals4((struct Obj02088788*)combatant->currentStats_)) {
        ward4 = -50.0f;
    }
    ward5 = 0.0f;
    if (IsFlag0x80SetAndStateEquals5((struct Obj020887d0*)combatant->currentStats_)) {
        ward5 = -50.0f;
    }

    unsigned char idx = element - 1;
    if (element < 1 || element > 21) {
        return 1.0f;
    }
    if (element == 8) {
        bonus = 0.0f;
    } else if (element >= 1 && element <= 7) {
        float wards[7] = {ward1, ward2, ward3, ward3, ward4, ward4, ward5};
        bonus = wards[idx];
    }

    float value = GetResists(combatant->currentStats_)[idx];
    value += bonus;
    if (value < 0.0f) {
        value = 0.0f;
    }
    return value / 100.0f;
}
