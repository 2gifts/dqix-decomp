#include <globaldefs.h>

#if defined(jpn)
enum { CombatantSlotsOffset = 0x144 };
#else
enum { CombatantSlotsOffset = 0x150 };
#endif
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Element020ddb38 { unsigned int v[8]; };
struct ElementFlagsWord020ddb38 {
    unsigned int kind : 4;
    unsigned int : 27;
    unsigned int topFlag : 1;
};
struct Container020ddb38 {
    char pad[0x2c];
    short kind;
};
struct Slots0208386c { unsigned char pad[0x454]; short slots[8]; };
struct S_a0504;

int IsField8Bit19Set_020ddb20(unsigned int* obj);
void RemoveSlotShiftDown0208386c(struct Slots0208386c* s, int idx);
void* GetPointerField_02171b9c_02171b9c(void* obj, int idx);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
int LoadBattleBlock020ac4c0(void* dst);
void AddClamped7BitField_020a0504(struct S_a0504* p, unsigned int amount);
int CopyInBattleField0x7540_020ac494(void* src);
extern "C" void func_02083738(void* o, int a1);

// USA: func_020ddb38
extern "C" ARM int func_020ddb38(int n, int idx, struct Container020ddb38* container, struct Random* rng) {
    int inRange;
    GameObject* combatant;
    struct Element020ddb38* elem;
    char localBuf[0xb0];

    combatant = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), n);
    inRange = (n >= 0 && n <= 3);
    if (!inRange) return 0;
    if (combatant == 0) return 0;
    if (container == 0) return 0;
    if (container->kind != 0x4667) {
        if (idx < 0) goto fail;
        if (idx < 0x10) goto ok;
    fail:
        return 0;
    ok:
        elem = (struct Element020ddb38*)GetPointerField_02171b9c_02171b9c(container, idx);
    } else {
        elem = (struct Element020ddb38*)((char*)(*(struct Slots0208386c**)((char*)combatant + CombatantSlotsOffset)) + 0x2d4);
    }
    if (elem == 0) return 0;
    if (!IsField8Bit19Set_020ddb20(elem->v)) return 0;
    switch (((struct ElementFlagsWord020ddb38*)&elem->v[2])->kind) {
    case 8:
    case 9:
    case 0xa:
        RemoveSlotShiftDown0208386c(*(struct Slots0208386c**)((char*)combatant + CombatantSlotsOffset), (signed char)idx);
        break;
    default:
        if (*(short*)((char*)elem + 0x18) == 0x4667) {
            if (rng == 0) rng = GetBTRandom();
            if (NextRandomMax(rng, 100) < 0x19) {
                func_02083738((void*)(int)GetFieldAt0x150_02053c6c((unsigned char*)combatant), 7);
                return 2;
            }
        }
        return 0;
    }
    if (((struct ElementFlagsWord020ddb38*)&elem->v[2])->topFlag) {
        LoadBattleBlock020ac4c0(localBuf);
        AddClamped7BitField_020a0504((struct S_a0504*)localBuf, 1);
        CopyInBattleField0x7540_020ac494(localBuf);
    }
    return 1;
}
