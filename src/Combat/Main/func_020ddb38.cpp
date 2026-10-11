#include <globaldefs.h>
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

int IsField8Bit19Set(unsigned int* obj);
extern "C" void _Z27RemoveSlotShiftDown0208386cP13Slots0208386ci(struct Slots0208386c* s, int idx);
extern "C" void* _Z33GetPointerField_02171b9c_02171b9cPvi(void* obj, int idx);
int GetFieldAt0x150(unsigned char* obj);
extern "C" int _Z23LoadBattleBlock020ac4c0Pv(void* dst);
void AddClamped7BitField(struct S_a0504* p, unsigned int amount);
int CopyInBattleField0x7540(void* src);
extern "C" void func_02083738(void* o, int a1);

// USA: func_020ddb38
extern "C" ARM int func_020ddb38(int n, int idx, struct Container020ddb38* container, struct Random* rng) {
    int inRange;
    GameObject* combatant;
    struct Element020ddb38* elem;
    char localBuf[0xb0];

    combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), n);
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
        elem = (struct Element020ddb38*)_Z33GetPointerField_02171b9c_02171b9cPvi(container, idx);
    } else {
        elem = (struct Element020ddb38*)((char*)(*(struct Slots0208386c**)((char*)combatant + 0x150)) + 0x2d4);
    }
    if (elem == 0) return 0;
    if (!IsField8Bit19Set(elem->v)) return 0;
    switch (((struct ElementFlagsWord020ddb38*)&elem->v[2])->kind) {
    case 8:
    case 9:
    case 0xa:
        _Z27RemoveSlotShiftDown0208386cP13Slots0208386ci(*(struct Slots0208386c**)((char*)combatant + 0x150), (signed char)idx);
        break;
    default:
        if (*(short*)((char*)elem + 0x18) == 0x4667) {
            if (rng == 0) rng = GetBTRandom();
            if (NextRandomMax(rng, 100) < 0x19) {
                func_02083738((void*)(int)GetFieldAt0x150((unsigned char*)combatant), 7);
                return 2;
            }
        }
        return 0;
    }
    if (((struct ElementFlagsWord020ddb38*)&elem->v[2])->topFlag) {
        _Z23LoadBattleBlock020ac4c0Pv(localBuf);
        AddClamped7BitField((struct S_a0504*)localBuf, 1);
        CopyInBattleField0x7540(localBuf);
    }
    return 1;
}
