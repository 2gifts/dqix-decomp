#include <globaldefs.h>
#if defined(jpn)
enum { kSlotsPointerOffset = 0x144 };
#else
enum { kSlotsPointerOffset = 0x150 };
#endif
#include "GameState/GameState.h"

struct Element020de650 { unsigned int v[8]; };
struct ElementFlagsWord020de650 {
    unsigned int kind : 4;
    unsigned int : 27;
    unsigned int topFlag : 1;
};
struct Container020dedd0;
struct Slots0208386c { unsigned char pad[0x454]; short slots[8]; };
struct S_a0504;

struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
int IsField8Bit19Set(unsigned int* obj);
void RemoveSlotShiftDown0208386c(struct Slots0208386c* s, int idx);
int LoadBattleBlock020ac4c0(void* dst);
void AddClamped7BitField(struct S_a0504* p, unsigned int amount);
int CopyInBattleField0x7540(void* src);

// USA: func_020ddcbc  (semantic: ApplySlotElementEffectIfFlagged020ddcbc)
extern "C" ARM int func_020ddcbc(int n, int idx, struct Container020dedd0* container) {
    GameObject* combatant;
    short* slotsArr;
    struct Element020de650* elem;
    int inRange;
    char localBuf[0xb0];

    inRange = (n >= 0 && n <= 3);
    if (!inRange) return 0;
    if (container == 0) return 0;
    if (idx < 0 || idx >= 8) return 0;

    combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), n);
    if (combatant == 0) return 0;

    slotsArr = (short*)((char*)(*(struct Slots0208386c**)((char*)combatant + kSlotsPointerOffset)) + 0x454);
    if (slotsArr == 0) return 0;

    elem = FindElementByKey020dedd0(container, slotsArr[idx]);
    if (elem == 0) return 0;
    if (!IsField8Bit19Set(elem->v)) return 0;

    switch (((struct ElementFlagsWord020de650*)&elem->v[2])->kind) {
        case 8:
        case 9:
        case 0xa:
            RemoveSlotShiftDown0208386c(*(struct Slots0208386c**)((char*)combatant + kSlotsPointerOffset), (signed char)idx);
            break;
    }

    if (((struct ElementFlagsWord020de650*)&elem->v[2])->topFlag) {
        LoadBattleBlock020ac4c0(localBuf);
        AddClamped7BitField((struct S_a0504*)localBuf, 1);
        CopyInBattleField0x7540(localBuf);
    }
    return 1;
}
